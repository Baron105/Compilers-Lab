#ifndef __TRANSLATOR_H
#define __TRANSLATOR_H

#include <string>
#include <vector>
#include <list>
using namespace std;

#define __SIZE_OF_VOID 0
#define __SIZE_OF_INT 4
#define __SIZE_OF_CHAR 1
#define __SIZE_OF_FLOAT 8
#define __SIZE_OF_FUNC 0
#define __SIZE_OF_PTR 4

class symbol;               // class to represent a symbol in the symbol table
class symbol_table;         // class to represent the symbol table
class symbol_type;          // class to represent the type of a symbol
class quad;                 // class to represent a quad entry for the quad array
class quad_array;           // class to represent the quad array

class expression;           // class to represent an expression
class statement;            // class to represent a statement
class Array;                // class to represent an array

extern symbol* current_symbol;
extern symbol_table* current_symbol_table;
extern symbol_table* global_symbol_table;
extern symbol_table* constant_symbol_table;
extern quad_array quad_table;
extern int symbol_table_counter;
extern string current_block_name;

extern char* yytext;
extern int yyparse();

class symbol_type {
public:
    string type;
    int width;
    symbol_type* ptr;
    symbol_type(string type,  symbol_type* ptr = NULL, int size = 1);
};

class symbol {
public:
    string name;
    symbol_type* type;
    string value;
    int size;
    int offset;
    symbol_table* nested_table;
    symbol(string name, string type, symbol_type* t = NULL, int width = 0);
    symbol* update(symbol_type* type);
};

class symbol_table {
public:
    string name;
    int count;
    symbol_table* parent;
    list<symbol> symbols;


    symbol_table(string name = "NULL");
    symbol* lookup(string name);
    static symbol* gentemp(symbol_type* type, string init = "");

    void print_st();
    void update();
};

class quad {
public:
    string op;
    string arg1;
    string arg2;
    string result;

    quad(string result, string arg1, string op = "=", string arg2 = "");
    quad(string result, int arg1, string op = "=", string arg2 = "");
    quad(string result, float arg1, string op = "=", string arg2 = "");

    void print_quad();
};

class quad_array {
public:
    vector<quad> arr;

    void print_quad_array();
};






// class for array
class Array
{
    public:
        string arrtype; // type of array either 'arr' or 'ptr'
        symbol* loc ;      // location where array is stored
        symbol* arr ;      // pointer to symbol table entry of array
        symbol_type* type; // type of array

};


// class for statement
class statement
{
    public:
        list<int> nextlist; // nextlist for statement
};


// class for expression
class expression
{
    public:
        string type;         // type of expression
        symbol* loc;         // ptr to symbol table entry
        list<int> truelist;  // truelist for expression
        list<int> falselist; // falselist for expression
        list<int> nextlist; // nextlist for expression
};


// definition for function emit 
// the function emits the quad for the given parameters
// adds quads of 3 forms 
// 1. binary operation
// 2. unary operation
// 3. copy assignment 

// it is overloaded for different types of arguments

void emit(string op, string result, string arg1 = "", string arg2 = "");
void emit(string op, string result, int arg1, string arg2 = "");
void emit(string op, string result, float arg1, string arg2 = "");


// function to create a list consisting of a single entry index , which is an index to the quad array
// returns a ptr to the list
list<int> makelist(int );


// function to merge two lists
// returns a ptr to the merged list
list<int> merge(list<int> &, list<int> &);

// function definition for backpatch
// it takes a list of indices of the quads and a target label
// it inserts the label at the target of all the quads in the list
void backpatch(list<int> , int );

// functions to carry out typecheck 
// it takes two symbols and checks if they are of same type
bool typecheck(symbol* & , symbol* & );
bool typecheck(symbol_type* , symbol_type* );

// function the convert types
// it takes a symbol and converts it to the type given by the string
symbol* convertType(symbol* , string );

// function to convert int to string 
string int2string(int );

// function to convert float to string
string float2string(float );


expression* convertInt2Bool(expression* );

expression* convertBool2Int(expression* );


// function to switch tables
// it takes a symbol table and switches the current table to the given table
void switchTable(symbol_table* );

int nextinstr();    // returns the next instruction count

// function to get the type of a symbol
string gettype(symbol_type* );

// function to get the size of a type
int getsize(symbol_type* );

#endif