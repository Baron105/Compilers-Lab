#include <iostream>
#include <string>
using namespace std;

#include "ass5_21CS10014_21CS30032_translator.h"

symbol *current_symbol;
symbol_table *current_symbol_table;
symbol_table *global_symbol_table;
quad_array quad_table;
int symbol_table_counter;
string current_block_name;

// string last_var_type;
string var_type;

symbol::symbol(string name, string t, symbol_type* st, int size):
    name(name), type(st), value("x"), size(size), offset(0), nested_table(NULL) {
    type = new symbol_type(t, size, st);
}

symbol_type::symbol_type(string type, int size, symbol_type* ptr):
    type(type), size(getsize(ptr)), ptr(ptr) {}

symbol* symbol::update(symbol_type* t) {
    type = t;
    return this;
}

symbol_table::symbol_table(string name, symbol_table* parent):
    name(name), count(0), parent(parent) {}

symbol *symbol_table::lookup(string name) {
    for (vector<symbol*>::iterator it = symbols.begin(); it != symbols.end(); it++) {
        if ((*it)->name == name) {
            return *it;
        }
    }

    symbol *s = NULL;
    if (this->parent != NULL) {
        s = this->parent->lookup(name);
    }
    if (current_symbol_table == this && s == NULL) {
        s = new symbol(name, "int");
        symbols.push_back(s);
        return &(*symbols.back());
    }
    return s;
}

symbol* symbol_table::gentemp(symbol_type* type, string value) {
    string name = "t" + int2string(current_symbol_table->count++);
    symbol* s = new symbol(name, type->type);
    s->type = type;
    s->value = value;
    s->size = getsize(type);

    current_symbol_table->symbols.push_back(s);
    return &(*current_symbol_table->symbols.back());
}

void symbol_table::print_st() {
    cout << "====================================================================================================" << endl;
    cout << "Symbol Table: " << name << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "Name\tValue\tType\tSize\tOffset\tNested Table" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    vector <symbol_table*> tables;

    for(int i = 0; i < symbols.size(); i++) {
        cout << symbols[i]->name << "\t" << symbols[i]->value << "\t" << symbols[i]->type->type << "\t" << symbols[i]->size << "\t" << symbols[i]->offset << "\t";
        if(symbols[i]->nested_table != NULL) {
            cout << symbols[i]->nested_table->name << endl;
            tables.push_back(symbols[i]->nested_table);
        }
        else {
            cout << "NULL" << endl;
        }
        cout << endl;
    }
    cout << "====================================================================================================" << endl;

    for(int i = 0; i < tables.size(); i++) {
        tables[i]->print_st();
    }
}

void symbol_table::update() {
    vector<symbol_table*> tables;
    int offset_new = 0;

    for(vector<symbol*>::iterator it = symbols.begin(); it != symbols.end(); it++) {
        if (it == symbols.begin()) {
            (*it)->offset = 0;
            offset_new = (*it)->size;
        }
        else {
            (*it)->offset = offset_new;
            offset_new += (*it)->size;
        }

        if ((*it)->nested_table != NULL) {
            tables.push_back((*it)->nested_table);
        }
    }
}


quad::quad(string result , string arg1 , string op, string arg2) : result(result) , arg1(arg1) , op(op) , arg2(arg2) {}

quad::quad(string result, int arg1, string op, string arg2 ) : result(result) , arg2(arg2) , op(op) {
    this->arg1 = int2string(arg1);
}
quad::quad(string result, float arg1, string op , string arg2) : result(result) , arg2(arg2) , op(op) {
    this->arg1 = float2string(arg1);
}


void quad :: print_quad()
{
    if (op == "=") cout << result << "=" << arg1;
    else if (op == "*=") cout << "*" << result << "=" << arg1;
    else if (op == "[]=") cout << result << "[" << arg1 << "]" << " = " << arg2;
    else if (op == "=[]") cout << result << " = " << arg1 << "[" << arg2 << "]";
    else if (op == "goto" || op == "param" || op == "return") cout << op << " " << result;
    else if (op == "call") cout << result << " = " << "call " << arg1 << ", " << arg2;
    else if (op == "label") cout << result << ": ";


    else if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%" || op == "^" || op == "|" || op == "&" || op == "<<" || op == ">>") cout << result << " = " << arg1 << " " << op << " " << arg2;
    else if(op == "==" || op == "!=" || op == "<" || op == ">" || op == "<=" || op == ">=") cout << "if " << arg1 << " " << op << " " << arg2 << " goto " << result;
    else if(op == "= &" || op == "= *" || op == "= -" || op == "= ~" || op == "= !") cout << result << " " << op << arg1;

    else cout << "Invalid Operator";
}

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


