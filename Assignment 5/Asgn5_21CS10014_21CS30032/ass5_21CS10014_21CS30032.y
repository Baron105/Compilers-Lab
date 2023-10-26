%{
    #include <iostream>
    #include "ass5_21CS10014_21CS30032_translator.h"
    using namespace std;

    extern int yylex();         
    void yyerror(string s);     
    extern char* yytext;        
    extern int yylineno;        
    extern string typevar;      
%}



%union {
    int intval;
    float floatval;
    char charval;
    char* strval;
    char op;
    int nparam;
    expression* expr;
    statement* stmt;
    int bp;
    symbol* sym;
    symbol_type* symtyp;
    Array* arr;
}

%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE BOOL COMPLEX IMAGINARY

%token SQUARE_BRACKET_OPEN SQUARE_BRACKET_CLOSE ROUND_BRACKET_OPEN ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN CURLY_BRACKET_CLOSE
%token DOT ARROW INCREMENT DECREMENT
%token BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_NOT
%token LOGICAL_AND LOGICAL_OR LOGICAL_NOT
%token MULTIPLY DIVIDE MODULO PLUS MINUS
%token LEFT_SHIFT RIGHT_SHIFT LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL EQUAL NOT_EQUAL
%token ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN MODULO_ASSIGN LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN BITWISE_AND_ASSIGN BITWISE_XOR_ASSIGN BITWISE_OR_ASSIGN
%token COMMA COLON SEMICOLON ELLIPSIS QUESTION_MARK HASH

%token <intval> INTEGER_CONSTANT
%token <strval> FLOATING_CONSTANT
%token <strval> CHAR_CONSTANT
%token <strval> STRING_LITERAL
%token <sym> IDENTIFIER

%right THEN ELSE

%token WS

%start translation_unit

%type <op> unary_operator
%type <nparam> argument_expression_list_opt argument_expression_list
%type <expr> expression primary_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression AND_expression exclusive_OR_expression inclusive_OR_expression logical_AND_expression logical_OR_expression conditional_expression assignment_expression constant_expression expression_statement
%type <stmt> statement compound_statement loop_statement jump_statement labeled_statement selection_statement iteration_statement block_item_list_opt block_item_list block_item
%type <symtyp> pointer
%type <sym> direct_declarator declarator init_declarator constant initializer
%type <arr> postfix_expression unary_expression cast_expression

%type <bp> M
%type <stmt> N



%%

primary_expression
    : IDENTIFIER { $$ = new expression(); $$->loc = $1 ; $$->type = "non_bool"; }
    | constant { $$ = new expression(); $$->loc = $1 ; }
    | STRING_LITERAL { $$ = new expression() ; $$->loc = symbol_table :: gentemp(new symbol_type("ptr"),$1); $$->loc->type->ptr = new symbol_type("char"); }
    | ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE { $$ = $2 ; }
    ;

constant
    : INTEGER_CONSTANT {
        $$ = symbol_table :: gentemp(new symbol_type("int"),int2string($1));
        emit("=",$$->name,$1);
    }
    | FLOATING_CONSTANT { 
        $$ = symbol_table :: gentemp(new symbol_type("float"),string($1));
        emit("=",$$->name,$1);
     }
    | CHAR_CONSTANT {
        $$ = symbol_table :: gentemp(new symbol_type("char"),string($1));
        emit("=",$$->name,$1);
    }
    ;

