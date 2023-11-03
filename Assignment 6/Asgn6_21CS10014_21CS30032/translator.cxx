#include <iostream>
#include <string>
using namespace std;

#include "translator.h"
#include <iomanip>

symbol *current_symbol;
symbol_table *current_symbol_table;
symbol_table *global_symbol_table;
quad_array quad_table;
int symbol_table_counter;
string current_block_name;

// string last_var_type;
string typevar;

// symbol::symbol(string name, string t, symbol_type* st, int width):
//     name(name), type(st), value("x"), offset(0), nested_table(NULL) {
//     type = new symbol_type(t, st, width);
//     size = getsize(type);
// }

// symbol_type::symbol_type(string type,symbol_type* ptr,int width):
//     type(type), width(width), ptr(ptr) {}

// symbol* symbol::update(symbol_type* t) {
//     type = t;
//     size = getsize(t);
//     return this;
// }

// symbol_table::symbol_table(string name):
//     name(name), count(0), parent(parent) {}

// symbol* symbol_table::lookup(string name) {
//     for (list<symbol>::iterator it = symbols.begin(); it != symbols.end(); it++) {
//         if ((it)->name == name) {
//             return &(*it);
//         }
//     }

//     symbol *s = NULL;
//     if (this->parent != NULL) {
//         s = this->parent->lookup(name);
//     }
//     if (current_symbol_table == this && s == NULL) {
//         s = new symbol(name, "int");
//         symbols.push_back(*s);
//         return &(symbols.back());
//     }
//     return s;
// }

// symbol* symbol_table::gentemp(symbol_type* type, string value) {
//     string name = "t" + int2string(current_symbol_table->count++);
//     symbol* s = new symbol(name, type->type);
//     s->type = type;
//     s->value = value;
//     s->size = getsize(type);

//     current_symbol_table->symbols.push_back(*s);
//     return &(current_symbol_table->symbols.back());
// }

// void symbol_table::print_st() {
//     cout << "========================================================================================================================" << endl;
//     cout << "Symbol Table: " << name << endl;
//     cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
//     // cout << "Name\tValue\tType\tSize\tOffset\tNested Table" << endl;
//     // using setw() to allocate size for better tabular representation
//     cout << setw(20) << "Name" << setw(20) << "Value" << setw(20) << "Type" << setw(20) << "Size" << setw(20) << "Offset" << setw(20) << "Nested Table" << endl;
//     cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
//     vector <symbol_table*> tables;

//     for(list<symbol>::iterator it = symbols.begin(); it != symbols.end(); it++) {
//         // cout << it->name << "\t\t\t" << it->value << "\t\t\t" << gettype(it->type) << "\t\t\t" << it->size << "\t\t\t" << it->offset << "\t\t";
//         cout << setw(20) << it->name << setw(20) << it->value << setw(20) << gettype(it->type) << setw(20) << it->size << setw(20) << it->offset << setw(20);
//         if (it->nested_table != NULL) {
//             cout << it->nested_table->name;
//             tables.push_back(it->nested_table);
//         }
//         cout << endl;
//     }
//     cout << "========================================================================================================================" << endl;

//     for(int i = 0; i < tables.size(); i++) {
//         tables[i]->print_st();
//     }
// }

// void symbol_table::update() {
//     vector<symbol_table*> tables;
//     int offset_new = 0;

//     for(list<symbol>::iterator it = symbols.begin(); it != symbols.end(); it++) {
//         if (it == symbols.begin()) {
//             it->offset = 0;
//             offset_new = it->size;
//         }
//         else {
//             it->offset = offset_new;
//             offset_new = it->offset + it->size;
//         }

//         if (it->nested_table != NULL) {
//             tables.push_back(it->nested_table);
//         }
//     }
// }


// quad::quad(string result , string arg1 , string op, string arg2) : result(result) , arg1(arg1) , op(op) , arg2(arg2) {}

// quad::quad(string result, int arg1, string op, string arg2 ) : result(result) , arg2(arg2) , op(op) {
//     this->arg1 = int2string(arg1);
// }
// quad::quad(string result, float arg1, string op , string arg2) : result(result) , arg2(arg2) , op(op) {
//     this->arg1 = float2string(arg1);
// }


// void quad :: print_quad()
// {
//     if (op == "=") cout << result << "=" << arg1;
//     else if (op == "*=") cout << "*" << result << "=" << arg1;
//     else if (op == "[]=") cout << result << "[" << arg1 << "]" << " = " << arg2;
//     else if (op == "=[]") cout << result << " = " << arg1 << "[" << arg2 << "]";
//     else if (op == "goto" || op == "param" || op == "return") cout << op << " " << result;
//     else if (op == "call") cout << result << " = " << "call " << arg1 << ", " << arg2;
//     else if (op == "label") cout << result << ": ";


