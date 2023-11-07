#include "ass6_21CS10014_21CS30032_translator.h"
#include <fstream>
#include <sstream>
#include <stack>
#define endl '\n'

using namespace std;

// External variables 
extern symbol_table global_symbol_table;
extern symbol_table* constant_symbol_table;
extern quad_array quad_list;

// Global variables
vector<string> consts;
map<int,string> labels ;
stack<pair<string,int>> parameters ;
int label_count = 0;
string function_running = "";
string dot_s_file_name = "";

void print_global(ofstream& sfile)
{
    for (auto it = global_symbol_table.symbol_list.begin(); it != global_symbol_table.symbol_list.end(); it++)
    {
        symbol* s = *it;
        
        // if int AND not a temporary variable
        if (s->type.type == INT && s->name[0] != 't')
        {
            if (s->initial_value)
            {
                sfile << "\t.globl\t" << s->name << endl;
                sfile << "\t.data" << endl;
                sfile << "\t.align\t4" << endl;
                sfile << "\t.type\t" << s->name << ", @object" << endl;
                sfile << "\t.size\t" << s->name << ", 4" << endl;
                sfile << s->name << ":" << endl;
                sfile << "\t.long\t" << s->initial_value->int_val << endl;
            }
            else sfile << "\t.comm\t" << s->name << ",4,4" << endl;
        }

        // if char AND not a temporary variable
        else if (s->type.type == CHAR && s->name[0] != 't')
        {
            if (s->initial_value)
            {
                sfile << "\t.globl\t" << s->name << endl;
                sfile << "\t.data" << endl;
                sfile << "\t.align\t4" << endl;
                sfile << "\t.type\t" << s->name << ", @object" << endl;
                sfile << "\t.size\t" << s->name << ", 1" << endl;
                sfile << s->name << ":" << endl;
                sfile << "\t.byte\t" << s->initial_value->char_val << endl;
            }
            else sfile << "\t.comm\t" << s->name << ",1,1" << endl;
        }
    }
}

void print_strings(ofstream& sfile)
{
    sfile << ".section\t.rodata" << endl;
    for (auto it = consts.begin(); it != consts.end(); it++)
    {
        sfile << ".LC" << it - consts.begin() << ":" << endl;
        sfile << "\t.string\t" << *it << endl;
    }
}

void set_goto_labels()
{
    int i = 0;
    for (auto it = quad_list.arr.begin(); it != quad_list.arr.end(); it++)
    {
        if (it->op == GOTO || it->op == GOTO_LT || it->op == GOTO_GT || it->op == GOTO_GTE || it->op == GOTO_LTE || it->op == GOTO_EQ || it->op == GOTO_NEQ || it->op == IF_GOTO || it->op == IF_FALSE_GOTO)
        {
            int target = atoi(it->result.c_str());
            if(labels.find(target) == labels.end())
            {
                labels[target] = ".L" + to_string(i);
            }
            it->result = labels[target];
        }
    }
}

// generated function prologue
void gen_prologue(int local_var_size, ofstream& sfile)
{
    int size = 16;
    sfile << endl << "\t.text" << endl;
    sfile << "\t.globl\t" << function_running << endl;
    sfile << "\t.type\t" << function_running << ", @function" << endl;
    sfile << function_running << ":" << endl;
    sfile << "\tpushq\t%rbp" << endl;
    sfile << "\tmovq\t%rsp, %rbp" << endl;
    sfile << "\tsubq\t$" << local_var_size + size << ", %rsp" << endl;
}

