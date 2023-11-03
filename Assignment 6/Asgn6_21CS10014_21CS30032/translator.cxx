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

void symbol_value::set_value(int val) {
    int_val = val;
}

void symbol_value::set_value(float val) {
    float_val = val;
}

void symbol_value::set_value(char val) {
    char_val = val;
}

symbol::symbol(): initial_value(NULL), size(0), offset(0), nested_table(NULL) {}

symbol_table::symbol_table() : offset(0) {}

symbol* symbol_table::lookup(string name, data_type type, int pc) {
    map<string, symbol*>::iterator it = table.find(name);
    if (it != table.end()) {
        return it->second;
    }
    else {
        symbol* sym = new symbol();
        sym->name = name;
        sym->type.type = type;
        sym->offset = offset;
        sym->initial_value = NULL;
        if (pc == 0) {
            sym->size = getsize(type);
            offset += sym->size;
        }
        else {
            sym->size = SIZE_OF_PTR;
            sym->type.ptr = pc;
            sym->type.nextType = type;
            sym->type.type = ARR;
        }
        symbol_list.push_back(sym);
        table[name] = sym;
        return sym;
    }
}

string symbol_table::gentemp(data_type type) {
    string name = "t" + to_string(count++);
    symbol* sym = new symbol();
    sym->name = name;
    sym->type.type = type;
    sym->offset = offset;
    sym->initial_value = NULL;
    sym->size = getsize(type);

    offset += sym->size;
    symbol_list.push_back(sym);
    table[name] = sym;
    return name;
}

void symbol_table::print_st(string name) {
    cout << "Symbol Table: " << name << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << "Name" << setw(20) << "Type" << setw(20) << "Initial Value" << setw(20) << "Size" << setw(20) << "Offset" << setw(20) << "Nested Table" << endl;

    vector<pair<string, symbol_table*>> v;

    for (int i = 0; i < symbol_list.size(); i++) {
        cout << setw(20) << symbol_list[i]->name << setw(20) << gettype(symbol_list[i]->type) << setw(20) << getval(symbol_list[i]) << setw(20) << symbol_list[i]->size << setw(20) << symbol_list[i]->offset << setw(20) << symbol_list[i]->nested_table << endl;

        if (symbol_list[i]->nested_table != NULL) {
            string s = name + "_" + symbol_list[i]->name;
            cout << s << endl;
            v.push_back(make_pair(s, symbol_list[i]->nested_table));
        }
    }
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < v.size(); i++) {
        v[i].second->print_st(v[i].first);
    }
}

symbol* symbol_table::search_global_table(string name) {
    map<string, symbol*>::iterator it = table.find(name);
    if (it != table.end()) {
        return it->second;
    }
    else {
        return NULL;
    }
}

string quad::print_quad()
{
    string s = "";
    if (op == ADD) s += result + " = " + arg1 + " + " + arg2;
    else if (op == SUB) s += result + " = " + arg1 + " - " + arg2;
    else if (op == MULT) s += result + " = " + arg1 + " * " + arg2;
    else if (op == DIV) s += result + " = " + arg1 + " / " + arg2;
    else if (op == MOD) s += result + " = " + arg1 + " % " + arg2;
    else if (op == BITWISE_XOR) s += result + " = " + arg1 + " ^ " + arg2;
    else if (op == BITWISE_OR) s += result + " = " + arg1 + " | " + arg2;
    else if (op == BITWISE_AND) s += result + " = " + arg1 + " & " + arg2;
    else if (op == SL) s += result + " = " + arg1 + " << " + arg2;
    else if (op == SR) s += result + " = " + arg1 + " >> " + arg2;
    else if (op == ASSIGN) s += result + " = " + arg1;
    else if (op == BITWISE_UNARY_NOT) s += result + " = ~" + arg1;
    else if (op == UNARY_NEG) s += result + " = !" + arg1;
    else if (op == UNARY_MINUS) s += result + " = -" + arg1;
    else if (op == UNARY_PLUS) s += result + " = +" + arg1;
    else if (op == GOTO) s += "goto " + result;
    else if (op == GOTO_LT) s += "if " + arg1 + " < " + arg2 + " goto " + result;
    else if (op == GOTO_GT) s += "if " + arg1 + " > " + arg2 + " goto " + result;
    else if (op == GOTO_LTE) s += "if " + arg1 + " <= " + arg2 + " goto " + result;
    else if (op == GOTO_GTE) s += "if " + arg1 + " >= " + arg2 + " goto " + result;
    else if (op == GOTO_EQ) s += "if " + arg1 + " == " + arg2 + " goto " + result;
    else if (op == GOTO_NEQ) s += "if " + arg1 + " != " + arg2 + " goto " + result;
    else if (op == IF_GOTO) s += "if " + arg1 + "!= 0 goto " + result + " ";
    else if (op == IF_FALSE_GOTO) s += "if " + arg1 + "== 0 goto " + result + " ";
    else if (op == PARAM) s += "param " + result;
    else if (op == CALL) 
    {
        if (arg2.size() > 0) s += arg2 + " = ";
        s += "call " + arg1 + ", " + result; 
    }
    else if (op == RETURN) s += "return " + result;
    else if (op == ARR_IDX_ARG) s += result + " = " + arg1 + "[" + arg2 + "]";
    else if (op == ARR_IDX_RES) s += result + "[" + arg2 + "]" + " = " + arg2;
    else if (op == FUNC_BEG) s += result + ":";
    else if (op == FUNC_END) s += "function " + result + " ends";
    else if (op == L_DEREF) s += result + " = *" + arg1;
    else if (op == CHARtoINT) s += result + " = (int)" + arg1;
    else if (op == INTtoCHAR) s += result + " = (char)" + arg1;
    else if (op == FLOATtoINT) s += result + " = (int)" + arg1;
    else if (op == INTtoFLOAT) s += result + " = (float)" + arg1;
    else if (op == FLOATtoCHAR) s += result + " = (char)" + arg1;
    else if (op == CHARtoFLOAT) s += result + " = (float)" + arg1;
    else if (op == REFERENCE) s += result + " = &" + arg1;
    else if (op == DEREFERENCE) s+= result + " = *" + arg1;

    return s;
}

void quad_array::print_quad_array() {
    cout << "Three Address Codes:" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].op == FUNC_BEG)
        {
            cout << endl;
            cout << setw(20) << i << setw(20) << arr[i].print_quad() << endl;
        }
        else if (arr[i].op == FUNC_END)
        {
            cout << arr[i].print_quad() << endl;
            cout << endl;
        }
        else
        {
            cout << setw(20) << i << setw(20) << arr[i].print_quad() << endl;
        }

    }
}

quad::quad(string result, string arg1, opcode op, string arg2) : result(result), arg1(arg1), op(op), arg2(arg2) {}

expression::expression() : fold(0), folder(NULL) {}

void emit(string result, string arg1, opcode op, string arg2) {
    quad_table.arr.push_back(quad(result, arg1, op, arg2));
    next_instr++;
}

void emit(string result, int constant, opcode op) {
    quad_table.arr.push_back(quad(result, to_string(constant), op, ""));
    next_instr++;
}

void emit(string result, float constant, opcode op) {
    quad_table.arr.push_back(quad(result, to_string(constant), op, ""));
    next_instr++;
}

void emit(string result, char constant, opcode op) {
    quad_table.arr.push_back(quad(result, to_string(constant), op, ""));
    next_instr++;
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
    }
    return "x";
}