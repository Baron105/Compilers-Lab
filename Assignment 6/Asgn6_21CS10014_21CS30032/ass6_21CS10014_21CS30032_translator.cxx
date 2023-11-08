/*
    Made by Barun Parua and Navaneeth Shaji
    Roll Numbers: 21CS10014 and 21CS30032
    Assignment 6
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "ass6_21CS10014_21CS30032_translator.h"

// declare and initialize static/global variables
symbol_table *current_symbol_table;             // pointer to current symbol table
symbol_table global_symbol_table;               // global symbol table
quad_array quad_list;
int next_instr = 0;
int symbol_table::count = 0;

// set initial values for symbol_value
void symbol_value::set_value(int val) {
    int_val = char_val = float_val = val;
    ptr_val = NULL;
}

void symbol_value::set_value(float val) {
    float_val = int_val = char_val = val;
    ptr_val = NULL;
}

void symbol_value::set_value(char val) {
    char_val = int_val = float_val = val;
    ptr_val = NULL;
}

// constructors for symbol_table and symbol
symbol::symbol(): nested_table(NULL) {}

symbol_table::symbol_table() : offset(0) {}

// lookup for a symbol in the symbol table
symbol* symbol_table::lookup(string name, data_type type, int pc) {
    map<string, symbol*>::iterator it = table.find(name);
    if (it == table.end()) {
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
    return table[name];
}

// generate a temporary variable using gentemp
string symbol_table::gentemp(data_type type) {
    string name = "t" + to_string(symbol_table::count++);
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

// print the symbol table
// well formatted
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
        else cout << "NULL" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    for (auto it = v.begin(); it != v.end(); it++) {
        it->second->print_st(it->first);
    }
}

// search for a symbol in the global symbol table
symbol* symbol_table::search_global_table(string name) {
    return (table.find(name) == table.end()) ? NULL : table[name];
}

// print the quads
// well formatted
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

// prints the quad array
// well formatted
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

// constructor for quad and expression
quad::quad(string result, string arg1, string arg2, opcode op) : result(result), arg1(arg1), arg2(arg2), op(op) {}

expression::expression() : fold(0), folder(NULL) {}

// four emit functions to emit quads for different types of operations
void emit(string result, string arg1, string arg2, opcode op) {
    quad_list.arr.push_back(quad(result, arg1, arg2, op));
    next_instr++;
}

void emit(string result, int constant, opcode op) {
    quad_list.arr.push_back(quad(result, to_string(constant), "", op));
    next_instr++;
}

void emit(string result, float constant, opcode op) {
    quad_list.arr.push_back(quad(result, to_string(constant), "", op));
    next_instr++;
}

void emit(string result, char constant, opcode op) {
    quad_list.arr.push_back(quad(result, to_string(constant), "", op));
    next_instr++;
}

// implementation of makelist that makes a list of integers
list<int> makelist(int i)
{
    list<int> lst(1,i);
    return lst;
}

// implementation of merge that merges two lists
list<int> merge(list<int> l1, list<int> l2)
{
    l1.merge(l2);
    return l1;
}

// implementation of backpatch that backpatches a list of quads with a given instruction number
void backpatch(list<int> lst, int i)
{
    string s = to_string(i);
    for(list<int>::iterator it = lst.begin(); it != lst.end(); it++) quad_list.arr[*it].result = s;
}

// implementation of converttype that converts an expression to a given type
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
        if (type == INT) emit(res->loc, arg->loc, "", CHARtoINT);
        else if (type == FLOAT) emit(res->loc, arg->loc, "", CHARtoFLOAT);
    }
}

// implementation of converttype with overloading
void converttype(string o, data_type otype, string n, data_type ntype)
{
    if (otype == ntype) return;

    if (otype == INT)
    {
        if (ntype == FLOAT) emit(n, o, "", INTtoFLOAT);
        else if (ntype == CHAR) emit(n, o, "", INTtoCHAR);
    }
    else if (otype == FLOAT)
    {
        if (ntype == INT) emit(n, o, "", FLOATtoINT);
        else if (ntype == CHAR) emit(n, o, "", FLOATtoCHAR);
    }
    else if (otype == CHAR)
    {
        if (ntype == INT) emit(n, o, "", CHARtoINT);
        else if (ntype == FLOAT) emit(n, o, "", CHARtoFLOAT);
    }
}

// implementation of inttobool
// used to convert an integer expression to a boolean expression for if and while statements
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

// implementation of getsize that returns the size of a data_type
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

// implementation of gettype
// basically returns the string representation of a data_type
string gettype(symbol_type x)
{
    if (x.type==VOID) return "void";
    else if (x.type==CHAR) return "char";
    else if (x.type==INT) return "int";
    else if (x.type==FLOAT) return "float";
    else if (x.type==FUNC) return "function";

    // for pointers types
    else if (x.type==PTR) 
    {
        string s = "";
        if (x.nextType==VOID) s += "void";
        else if (x.nextType==CHAR) s += "char";
        else if (x.nextType==INT) s += "int";
        else if (x.nextType==FLOAT) s += "float";
        s += string(x.ptr, '*');
        return s;
    }

    // for array types
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
    return "unknown";
}

// get the initial value of a symbol
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
    return "-";
}