//     else if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%" || op == "^" || op == "|" || op == "&" || op == "<<" || op == ">>") cout << result << " = " << arg1 << " " << op << " " << arg2;
//     else if(op == "==" || op == "!=" || op == "<" || op == ">" || op == "<=" || op == ">=") cout << "if " << arg1 << " " << op << " " << arg2 << " goto " << result;
//     else if(op == "= &" || op == "= *" || op == "= -" || op == "= ~" || op == "= !") cout << result << " " << op << arg1;

//     else cout << "Invalid Operator";
// }

void quad_array :: print_quad_array()
{
        cout << "====================================================================================================" << endl;
        cout << "List of Quads" << endl;
        cout << "----------------------------------------------------------------------------------------------------" << endl;

        for(int i = 0; i < arr.size(); i++)
        {
            cout << i << ":\t";
            arr[i].print_quad();
            cout << endl;
        }
        cout << "====================================================================================================" << endl;
}


void emit(string result, string arg1, opcode op, string arg2) {
    quad_table.arr.push_back(quad(result, arg1, op, arg2));
}

list<int> makelist(int i)
{
    list<int> lst(1,i);
    return lst;
}

list<int> merge(list<int> &l1, list<int> &l2)
{
    l1.merge(l2);
    return l1;
}


void backpatch(list<int> lst, int i)
{
    string s = to_string(i);
    for(list<int>::iterator it = lst.begin(); it != lst.end(); it++) quad_table.arr[*it].result = s;
}

void converttype (expression* arg, expression* res, data_type type)
{
    if (res->type == type) return;

    if (res->type == INT)
    {
        if (type == FLOAT) emit(res->loc, arg->loc, "", INTtoFLOAT);
        else if (type == CHAR) emit(res->loc, arg->loc, "", INTtoCHAR);
    }
    else if (res->type == FLOAT)
    {
        if (type == INT) emit(res->loc, arg->loc, "", FLOATtoINT);
        else if (type == CHAR) emit(res->loc, arg->loc, "", FLOATtoCHAR);
    }
    else if (res->type == CHAR)
    {
        if (type == INT) emit(res->loc, arg->loc, "", INTtoCHAR);
        else if (type == FLOAT) emit(res->loc, arg->loc, "", FLOATtoCHAR);
    }
}

void converttype(string o, data_type otype, string n, data_type ntype)
{
    if (otype == ntype) return;

    if (otype == INT)
    {
        if (ntype == FLOAT) emit(n, o, "", FLOATtoINT);
        else if (ntype == CHAR) emit(n, o, "", CHARtoINT);
    }
    else if (otype == FLOAT)
    {
        if (ntype == INT) emit(n, o, "", INTtoFLOAT);
        else if (ntype == CHAR) emit(n, o, "", CHARtoFLOAT);
    }
    else if (otype == CHAR)
    {
        if (ntype == INT) emit(n, o, "", INTtoCHAR);
        else if (ntype == FLOAT) emit(n, o, "", FLOATtoCHAR);
    }
}



void inttobool(expression* e)
{
    if(e->type != BOOL)
    {
        e->type = BOOL;
        e->falselist = makelist(next_instr);
        emit("", e->loc , "", IF_FALSE_GOTO);
        e->truelist = makelist(next_instr);
        emit("", "" , "", GOTO);
    }
}

int getsize(data_type t)
{
    if (t==VOID) return SIZE_OF_VOID;
    else if (t==CHAR) return SIZE_OF_CHAR;
    else if (t==INT) return SIZE_OF_INT;
    else if (t==FLOAT) return SIZE_OF_FLOAT;
    else if (t==PTR) return SIZE_OF_PTR;
    else if (t==FUNC) return SIZE_OF_FUNC;
    return 0;
}


string gettype(symbol_type x)
{
    if (x.type==VOID) return "void";
    else if (x.type==CHAR) return "char";
    else if (x.type==INT) return "int";
    else if (x.type==FLOAT) return "float";
    else if (x.type==FUNC) return "function";

    else if (x.type==PTR) 
    {
        string s = "";
        if (x.nextType==VOID) s += "void";
        else if (x.nextType==CHAR) s += "char";
        else if (x.nextType==INT) s += "int";
        else if (x.nextType==FLOAT) s += "float";
        s += string("*");
        return s;
    }

    else if (x.type==ARR) 
    {
        string s = "";
        if (x.nextType==VOID) s += "void";
        else if (x.nextType==CHAR) s += "char";
        else if (x.nextType==INT) s += "int";
        else if (x.nextType==FLOAT) s += "float";

        vector<int> v = x.dimensions;
        for(int i = 0; i < v.size(); i++)
        {
            if (v[i]) s += "[" + to_string(v[i]) + "]";
            else s += "[]";
        }
        if (v.size()==0) s += "[]";
        return s;
    }
    return "undefined";
}

string getval(symbol* sym)
{
    if (sym->initial_value != NULL) {
        if (sym->type.type == INT) {
            return to_string(sym->initial_value->int_val);
        }
        else if (sym->type.type == FLOAT) {
            return to_string(sym->initial_value->float_val);
        }
        else if (sym->type.type == CHAR) {
            return to_string(sym->initial_value->char_val);
        }
        return "x";
    }
}