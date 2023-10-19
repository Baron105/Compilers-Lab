#ifndef __TRANSLATOR_H
#define __TRANSLATOR_H

#include <string>
#include <vector>
using namespace std;

#define __SIZE_OF_VOID 0
#define __SIZE_OF_INT 4
#define __SIZE_OF_CHAR 1
#define __SIZE_OF_FLOAT 8
#define __SIZE_OF_FUNC 0
#define __SIZE_OF_PTR 4

class symbol;
class symbol_table;
class symbol_type;

class quad;
class quad_array;

extern symbol* current_symbol;
extern symbol_table* current_symbol_table;
extern symbol_table* global_symbol_table;
extern symbol_table* constant_symbol_table;
extern quad_array* quad_table;
extern int symbol_table_counter;
extern string current_block_name;

extern char* yytext;
extern int yyparse();

class symbol_type {
public:
    string type;
    int size;
    symbol_type* ptr;
    symbol_type(string type, int size = 0, symbol_type* ptr = NULL);
};

class symbol {
public:
    string name;
    symbol_type* type;
    string initial_value;
    int size;
    int offset;
    symbol_table* nested_table;
    symbol(string name, symbol_type* type, string initial_value = "", int size = 0, int offset = 0, symbol_table* nested_table = NULL);
    symbol* update(symbol_type* type);
};

class symbol_table {
public:
    string name;
    int count;
    symbol_table* parent;
    vector<symbol*> symbols;
    symbol_table(string name = "", symbol_table* parent = NULL);
    symbol* lookup(string name);
    symbol* lookup(string name, bool search_parent);
    symbol* insert(string name, symbol_type* type, string initial_value = "", int size = 0, int offset = 0, symbol_table* nested_table = NULL);
    void print();
};


#endif