// the 3 emit functions
void emit(string op, string result, string arg1, string arg2) {
    quad* q = new quad(result, arg1, op, arg2);
    quad_table.arr.push_back(*q);
}

void emit(string op, string result, int arg1, string arg2) {
    quad* q = new quad(result, arg1, op, arg2);
    quad_table.arr.push_back(*q);
}

void emit(string op, string result, float arg1, string arg2) {
    quad* q = new quad(result, arg1, op, arg2);
    quad_table.arr.push_back(*q);
}

list<int> makelist(int index)
{
    list<int> lst(1,index);
    return lst;
}

list<int> merge(list<int> &a, list<int> &b)
{
    list<int> ret = a;
    ret.merge(b);
    return ret;
}


void backpatch(list<int> lst, int i)
{
    string s = int2string(i);

    for(list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        quad_table.arr[*it].result = s;
    }
}

bool typecheck(symbol* &a,symbol* &b)
{
    symbol_type *t1, *t2;
    t1 = a->type;
    t2 = b->type;

    if(typecheck(t1,t2))
        return true;
    else if(a=convertType(a,t2->type))
        return true ;
    else if(b=convertType(b,t1->type))
        return true ;
    else 
        return false ;
}


bool typecheck(symbol_type * a , symbol_type * b)
{
    if(a==NULL && b==NULL) return true ;
    else if(a==NULL || b==NULL) return false ;
    else if(a->type != b->type) return false ;
    

    return typecheck(a->ptr , b->ptr) ;
}


symbol* convertType(symbol* s , string t)
{
    symbol* temp = symbol_table::gentemp(new symbol_type(t));

    if(s->type->type == "float")
    {
        if(t=="int")
        {
            emit("=",temp->name,"float2int(" + s->name + ")");
            return temp;
        }
        else if(t=="char")
        {
            emit("=",temp->name,"float2char(" + s->name + ")");
            return temp;
        }
        return s;
    }

    else if(s->type->type == "int") {
        if(t == "float") {
            emit("=", temp->name, "int2float(" + s->name + ")");
            return temp;
        }
        else if(t == "char") {
            emit("=", temp->name, "int2char(" + s->name + ")");
            return temp;
        }
        return s;
    }

    else if(s->type->type == "char") {
        if(t == "float") {
            emit("=", temp->name, "char2float(" + s->name + ")");
            return temp;
        }
        else if(t == "int") {
            emit("=", temp->name, "char2int(" + s->name + ")");
            return temp;
        }
        return s;
    }

    return s;
}



string int2string(int n)
{
    return to_string(n);
}

string float2string(float n)
{
    return to_string(n);
}

expression* convertInt2Bool(expression* e)
{
    if(e->type != "bool")
    {
        e->falselist = makelist(nextinstr());
        emit("==",e->loc->name,"0");
        e->truelist = makelist(nextinstr());
        emit("goto","");
    }
    return e;
}


expression * convertBool2Int(expression * expr)
{
    if(expr->type == "bool")
    {
        expr->loc = symbol_table::gentemp(new symbol_type("int"));
        backpatch(expr->truelist,nextinstr());
        emit("=",expr->loc->name,"true");
        emit("goto" , int2string(nextinstr()+1));
        backpatch(expr->falselist,nextinstr());
        emit("=",expr->loc->name,"false");
    }
    return expr;
}


void switchTable(symbol_table *newtable)
{
    current_symbol_table = newtable;
}


int nextinstr()
{
    return quad_table.arr.size();
}


int getsize(symbol_type * x)
{
    if(x->type == "void") return __SIZE_OF_VOID ;
    else if(x->type == "char") return __SIZE_OF_CHAR ;
    else if(x->type == "int") return __SIZE_OF_INT ;
    else if(x->type == "float") return __SIZE_OF_FLOAT ;
    else if(x->type == "ptr") return __SIZE_OF_PTR ;
    else if(x->type == "arr") return x->size * getsize(x->ptr) ;
    else if(x->type == "func") return __SIZE_OF_FUNC ;

    else 
        return -1;
}



string gettype(symbol_type * x)
{
    if(x==NULL)
        return "null";
    if(x->type == "void" || x->type == "char" || x->type == "int" || x->type == "float" || x->type == "block" || x->type == "func") return x->type ;
    else if(x->type == "ptr") return "ptr(" + gettype(x->ptr) + ")" ;
    else if(x->type == "arr") return "arr(" + int2string(x->size) + ", " + gettype(x->ptr) + ")" ;
    else 
        return "invalid";
    
}

int main()
{
    symbol_table_counter = 0;
    global_symbol_table = new symbol_table("Global");
    current_symbol_table = global_symbol_table;
    current_block_name = "";
    
    yyparse();
    global_symbol_table->update();
    quad_table.print_quad_array();
    cout << "\n";
    global_symbol_table->print_st();
    return 0;
}