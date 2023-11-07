#ifndef __TRANSLATOR_H
#define __TRANSLATOR_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <map>
using namespace std;

#define SIZE_OF_VOID 0
#define SIZE_OF_INT 4
#define SIZE_OF_CHAR 1
#define SIZE_OF_FLOAT 8
#define SIZE_OF_FUNC 0
#define SIZE_OF_PTR 8

typedef enum {
    VOID,
    INT,
    CHAR,
    FLOAT,
    FUNC,
    PTR,
    BOOL,
    ARR
} data_type;

/*
    An enum for all opcodes
*/
typedef enum  {
    ADD, SUB, MULT, DIV, MOD, SL, SR, 
    BITWISE_AND, BITWISE_OR, BITWISE_XOR, 
    BITWISE_UNARY_NOT ,UNARY_PLUS, UNARY_MINUS, REFERENCE, DEREFERENCE, UNARY_NEG, 
    GOTO_EQ, GOTO_NEQ, GOTO_GT, GOTO_GTE, GOTO_LT, GOTO_LTE, IF_GOTO, IF_FALSE_GOTO, 
    CHARtoINT, INTtoCHAR, FLOATtoINT, INTtoFLOAT, FLOATtoCHAR ,CHARtoFLOAT, 
    ASSIGN, GOTO, RETURN, PARAM, CALL, ARR_IDX_ARG, ARR_IDX_RES, FUNC_BEG, FUNC_END, L_DEREF
} opcode;

class symbol;               // class to represent a symbol in the symbol table
class symbol_table;         // class to represent the symbol table
class symbol_type;          // class to represent the type of a symbol
class symbol_value;         // class to represent the value of an element in the symbol table
class quad;                 // class to represent a quad entry for the quad array
class quad_array;           // class to represent the quad array

class expression;           // class to represent an expression

extern symbol* current_symbol;
extern symbol_table* current_symbol_table;
extern symbol_table global_symbol_table;
extern symbol_table* constant_symbol_table;
extern quad_array quad_table;
extern int symbol_table_counter;
extern string current_block_name;
extern int next_instr;

extern char* yytext;
extern int yyparse();

class symbol_type {
public:
    int ptr;
    data_type type;
    data_type nextType;
    vector <int> dimensions;
};

class symbol {
public:
    string name;
    symbol_type type;
    symbol_value* initial_value;
    int size;
    int offset;
    symbol_table* nested_table;
    symbol();
};

class symbol_value {
public :
    int int_val;
    float float_val;
    char char_val;
    void *ptr_val;


    void set_value(int val);
    void set_value(float val);
    void set_value(char val);
};

class symbol_table {
public:
    map<string, symbol*> table;
    vector<symbol*> symbol_list;
    int offset;
    static int count;


    symbol_table();
    symbol* lookup(string name ,data_type type = INT,int pc = 0);
    symbol* search_global_table(string name);
    string gentemp(data_type t = INT);

    void print_st(string );
};

class quad {
public:
    opcode op;
    string arg1;
    string arg2;
    string result;

    quad(string result, string arg1, opcode op, string arg2);

    string print_quad();
};

class quad_array {
public:
    vector<quad> arr;

    void print_quad_array();
};


// class for parameters
class param{
public :
    string name ;
    symbol_type type ;
};

// class for expression
class expression
{
    public:
        int instruction ; // instruction number
        data_type type ; // type of expression
        string loc ; // location where result is stored
        list<int> truelist;  // truelist for expression
        list<int> falselist; // falselist for expression
        list<int> nextlist; // nextlist for expression
        int fold;
        string* folder;

        expression();
};

// class to represent declaration 
class declaration{
public :
    string name ;                       // name of the declaration
    int ptrs ;                          // number of pointers
    data_type type ;                    // type of the declaration
    data_type next_type ;               
    vector <int> instr_list ;           // list of instructions
    expression* initial_value ;         // initial value of the declaration
    int pc;
};


// definition for function emit 
// the function emits the quad for the given parameters
// adds quads of 3 forms 
// 1. binary operation
// 2. unary operation
// 3. copy assignment 

// it is overloaded for different types of arguments

void emit(string result, string arg1, string arg2, opcode op);
void emit(string result, int constant, opcode op);
void emit(string result, float constant, opcode op);
void emit(string result, char constant, opcode op);

// function to create a list consisting of a single entry index , which is an index to the quad array
// returns a ptr to the list
list<int> makelist(int );


// function to merge two lists
// returns a ptr to the merged list
list<int> merge(list<int>, list<int>);

// function definition for backpatch
// it takes a list of indices of the quads and a target label
// it inserts the label at the target of all the quads in the list
void backpatch(list<int> , int );



// function the convert types
// it takes a symbol and converts it to the type given by the string
void converttype(expression* arg, expression* res, data_type type);
void converttype(string o, data_type otype, string n, data_type ntype);



void inttobool(expression* e);

// function to get the type of a symbol
string gettype(symbol_type );

// function to get the size of a type
int getsize(data_type );

// function to get the initial value of a symbol
string getval(symbol* sym);

#endif