postfix_expression
    : primary_expression {
        $$ = new Array();
        $$->arr = $1->loc;
        $$->type = $1->loc->type;
        $$->loc = $$->arr;

    }
    | postfix_expression SQUARE_BRACKET_OPEN expression SQUARE_BRACKET_CLOSE {
        $$ = new Array();
        $$->type = $1->type->ptr;
        $$->arr = $1->arr;
        $$->loc = symbol_table :: gentemp(new symbol_type("int"));
        $$->arrtype = "arr";

        if($1->arrtype == "arr")
        {
            symbol * symb = symbol_table :: gentemp(new symbol_type("int"));
            int size  = getsize($$->type);
            emit("+",symb->name,$3->loc->name,int2string(size));
            emit("+",$$->loc->name,$1->loc->name,symb->name);
        }
        else 
        {
            int size = getsize($$->type);
            emit("+",$$->loc->name,$3->loc->name,int2string(size));
        }
    }
    | postfix_expression ROUND_BRACKET_OPEN ROUND_BRACKET_CLOSE 
    { /* nothin */}
    | postfix_expression ROUND_BRACKET_OPEN argument_expression_list_opt ROUND_BRACKET_CLOSE { 
        // Corresponds to calling a function with the  function name and the appropriate number of parameters
        $$ = new Array();
        $$->arr = symbol_table :: gentemp($1->type);
        emit("call",$$->arr->name,$1->arr->name,int2string($3));
    }
    | postfix_expression DOT IDENTIFIER 
    { /* nothin */}
    | postfix_expression ARROW IDENTIFIER 
    { /* nothin */}
    | postfix_expression INCREMENT {
        $$ = new Array();
        $$->arr = symbol_table :: gentemp($1->arr->type);
        emit("=",$$->arr->name,$1->arr->name);
        emit("+",$1->arr->name,$1->arr->name,"1");
    }
    | postfix_expression DECREMENT {
        $$ = new Array();
        $$->arr = symbol_table :: gentemp($1->arr->type);
        emit("=",$$->arr->name,$1->arr->name);
        emit("-",$1->arr->name,$1->arr->name,"1");
    }
    | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE 
    { /* nothin */}
    | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE 
    { /* nothin */}
    ;

argument_expression_list_opt
    : argument_expression_list {$$ = $1;}
    | %empty
    { $$ = 0; }
    ;

argument_expression_list 
    : assignment_expression {
        $$ = 1;
        emit("param",$1->loc->name);
    }
    | argument_expression_list COMMA assignment_expression { 
        $$ = $1 + 1;
        emit("param",$3->loc->name);
    }
    ;

unary_expression
    : postfix_expression {$$ = $1;}
    | INCREMENT unary_expression {
        emit("+",$2->arr->name,$2->arr->name,"1");
        $$ = $2;
    }
    | DECREMENT unary_expression {
        emit("-",$2->arr->name,$2->arr->name,"1");
        $$ = $2;
    }
    | unary_operator cast_expression {
        $$ = new Array();
        switch($1)
        {
            case '&' : 
                $$->arr = symbol_table :: gentemp(new symbol_type("ptr"));
                $$->arr->type->ptr = $2->arr->type;
                emit("= &",$$->arr->name,$2->arr->name);
                break;
            
            case '*' :
                $$->arrtype = "ptr" ;
                $$->loc = symbol_table :: gentemp($2->arr->type->ptr);
                $$->arr = $2->arr;
                emit("= *",$$->loc->name,$2->arr->name);
                break;
            
            case '+' :
                $$ = $2;
                break;

            case '-' :
                $$->arr = symbol_table :: gentemp($2->arr->type->ptr);
                emit("= -",$$->arr->name,$2->arr->name);
                break;

            case '~' :
                $$->arr = symbol_table :: gentemp($2->arr->type->ptr);
                emit("= ~",$$->arr->name,$2->arr->name);
                break;
            
            case '!' :
                $$->arr = symbol_table :: gentemp($2->arr->type->ptr);
                emit("= !",$$->arr->name,$2->arr->name);
                break;
        }
    }
    | SIZEOF unary_expression 
    { /* nothin */}
    | SIZEOF ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE 
    { /* nothin */}
    ;

unary_operator
    : BITWISE_AND { $$ = '&'; }
    | MULTIPLY { $$ = '*';}
    | PLUS { $$ = '+';}
    | MINUS { $$ = '-';}
    | BITWISE_NOT { $$ = '~';}
    | LOGICAL_NOT { $$ = '!';}
    ;

cast_expression
    : unary_expression { $$ = $1; }
    | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE cast_expression {
        $$ = new Array() ;
        $$->arr = convertType($4->arr,typevar);
    }
    ;