// function that generates the assembly code for the given quad
void gen_ass_from_quad(quad q , ofstream& sfile)
{
    string label  = q.result;
    bool is_label = (q.result[0] == '.' && q.result[1] == 'L' && q.result[2] == 'C');
    string print1 = "" , print2 = "", print_res = "";
    int offset1 = 0,offset2 = 0 , offset_res = 0;

    symbol* loc1 = current_symbol_table->lookup(q.arg1);
    symbol* loc2 = current_symbol_table->lookup(q.arg2);
    symbol* loc3 = current_symbol_table->lookup(q.result);
    symbol* global1 = global_symbol_table.search_global_table(q.arg1);
    symbol* global2 = global_symbol_table.search_global_table(q.arg2);
    symbol* global3 = global_symbol_table.search_global_table(q.result);


    if(current_symbol_table != &global_symbol_table)
    {
        if(global1 == NULL) offset1 = loc1->offset;
        if(global2 == NULL) offset2 = loc2->offset;
        if(global3 == NULL) offset_res = loc3->offset ;

        if(q.arg1[0]<'0' || q.arg1[0]>'9')
        {
            if(global1 !=NULL) print1 = q.arg1 + "(%rip)";
            else print1 = to_string(offset1) + "(%rbp)";
        }
        if(q.arg2[0]<'0' || q.arg2[0]>'9')
        {
            if(global2 !=NULL) print2 = q.arg2 + "(%rip)";
            else print2 = to_string(offset2) + "(%rbp)";
        }
        if(q.result[0]<'0' || q.result[0]>'9')
        {
            if(global3 !=NULL) print_res = q.result + "(%rip)";
            else print_res = to_string(offset_res) + "(%rbp)";
        }

    }
    else 
    {
        print1 = q.arg1;
        print2 = q.arg2;
        print_res = q.result;
    }

    if(is_label) print_res = label;

    if(q.op == ASSIGN)
    {
        if(q.result[0] != 't' || loc3->type.type == INT || loc3->type.type == PTR)
        {
            if(loc3->type.type != PTR)
            {
                if(q.arg1[0] < '0' || q.arg1[0] > '9')
                {
                    sfile << "\tmovl\t" << print1 << ", %eax" << endl;
                    sfile << "\tmovl\t%eax, " << print_res << endl;
                }
                else sfile << "\tmovl\t$" << q.arg1 << ", " << print_res << endl;
            }
            else 
            {
                sfile << "\tmovq\t" << print1 << ", %rax" << endl;
                sfile << "\tmovq\t%rax, " << print_res << endl;
            }
        }
        else 
        {
            int x = q.arg1[0] ;
            sfile << "\tmovb\t$" << x << ", " << print_res << endl;
        }
    }
    else if(q.op == UNARY_MINUS)
    {
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "\tnegl\t%eax" << endl;
        sfile << "\tmovl\t%eax, " << print_res << endl;
    }
    else if (q.op == ADD)
    {
        if(q.arg1[0]>'0' && q.arg1[0] <='9' ) sfile << "\tmovl\t$" << q.arg1 << ", %eax" << endl;
        else sfile << "\tmovl\t" << print1 << ", %eax" << endl;

        if(q.arg2[0]>'0' && q.arg2[0] <='9' ) sfile << "\tmovl\t$" << q.arg2 << ", %edx" << endl;
        else sfile << "\tmovl\t" << print2 << ", %edx" << endl;

        sfile << "\taddl\t%edx, %eax" << endl;
        sfile << "\tmovl\t%eax, " << print_res << endl;
    }
    else if(q.op == SUB)
    {
        if(q.arg1[0]>'0' && q.arg1[0] <= '9') sfile << "\tmovl\t$" << q.arg1 << ", %eax" << endl;
        else sfile << "\tmovl\t" << print1 << ", %eax" << endl;

        if(q.arg2[0]>'0' && q.arg2[0] <= '9') sfile << "\tmovl\t$" << q.arg2 << ", %edx" << endl;
        else sfile << "\tmovl\t" << print2 << ", %edx" << endl;

        sfile << "\tsubl\t%eax, %edx" << endl; 
        sfile << "\tmovl\tedx, %eax" << endl;
        sfile << "\tmovl\t%eax, " << print_res << endl;

    }
    else if(q.op == MULT)
    {
        if(q.arg1[0]>'0' && q.arg1[0] <= '9') sfile << "\tmovl\t$" << q.arg1 << ", %eax" << endl;
        else sfile << "\tmovl\t" << print1 << ", %eax" << endl;

        sfile << "\timull\t";

        if(q.arg2[0] > '0' && q.arg2[0] <= '9') sfile << "$" << q.arg2 << ", %eax" << endl;
        else sfile << print2 << ", %eax" << endl;

        sfile << "\tmovl\t%eax, " << print_res << endl;
    }
    else if(q.op == DIV)
    {
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "\tcltd\n\tidivl\t" << print2 << endl;
        sfile << "\tmovl\t%eax, " << print_res << endl;
    }
    else if (q.op == MOD)
    {
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "\tcltd\n\tidivl\t" << print2 << endl;
        sfile << "\tmovl\t%edx, " << print_res << endl;
    }
    else if(q.op == GOTO)
    {
        sfile << "\tjmp\t" << print_res << endl;
    }
    else if(q.op == GOTO_LT)
    {
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "\tcmpl\t" << print2 << ", %eax" << endl;
        sfile << "\tjge\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == GOTO_GT)
    {
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "\tcmpl\t" << print2 << ", %eax" << endl;
        sfile << "\tjle\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == GOTO_GTE)
    {
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "\tcmpl\t" << print2 << ", %eax" << endl;
        sfile << "\tjle\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == GOTO_LTE)
    {
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "\tcmpl\t" << print2 << ", %eax" << endl;
        sfile << "\tjg\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == GOTO_EQ)
    {
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        if(q.arg2[0] >= '0' && q.arg2[0] <= '9') sfile << "\tcmpl\t$" << q.arg2 << ", %eax" << endl;
        else sfile << "\tcmpl\t" << print2 << ", %eax" << endl;

        sfile << "\tjne\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == GOTO_NEQ)
    {
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "\tcmpl\t" << print2 << ", %eax" << endl;
        sfile << "\tje\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == IF_GOTO)
    {
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "\tcmpl\t$0, %eax" << endl;
        sfile << "\tje\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == IF_FALSE_GOTO)
    {
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "\tcmpl\t$0, %eax" << endl;
        sfile << "\tjne\t.L" << label_count << endl;
        sfile << "\tjmp\t" << q.result << endl;
        sfile << ".L" << label_count++ << ":" << endl;
    }
    else if(q.op == ARR_IDX_ARG)
    {
        sfile << "\tmovl\t" << print2 << ", %eax" << endl;
        sfile << "cltq" << endl;

        if(offset1 < 0)
        {
            sfile << "\tmovl\t" << offset1 << "(%rbp,%rdx,1), %eax" << endl;
            sfile << "\tmovl\t%eax, " << print_res << endl;
        }
        else 
        {
            sfile << "\tmovq\t" << offset1 << "(%rbp), %rdi" << endl;
            sfile << "\taddq\t%rdi, %rdx" << endl;
            sfile << "\tmovq\t(%rdx), %rax" << endl;
            sfile << "\tmovq\t%rax, " << print_res << endl;
        }
    }
    else if(q.op == ARR_IDX_RES)
    {
        sfile << "\tmovl\t" << print2 << ", %edx" << endl;
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "cltq" << endl;

        if(offset_res > 0)
        {
            sfile << "\tmovq\t" << offset_res << "(%rbp), %rdi" << endl;
            sfile << "\taddq\t%rdi, %rdx" << endl;
            sfile << "\tmovl\t%eax, (%rdx)" << endl;
        }
        else sfile << "\tmovl\t%eax, " << offset_res << "(%rbp,%rdx,1)" << endl;
    }
    else if(q.op == REFERENCE)
    {
        if(offset1 < 0)
        {
            sfile << "\tleaq\t" <<print1 << ", %rax" << endl;
            sfile << "\tmovq\t%rax, " << print_res << endl;
        }
        else 
        {
            sfile << "\tmovq\t" << print1 << ", %rax" << endl;
            sfile << "\tmovq\trax, " << print_res << endl; 
        }
    }
    else if(q.op == DEREFERENCE)
    {
        sfile << "\tmovq\t" << print1 << ", %rax" << endl;
        sfile << "\tmovq\t(%rax), %rdx" << endl;
        sfile << "\tmovq\t%rdx, " << print_res << endl;
    }
    else if(q.op == L_DEREF)
    {
        sfile << "\tmovq\t" << print_res << ", %rdx" << endl;
        sfile << "\tmovl\t" << print1 << ", %eax" << endl;
        sfile << "\tmovl\t%eax, (%rdx)" << endl;
    }
    else if(q.op == PARAM)
    {
        int param_size ;
        data_type t ;
        if(global3 != NULL) t = global3->type.type;
        else t = loc3->type.type;

        if(t == INT) param_size = SIZE_OF_INT;
        else if(t == CHAR) param_size = SIZE_OF_CHAR ;
        else param_size = SIZE_OF_PTR ;

        stringstream ss;

        if(q.result[0] == '.') ss << "\tmovq\t$" << print_res << ", %rax" << endl;
        else if(q.result[0] >= '0' && q.result[0] <= '9') ss << "\tmovq\t$" << q.result[0] << ", %rax" << endl;
        else
        {
            if(loc3->type.type != ARR)
            {
                if(loc3->type.type != PTR) 
                    ss << "\tmovq\t" << print_res << ", %rax" << endl;
                else if(loc3 == NULL)
                    ss << "\tleaq\t" << print_res << ", %rax" << endl;
                else 
                    ss << "\tmovq\t" << print_res << ", %rax" << endl;
            }
            else 
            {
                if(offset_res < 0) ss << "\tleaq\t" << print_res << ", %rax" << endl;
                else 
                {
                    ss << "\tmovq\t" << offset_res << "(%rbp), %rdi" << endl;
                    ss << "\tmovq\t%rdi, %rax" << endl;
                }
            }
        }
        parameters.push(make_pair(ss.str(),param_size));
    }
    else if(q.op == CALL)
    {
        int num_params = 0;
        num_params = atoi(q.arg1.c_str());
        int total_size = 0;
        int k = 0;

        // taking registers based on the parameters
        if( num_params > 6)
        {
            for(int i =0;i<num_params-6 ; i++)
            {
                string s = parameters.top().first;
                sfile << s << "\tpushq\t%rax" << endl;
                total_size += parameters.top().second;
                parameters.pop();
            }
            sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %r9d" << endl;
            total_size += parameters.top().second;
            parameters.pop();
            sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %r8d" << endl;
            total_size += parameters.top().second;
            parameters.pop();
            sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %rcx" << endl;
            total_size += parameters.top().second;
            parameters.pop();
            sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %rdx" << endl;
            total_size += parameters.top().second;
            parameters.pop();
            sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %rsi" << endl;
            total_size += parameters.top().second;
            parameters.pop();
            sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %rdi" << endl;
            total_size += parameters.top().second;
            parameters.pop();
        }
        else 
        {
            while(!parameters.empty())
            {
                if(parameters.size() == 6)
                {
                    sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %r9d" << endl;
                    total_size += parameters.top().second;
                    parameters.pop();
                }
                else if(parameters.size() == 5)
                {
                    sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %r8d" << endl;
                    total_size += parameters.top().second;
                    parameters.pop();
                }
                else if(parameters.size() == 4)
                {
                    sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %rcx" << endl;
                    total_size += parameters.top().second;
                    parameters.pop();
                }
                else if(parameters.size() == 3)
                {
                    sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %rdx" << endl;
                    total_size += parameters.top().second;
                    parameters.pop();
                }
                else if(parameters.size() == 2)
                {
                    sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %rsi" << endl;
                    total_size += parameters.top().second;
                    parameters.pop();
                }
                else if(parameters.size() == 1)
                {
                    sfile << parameters.top().first << "\tpushq\t%rax" << endl << "\tmovq\trax, %rdi" << endl;
                    total_size += parameters.top().second;
                    parameters.pop();
                }
            }
        }
        sfile << "\tcall\t" << q.result << endl;

        if(q.arg2 != "") sfile << "\tmovq\t%rax, " << print_res << endl;
        sfile << "\taddq\t$" << total_size << ", %rsp" << endl;
    }
    else if(q.op == RETURN)
    {
        if(q.result != "") sfile << "\tmovq\t" << print_res << ", %rax" << endl;
        sfile << "\tleave" << endl << "\tret" << endl;
    }
}

void gen_target_code(ofstream& sfile)
{
    print_global(sfile);
    print_strings(sfile);
    set_goto_labels();

    symbol_table* function_symbol_table = NULL;
    symbol* curr_func = NULL;

    for(int i = 0; i < quad_list.arr.size(); i++)
    {
        sfile << "# " << quad_list.arr[i].print_quad() << endl;
        if (labels.count(i) > 0)
        {
            sfile << labels[i] << ":" << endl;
        }

        if (quad_list.arr[i].op == FUNC_BEG)
        {
            i++;
            if (quad_list.arr[i].op == FUNC_END) i--;
            curr_func = global_symbol_table.search_global_table(quad_list.arr[i].result);
            function_symbol_table = curr_func->nested_table;

            int param = 1;
            int local_var_size = 16;
            current_symbol_table = function_symbol_table;

            for (int j = 0; j < current_symbol_table->symbol_list.size(); j++)
            {
                if (current_symbol_table->symbol_list[j]->name == "RETVAL")
                {
                    param = 0;
                    local_var_size = 0;

                    if (current_symbol_table->symbol_list.size()>j+1) local_var_size = current_symbol_table->symbol_list[j+1]->size;

                    else 
                    {
                        if (!param) 
                        {
                            current_symbol_table->symbol_list[j]->offset = local_var_size;
                            if (current_symbol_table->symbol_list.size()>j+1) local_var_size -= current_symbol_table->symbol_list[j+1]->size;
                        }

                        else 
                        {
                            current_symbol_table->symbol_list[j]->offset = local_var_size;
                            local_var_size += 8;
                        }
                        
                    }
                }
            }

            if (local_var_size >= 0) local_var_size = 0;
            else local_var_size = -local_var_size;

            function_running = quad_list.arr[i].result;
            gen_prologue(local_var_size, sfile);

        }

        else if (quad_list.arr[i].op == FUNC_END)
        {
            current_symbol_table = &global_symbol_table;
            function_running = "";
            sfile << "\tleave" << endl << "\tret" << endl;
            sfile << "\t.size\t" << quad_list.arr[i].result << ", .-" << quad_list.arr[i].result << endl;
            
        }

        if (function_running != "") gen_ass_from_quad(quad_list.arr[i], sfile);
    }
}

int main(int argc, char* argv[])
{
    current_symbol_table = &global_symbol_table;
    yyparse();

    dot_s_file_name = "ass6_21CS10014_21CS30032_" + string(argv[argc-1]) + ".s";
    ofstream sfile;

    sfile.open(dot_s_file_name);

    quad_list.print_quad_array();

    current_symbol_table->print_st("Global Symbol Table");

    gen_target_code(sfile);

    sfile.close();

    return 0;
}