multiplicative_expression
    : cast_expression {
        $$ = new expression();
        if($1->arrtype == "arr")
        {
            $$->loc = symbol_table :: gentemp($1->loc->type);
            emit("=[]",$$->loc->name,$1->arr->name,$1->loc->name);
        }
        else if($1->arrtype == "ptr")
        {
            $$->loc = $1->arr;
        }
        else 
        {
            $$->loc = $1->arr;
        }
    }
    | multiplicative_expression MULTIPLY cast_expression {
        
        if(typecheck($1->loc,$3->arr))
        {
            $$ = new expression();
            $$->loc = symbol_table :: gentemp(new symbol_type($1->loc->type->type));
            emit("*",$$->loc->name,$1->loc->name,$3->arr->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    | multiplicative_expression DIVIDE cast_expression {
        
        if(typecheck($1->loc,$3->arr))
        {
            $$ = new expression();
            $$->loc = symbol_table :: gentemp(new symbol_type($1->loc->type->type));
            emit("/",$$->loc->name,$1->loc->name,$3->arr->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    | multiplicative_expression MODULO cast_expression {
        
        if(typecheck($1->loc,$3->arr))
        {
            $$ = new expression();
            $$->loc = symbol_table :: gentemp(new symbol_type($1->loc->type->type));
            emit("%",$$->loc->name,$1->loc->name,$3->arr->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    ;

additive_expression
    : multiplicative_expression { $$=$1; }
    | additive_expression PLUS multiplicative_expression {

        if(typecheck($1->loc,$3->loc))
        {
            $$ = new expression();
            $$->loc = symbol_table :: gentemp(new symbol_type($1->loc->type->type));
            emit("+",$$->loc->name,$1->loc->name,$3->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    | additive_expression MINUS multiplicative_expression {
        
        if(typecheck($1->loc,$3->loc))
        {
            $$ = new expression();
            $$->loc = symbol_table :: gentemp(new symbol_type($1->loc->type->type));
            emit("-",$$->loc->name,$1->loc->name,$3->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    ;

shift_expression
    : additive_expression { $$=$1; }
    | shift_expression LEFT_SHIFT additive_expression {
        
        if($3->loc->type->type == "int")
        {
            $$ = new expression();
            $$->loc = symbol_table :: gentemp(new symbol_type("int"));
            emit("<<",$$->loc->name,$1->loc->name,$3->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    | shift_expression RIGHT_SHIFT additive_expression {
        
        if($3->loc->type->type == "int")
        {
            $$ = new expression();
            $$->loc = symbol_table :: gentemp(new symbol_type("int"));
            emit(">>",$$->loc->name,$1->loc->name,$3->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    ;

relational_expression
    : shift_expression { $$ = $1; }
    | relational_expression LESS_THAN shift_expression
    {
        if(typecheck($1->loc ,$3->loc))
        {
            $$ = new expression();
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());
            $$->falselist = makelist(nextinstr()+1);
            emit("<","",$1->loc->name,$3->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    | relational_expression GREATER_THAN shift_expression { 
        if(typecheck($1->loc ,$3->loc))
        {
            $$ = new expression();
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());
            $$->falselist = makelist(nextinstr()+1);
            emit(">","",$1->loc->name,$3->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
     }
    | relational_expression LESS_THAN_EQUAL shift_expression {
        if(typecheck($1->loc ,$3->loc))
        {
            $$ = new expression();
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());
            $$->falselist = makelist(nextinstr()+1);
            emit("<=","",$1->loc->name,$3->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    
    | relational_expression GREATER_THAN_EQUAL shift_expression 
    {
        if(typecheck($1->loc ,$3->loc))
        {
            $$ = new expression();
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());
            $$->falselist = makelist(nextinstr()+1);
            emit(">=","",$1->loc->name,$3->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQUAL relational_expression {
        
        if(typecheck($1->loc,$3->loc))
        {
            convertBool2Int($1);
            convertBool2Int($3);
            $$ = new expression();
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());
            $$->falselist = makelist(nextinstr()+1);
            emit("==","",$1->loc->name,$3->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    | equality_expression NOT_EQUAL relational_expression {
        
        if(typecheck($1->loc,$3->loc))
        {
            convertBool2Int($1);
            convertBool2Int($3);
            $$ = new expression();
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());
            $$->falselist = makelist(nextinstr()+1);
            emit("!=","",$1->loc->name,$3->loc->name);
            emit("goto","");
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    ;

AND_expression
    : equality_expression { $$ = $1; }
    | AND_expression BITWISE_AND equality_expression { 
        
        if(typecheck($1->loc,$3->loc))
        {
            convertBool2Int($1);
            convertBool2Int($3);
            $$ = new expression();
            $$->type = "not_bool";
            $$->loc = symbol_table :: gentemp(new symbol_type("int"));
            emit("&",$$->loc->name,$1->loc->name,$3->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    ;

exclusive_OR_expression
    : AND_expression { $$ = $1; }
    | exclusive_OR_expression BITWISE_XOR AND_expression {
        
        if(typecheck($1->loc,$3->loc))
        {
            convertBool2Int($1);
            convertBool2Int($3);
            $$ = new expression();
            $$->type = "not_bool";
            $$->loc = symbol_table :: gentemp(new symbol_type("int"));
            emit("^",$$->loc->name,$1->loc->name,$3->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    ;

inclusive_OR_expression
    : exclusive_OR_expression {$$ = $1;}
    | inclusive_OR_expression BITWISE_OR exclusive_OR_expression {
        
        if(typecheck($1->loc,$3->loc))
        {
            convertBool2Int($1);
            convertBool2Int($3);
            $$ = new expression();
            $$->type = "not_bool";
            $$->loc = symbol_table :: gentemp(new symbol_type("int"));
            emit("|",$$->loc->name,$1->loc->name,$3->loc->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    ;

logical_AND_expression
    : inclusive_OR_expression { $$ = $1; }
    | logical_AND_expression LOGICAL_AND M inclusive_OR_expression {
        
        /* 
            here we have made few changes to the grammar to incorporate non terminal M to handle backpatching
        */

        convertBool2Int($1);
        convertBool2Int($4);
        $$ = new expression();
        $$->type = "bool";
        backpatch($1->truelist,$3);
        $$->truelist = $4->truelist;
        $$->falselist = merge($1->falselist,$4->falselist);

    }
    ;

logical_OR_expression
    : logical_AND_expression { $$ = $1; }
    | logical_OR_expression LOGICAL_OR M logical_AND_expression {
        
        convertBool2Int($1);
        convertBool2Int($4);
        $$ = new expression();
        $$->type = "bool";
        backpatch($1->falselist,$3);
        $$->truelist = merge($1->truelist,$4->truelist);
        $$->falselist = $4->falselist;
    }
    ;

conditional_expression
    : logical_OR_expression { $$ = $1; }
    | logical_OR_expression N QUESTION_MARK M expression N COLON M conditional_expression {
        
        /* 
            here we have made few changes to the grammar to incorporate non terminal N and M to handle backpatching
        */

        $$->loc = symbol_table :: gentemp($5->loc->type);
        $$->loc->update($5->loc->type);
        emit("=", $$->loc->name, $9->loc->name);
        list<int> l1 = makelist(nextinstr());
        emit("goto", "");
        backpatch($6->nextlist, nextinstr());
        emit("=", $$->loc->name, $5->loc->name);
        list<int> l2 = makelist(nextinstr());
        l1=merge(l1,l2);
        emit("goto", "");
        backpatch($2->nextlist, nextinstr());
        convertInt2Bool($1);
        backpatch($1->truelist,$4);
        backpatch($1->falselist,$8);
        backpatch(l1,nextinstr());
    }
    ;

M:  %empty
    {
        // keeps track of the next instruction and is useful in backpatching

        $$ = nextinstr();
    }
    ;

N:  %empty
    {
        // helps in the handling control flow

        $$ = new statement();
        $$->nextlist = makelist(nextinstr());
        emit("goto","");
    }
    ;

assignment_expression
    : conditional_expression { $$ = $1; }
    | unary_expression assignment_operator assignment_expression {
        
        if($1->arrtype == "arr")
        {
            $3->loc = convertType($3->loc,$1->type->type);
            emit("[]=", $1->arr->name,$1->loc->name,$3->loc->name);
        }
        else if($1->arrtype == "ptr")
        {
            emit("*=", $1->arr->name,$3->loc->name);
        }
        else 
        {
            $3->loc = convertType($3->loc,$1->arr->type->type);
            emit("=", $1->arr->name,$3->loc->name);
        }
        $$ = $3;
    }
    ;

assignment_operator
    : ASSIGN 
    { /* nothin */}
    | MULTIPLY_ASSIGN 
    { /* nothin */}
    | DIVIDE_ASSIGN 
    { /* nothin */}
    | MODULO_ASSIGN 
    { /* nothin */}
    | PLUS_ASSIGN 
    { /* nothin */}
    | MINUS_ASSIGN 
    { /* nothin */}
    | LEFT_SHIFT_ASSIGN 
    { /* nothin */}
    | RIGHT_SHIFT_ASSIGN 
    { /* nothin */}
    | BITWISE_AND_ASSIGN 
    { /* nothin */}
    | BITWISE_XOR_ASSIGN 
    { /* nothin */}
    | BITWISE_OR_ASSIGN 
    { /* nothin */}
    ;

// my part

expression
    : assignment_expression { $$ = $1; }
    | expression COMMA assignment_expression { /* No Action Taken */ }
    ;

constant_expression
    : conditional_expression { /* No Action Taken */ }
    ;


declaration
    : declaration_specifiers init_declarator_list_opt SEMICOLON { /* No Action Taken */ }
    ;

init_declarator_list_opt
    : init_declarator_list { /* No Action Taken */ }
    | %empty
    { /* No Action Taken */ }
    ;

declaration_specifiers
    : storage_class_specifier declaration_specifiers_opt { /* No Action Taken */ }
    | type_specifier declaration_specifiers_opt { /* No Action Taken */ }
    | type_qualifier declaration_specifiers_opt { /* No Action Taken */ }
    | function_specifier declaration_specifiers_opt { /* No Action Taken */ }
    ;

declaration_specifiers_opt
    : declaration_specifiers { /* No Action Taken */ }
    | %empty
    { /* No Action Taken */ }
    ;

init_declarator_list 
    : init_declarator { /* No Action Taken */ }
    | init_declarator_list COMMA init_declarator { /* No Action Taken */ }
    ;

init_declarator
    : declarator { $$ = $1; }
    | declarator ASSIGN initializer
    {
        if ($3->value != "")
        {
            $1->value = $3->value;
        }
        emit("=", $1->name, $3->name);
    }
    ;

storage_class_specifier
    : EXTERN { /* No Action Taken */ }
    | STATIC { /* No Action Taken */ }
    | AUTO { /* No Action Taken */ }
    | REGISTER { /* No Action Taken */ }
    ;

// store the type of the variable for void char int and float
// No Action Taken for the rest
type_specifier
    : VOID { typevar = "void"; }
    | CHAR { typevar = "char"; }
    | SHORT { /* No Action Taken */ }
    | INT { typevar = "int"; }
    | LONG { /* No Action Taken */ }
    | FLOAT { typevar = "float"; }
    | DOUBLE { /* No Action Taken */ }
    | SIGNED { /* No Action Taken */ }
    | UNSIGNED { /* No Action Taken */ }
    | BOOL { /* No Action Taken */ }
    | COMPLEX { /* No Action Taken */ }
    | IMAGINARY { /* No Action Taken */ }
    | enum_specifier { /* No Action Taken */ }
    ;

specifier_qualifier_list
    : type_specifier specifier_qualifier_list_opt { /* No Action Taken */ }
    | type_qualifier specifier_qualifier_list_opt { /* No Action Taken */ }
    ;

specifier_qualifier_list_opt
    : specifier_qualifier_list { /* No Action Taken */ }
    | %empty
    { /* No Action Taken */ }
    ;

enum_specifier
    : ENUM identifier_opt CURLY_BRACKET_OPEN enumerator_list CURLY_BRACKET_CLOSE { /* No Action Taken */ }
    | ENUM identifier_opt CURLY_BRACKET_OPEN enumerator_list COMMA CURLY_BRACKET_CLOSE { /* No Action Taken */ }
    | ENUM IDENTIFIER { /* No Action Taken */ }
    ;

identifier_opt 
    : IDENTIFIER { /* No Action Taken */ }
    | %empty { /* No Action Taken */ }
    ;

enumerator_list
    : enumerator { /* No Action Taken */ }
    | enumerator_list COMMA enumerator { /* No Action Taken */ }
    ;

enumerator
    : IDENTIFIER { /* No Action Taken */ }
    | IDENTIFIER ASSIGN constant_expression { /* No Action Taken */ }
    ;

type_qualifier
    : CONST { /* No Action Taken */ }
    | RESTRICT { /* No Action Taken */ }
    | VOLATILE { /* No Action Taken */ }
    ;

function_specifier
    : INLINE { /* No Action Taken */ }
    ;

// **
declarator
    : pointer direct_declarator
    {
        symbol_type* t = $1;
        while(t->ptr != NULL)
        {
            t = t->ptr;
        }
        t->ptr = $2->type;
        $$ = $2->update($1);
    }
    | direct_declarator { /* No Action Taken */ }
    ;

direct_declarator
    : IDENTIFIER
    { 
        $$ = $1->update(new symbol_type(typevar));
        current_symbol = $$;
    }
    | ROUND_BRACKET_OPEN declarator ROUND_BRACKET_CLOSE { $$ = $2; }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list assignment_expression SQUARE_BRACKET_CLOSE { /* No Action Taken */ }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list SQUARE_BRACKET_CLOSE { /* No Action Taken */ }
    | direct_declarator SQUARE_BRACKET_OPEN assignment_expression SQUARE_BRACKET_CLOSE
    {
        symbol_type* t = $1->type;
        symbol_type* new1 = NULL;
        while(t->type == "arr")
        {
            new1 = t;
            t = t->ptr;
        }
        if (new1 == NULL)
        {
            int temp = atoi($3->loc->value.c_str());
            symbol_type* new_type = new symbol_type("arr", $1->type, temp);
            $$ = $1->update(new_type);
        }
        else
        {
            int temp = atoi($3->loc->value.c_str());
            new1->ptr = new symbol_type("arr", t, temp);
            $$ = $1->update($1->type);
        }
    }
    | direct_declarator SQUARE_BRACKET_OPEN SQUARE_BRACKET_CLOSE
    {
        symbol_type* t = $1->type;
        symbol_type* new1 = NULL;
        while(t->type == "arr")
        {
            new1 = t;
            t = t->ptr;
        }
        if (new1 == NULL)
        {
            symbol_type* new_type = new symbol_type("arr", $1->type, 0);
            $$ = $1->update(new_type);
        }
        else
        {
            new1->ptr = new symbol_type("arr", t, 0);
            $$ = $1->update($1->type);
        }
    }
    | direct_declarator ROUND_BRACKET_OPEN change_table parameter_type_list ROUND_BRACKET_CLOSE
    {
        current_symbol_table->name = $1->name;
        if ($1->type->type != "void")
        {
            symbol* new1 = current_symbol_table->lookup("return");
            new1->update($1->type);
        }
        $1->nested_table = current_symbol_table;
        current_symbol_table->parent = global_symbol_table;
        switchTable(global_symbol_table);
        current_symbol = $$;
    }
    | direct_declarator ROUND_BRACKET_OPEN change_table ROUND_BRACKET_CLOSE
    {
        current_symbol_table->name = $1->name;
        if ($1->type->type != "void")
        {
            symbol* new1 = current_symbol_table->lookup("return");
            new1->update($1->type);
        }
        $1->nested_table = current_symbol_table;
        current_symbol_table->parent = global_symbol_table;
        switchTable(global_symbol_table);
        current_symbol = $$;
    }
    | direct_declarator ROUND_BRACKET_OPEN identifier_list ROUND_BRACKET_CLOSE { /* No Action Taken */ }
    | direct_declarator SQUARE_BRACKET_OPEN STATIC type_qualifier_list assignment_expression SQUARE_BRACKET_CLOSE { /* No Action Taken */ }
    | direct_declarator SQUARE_BRACKET_OPEN STATIC assignment_expression SQUARE_BRACKET_CLOSE { /* No Action Taken */ }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list STATIC assignment_expression SQUARE_BRACKET_CLOSE { /* No Action Taken */ }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list MULTIPLY SQUARE_BRACKET_CLOSE { /* No Action Taken */ }
    | direct_declarator SQUARE_BRACKET_OPEN MULTIPLY SQUARE_BRACKET_CLOSE { /* No Action Taken */ }
    ;


type_qualifier_list_opt
    : type_qualifier_list { /* No Action Taken */ }
    | %empty { /* No Action Taken */ }
    ;

pointer 
    : MULTIPLY type_qualifier_list_opt { $$ = new symbol_type("ptr"); }
    | MULTIPLY type_qualifier_list_opt pointer { $$ = new symbol_type("ptr", $3); }
    ;

type_qualifier_list
    : type_qualifier { /* No Action Taken */ }
    | type_qualifier_list type_qualifier { /* No Action Taken */ }
    ;

parameter_type_list
    : parameter_list { /* No Action Taken */ }
    | parameter_list COMMA ELLIPSIS { /* No Action Taken */ }
    ;

parameter_list
    : parameter_declaration { /* No Action Taken */ }
    | parameter_list COMMA parameter_declaration { /* No Action Taken */ }
    ;

parameter_declaration
    : declaration_specifiers declarator { /* No Action Taken */ }
    | declaration_specifiers { /* No Action Taken */ }
    ;

identifier_list
    : IDENTIFIER { /* No Action Taken */ }
    | identifier_list COMMA IDENTIFIER { /* No Action Taken */ }
    ;

type_name
    : specifier_qualifier_list { /* No Action Taken */ }
    ;

initializer
    : assignment_expression { $$ = $1->loc; }
    | CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE { /* No Action Taken */ }
    | CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE { /* No Action Taken */ }
    ;

initializer_list
    : designation_opt initializer { /* No Action Taken */ }
    | initializer_list COMMA designation_opt initializer { /* No Action Taken */ }
    ;

designation_opt
    : designation { /* No Action Taken */ }
    | %empty
    { /* No Action Taken */ }
    ;

designation
    : designator_list ASSIGN { /* No Action Taken */ }
    ;

designator_list
    : designator { /* No Action Taken */ }
    | designator_list designator { /* No Action Taken */ }
    ;

designator
    : SQUARE_BRACKET_OPEN constant_expression SQUARE_BRACKET_CLOSE { /* No Action Taken */ }
    | DOT IDENTIFIER { /* No Action Taken */ }
    ;

// new
// part 3
statement 
    : labeled_statement { /* No Action Taken */ }
    | compound_statement { $$ = $1; }
    | expression_statement
    { 
        $$ = new statement();
        $$->nextlist = $1->nextlist;
    }
    | selection_statement { $$ = $1; }
    | iteration_statement { $$ = $1; }
    | jump_statement { $$ = $1; }
    ;

loop_statement
    : labeled_statement { /* No Action Taken */ }
    | compound_statement { $$ = $1; }
    | expression_statement
    {
        $$ = new statement();
        $$->nextlist = $1->nextlist;
    }
    | selection_statement { $$ = $1; }
    | iteration_statement { $$ = $1; }
    | jump_statement { $$ = $1; }
    ;

labeled_statement
    : IDENTIFIER COLON statement { /* No Action Taken */ }
    | CASE constant_expression COLON statement { /* No Action Taken */ }
    | DEFAULT COLON statement { /* No Action Taken */ }
    ;

compound_statement
    : CURLY_BRACKET_OPEN X change_table block_item_list_opt CURLY_BRACKET_CLOSE
    {
        $$ = $4;
        switchTable(current_symbol_table->parent);
    }
    ;

block_item_list_opt
    : block_item_list { $$ = $1; }
    | %empty
    { $$ = new statement(); }
    ;

block_item_list
    : block_item { $$ = $1; }
    | block_item_list M block_item
    {
        $$ = $3;
        backpatch($1->nextlist, $2);
    }
    ;

block_item
    : declaration { $$ = new statement(); }
    | statement { $$ = $1; }
    ;

expression_statement
    : expression SEMICOLON { $$ = $1; }
    | SEMICOLON { $$ = new expression(); }

selection_statement
    : IF ROUND_BRACKET_OPEN expression N ROUND_BRACKET_CLOSE M statement N THEN
    {
        backpatch($4->nextlist, nextinstr());
        convertInt2Bool($3);
        $$ = new statement();
        backpatch($3->truelist, $6);

        list<int> temp = merge ($3->falselist, $7->nextlist);
        $$->nextlist = merge($8->nextlist, temp);
    }
    | IF ROUND_BRACKET_OPEN expression N ROUND_BRACKET_CLOSE M statement N ELSE M statement
    {
        backpatch($4->nextlist, nextinstr());
        convertInt2Bool($3);
        $$ = new statement();
        backpatch($3->truelist, $6);
        backpatch($3->falselist, $10);

        list<int> temp = merge ($3->falselist, $8->nextlist);
        $$->nextlist = merge($11->nextlist, temp);
    }
    | SWITCH ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement { /* No Action Taken */ }
    ;

iteration_statement
    :
    WHILE W ROUND_BRACKET_OPEN X change_table M expression ROUND_BRACKET_CLOSE M loop_statement
    {
        $$ = new statement();
        convertInt2Bool($7);
        backpatch($7->truelist, $9);
        backpatch($10->nextlist, $6);

        $$->nextlist = $7->falselist;
        emit("goto", int2string($6));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
    | WHILE W ROUND_BRACKET_OPEN X change_table M expression ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN M block_item_list_opt CURLY_BRACKET_CLOSE
    {
        $$ = new statement();
        convertInt2Bool($7);
        backpatch($7->truelist, $10);
        backpatch($11->nextlist, $6);

        $$->nextlist = $7->falselist;
        emit("goto", int2string($6));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
    | DO D M loop_statement M WHILE ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE SEMICOLON
    {
        $$ = new statement();
        convertInt2Bool($8);
        backpatch($8->truelist, $3);
        backpatch($4->nextlist, $5);

        $$->nextlist = $8->falselist;

        current_block_name = "";
    }
    | DO D CURLY_BRACKET_OPEN M block_item_list_opt CURLY_BRACKET_CLOSE M WHILE ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE SEMICOLON
    {
        $$ = new statement();
        convertInt2Bool($10);
        backpatch($10->truelist, $4);
        backpatch($5->nextlist, $7);

        $$->nextlist = $10->falselist;

        current_block_name = "";
    }
    | FOR F ROUND_BRACKET_OPEN X change_table declaration M expression_statement M expression N ROUND_BRACKET_CLOSE M loop_statement
    {
        $$ = new statement();
        convertInt2Bool($8);
        backpatch($8->truelist, $13);
        backpatch($14->nextlist, $9);
        backpatch($11->nextlist, $7);

        $$->nextlist = $8->falselist;
        emit("goto", int2string($9));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
    | FOR F ROUND_BRACKET_OPEN X change_table expression_statement M expression_statement M expression N ROUND_BRACKET_CLOSE M loop_statement
    {
        $$ = new statement();
        convertInt2Bool($8);
        backpatch($8->truelist, $13);
        backpatch($14->nextlist, $9);
        backpatch($11->nextlist, $7);

        $$->nextlist = $8->falselist;
        emit("goto", int2string($9));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
    | FOR F ROUND_BRACKET_OPEN X change_table expression_statement M expression_statement M expression N ROUND_BRACKET_CLOSE M CURLY_BRACKET_OPEN block_item_list_opt CURLY_BRACKET_CLOSE
    {
        $$ = new statement();
        convertInt2Bool($8);
        backpatch($8->truelist, $13);
        backpatch($15->nextlist, $9);
        backpatch($11->nextlist, $7);

        $$->nextlist = $8->falselist;
        emit("goto", int2string($9));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
    | FOR F ROUND_BRACKET_OPEN X change_table declaration M expression_statement M expression N ROUND_BRACKET_CLOSE M CURLY_BRACKET_OPEN block_item_list_opt CURLY_BRACKET_CLOSE
    {
        $$ = new statement();
        convertInt2Bool($8);
        backpatch($8->nextlist, $13);
        backpatch($15->nextlist, $9);
        backpatch($11->nextlist, $7);

        $$->nextlist = $8->falselist;
        emit("goto", int2string($9));
        current_block_name = "";
        switchTable(current_symbol_table->parent);
    }
    ;

F
    : { current_block_name = "for"; }
    ;

W
    : { current_block_name = "while"; }
    ;

D
    : { current_block_name = "do_while"; }
    ;

X   
    : %empty
    {
        string new_ST = current_symbol_table->name + "_" + current_block_name + "_" + to_string(symbol_table_counter++);
        symbol* new_symbol = current_symbol_table->lookup(new_ST);
        new_symbol->nested_table = new symbol_table(new_ST);
        new_symbol->name = new_ST;
        new_symbol->nested_table->parent = current_symbol_table;
        new_symbol->type = new symbol_type("block");
        current_symbol = new_symbol;
    }

change_table
    : %empty
    {
        if (current_symbol->nested_table != NULL)
        {
            switchTable(current_symbol->nested_table);
            emit("change", current_symbol_table->name);
        }
        else 
        {
            switchTable(new symbol_table(""));
        }
    }
    ;

jump_statement
    : GOTO IDENTIFIER SEMICOLON { /* No Action Taken */ }
    | CONTINUE SEMICOLON { $$ = new statement(); }
    | BREAK SEMICOLON { $$ = new statement(); }
    | RETURN expression SEMICOLON
    {
        $$ = new statement();
        emit("return", $2->loc->name);
    }
    | RETURN SEMICOLON
    {
        $$ = new statement();
        emit("return", "");
    }
    ;


translation_unit
    : external_declaration { /* No Action Taken */ }
    | translation_unit external_declaration { /* No Action Taken */ }
    ;

external_declaration
    : function_definition { /* No Action Taken */ }
    | declaration { /* No Action Taken */ }
    ;


function_definition
    : declaration_specifiers declarator declaration_list_opt change_table CURLY_BRACKET_OPEN block_item_list_opt CURLY_BRACKET_CLOSE
    {
        current_symbol_table->parent = global_symbol_table;
        symbol_table_counter = 0;
        switchTable(global_symbol_table);
    }
    ;

declaration_list_opt
    : declaration_list { /* No Action Taken */ }
    | %empty 
    { /* No Action Taken */ }
    ;

declaration_list
    : declaration { /* No Action Taken */ }
    | declaration_list declaration { /* No Action Taken */ }
    ;

%%

void yyerror(string s) {
    // for error reporting
    cout << "Error: " << s << endl;
    cout << "Line: " << yylineno << endl;
    cout << "Text: " << yytext << endl;
}