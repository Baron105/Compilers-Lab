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
    char operator;
    int nparam;
    expression* expr;
    statement* stmt;
    quad* q;
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
%token <floatval> FLOATING_CONSTANT
%token <charval> CHAR_CONSTANT
%token <strval> STRING_LITERAL
%token <sym> IDENTIFIER

%right THEN ELSE

%token WS

%start translation_unit

%type <operator> unary_operator
%type <nparam> argument_expression_list_opt argument_expression_list
%type <expr> expression primary_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression AND_expression exclusive_OR_expression inclusive_OR_expression logical_AND_expression logical_OR_expression conditional_expression assignment_expression constant_expression
%type <stmt> statement compound_statement loop_statement jump_statement labeled_statement selection_statement iteration_statement expression_statement block_item_list_opt block_item_list block_item


// Some NON terminal symbols to be defined 


// ----------------------x------------------




primary_expression
    : IDENTIFIER { $$ = new expression(); $$->loc = $1 ; $$->type = "non_bool"; }
    | constant { $$ = new expression(); $$->loc = $1 ; }
    | STRING_LITERAL { $$ new expression() ; $$->loc = symbol_table :: gentemp(new symbol_type("ptr"),$1); $$->loc->type->ptr = new symbol_type("char"); }
    | ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE { $$ = $2 ; }
    ;

constant
    : INTEGER_CONSTANT {
        $$ = symbol_table :: gentemp(new symbol_type("int"),int2string($1));
        emit("=",$$->name,$1);
    }
    | FLOATING_CONSTANT { 
        $$ = symbol_table :: gentemp(new symbol_type("float"),float2string($1));
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
            emit("+",symb->name,%3->loc->name,int2string(size));
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
    | { $$ = 0; }
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
                $$->arr = symbol_table :: gentemp($2->arr->type->type);
                emit("= -",$$->arr->name,$2->arr->name);
                break;

            case '~' :
                $$->arr = symbol_table :: gentemp($2->arr->type->type);
                emit("= ~",$$->arr->name,$2->arr->name);
                break;
            
            case '!' :
                $$->arr = symbol_table :: gentemp($2->arr->type->type);
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
        $$->arr = convertType($4->arr,varType);
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

        if(typecheck($1->loc,$3->arr))
        {
            $$ = new expression();
            $$->loc = symbol_table :: gentemp(new symbol_type($1->loc->type->type));
            emit("+",$$->loc->name,$1->loc->name,$3->arr->name);
        }
        else 
        {
            yyerror("Type mismatch");
        }
    }
    | additive_expression MINUS multiplicative_expression {
        
        if(typecheck($1->loc,$3->arr))
        {
            $$ = new expression();
            $$->loc = symbol_table :: gentemp(new symbol_type($1->loc->type->type));
            emit("-",$$->loc->name,$1->loc->name,$3->arr->name);
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
            convertBoolToInt($1);
            convertBoolToInt($3);
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
            convertBoolToInt($1);
            convertBoolToInt($3);
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
            convertBoolToInt($1);
            convertBoolToInt($3);
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
            convertBoolToInt($1);
            convertBoolToInt($3);
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
            convertBoolToInt($1);
            convertBoolToInt($3);
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

        convertBoolToInt($1);
        convertBoolToInt($4);
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
        
        convertBoolToInt($1);
        convertBoolToInt($4);
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
        convertIntToBool($1);
        backpatch($1->truelist,$4);
        backpatch($1->falselist,$8);
        backpatch(l1,nextinstr());
    }
    ;

M:  {
        // keeps track of the next instruction and is useful in backpatching

        $$ = nextinstr();
    }
    ;

N:  {
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

expression
    : assignment_expression { printf("expression -> assignment-expression\n"); }
    | expression COMMA assignment_expression { printf("expression -> expression , assignment-expression\n"); }
    ;

constant_expression
    : conditional_expression { printf("constant-expression -> conditional-expression\n"); }
    ;


//Declarations

declaration
    : declaration_specifiers init_declarator_list_opt SEMICOLON { printf("declaration -> declaration-specifiers init-declarator-list-opt ;\n"); }
    ;

init_declarator_list_opt
    : init_declarator_list { printf("init-declarator-list-opt -> init-declarator-list\n"); }
    | { printf("init-declarator-list-opt -> epsilon\n"); }
    ;

declaration_specifiers
    : storage_class_specifier declaration_specifiers_opt { printf("declaration-specifiers -> storage-class-specifier declaration-specifiers-opt\n"); }
    | type_specifier declaration_specifiers_opt { printf("declaration-specifiers -> type-specifier declaration-specifiers-opt\n"); }
    | type_qualifier declaration_specifiers_opt { printf("declaration-specifiers -> type-qualifier declaration-specifiers-opt\n"); }
    | function_specifier declaration_specifiers_opt { printf("declaration-specifiers -> function-specifier declaration-specifiers-opt\n"); }
    ;

declaration_specifiers_opt
    : declaration_specifiers { printf("declaration-specifiers-opt -> declaration-specifiers\n"); }
    | { printf("declaration-specifiers-opt -> epsilon\n"); }
    ;

init_declarator_list 
    : init_declarator { printf("init-declarator-list -> init-declarator\n"); }
    | init_declarator_list COMMA init_declarator { printf("init-declarator-list -> init-declarator-list , init-declarator\n"); }
    ;

init_declarator
    : declarator { printf("init-declarator -> declarator\n"); }
    | declarator ASSIGN initializer { printf("init-declarator -> declarator = initializer\n"); }
    ;

storage_class_specifier
    : EXTERN { printf("storage-class-specifier -> extern\n"); }
    | STATIC { printf("storage-class-specifier -> static\n"); }
    | AUTO { printf("storage-class-specifier -> auto\n"); }
    | REGISTER { printf("storage-class-specifier -> register\n"); }
    ;

type_specifier
    : VOID { printf("type-specifier -> void\n"); }
    | CHAR { printf("type-specifier -> char\n"); }
    | SHORT { printf("type-specifier -> short\n"); }
    | INT { printf("type-specifier -> int\n"); }
    | LONG { printf("type-specifier -> long\n"); }
    | FLOAT { printf("type-specifier -> float\n"); }
    | DOUBLE { printf("type-specifier -> double\n"); }
    | SIGNED { printf("type-specifier -> signed\n"); }
    | UNSIGNED { printf("type-specifier -> unsigned\n"); }
    | BOOL { printf("type-specifier -> _Bool\n"); }
    | COMPLEX { printf("type-specifier -> _Complex\n"); }
    | IMAGINARY { printf("type-specifier -> _Imaginary\n"); }
    | enum_specifier { printf("type-specifier -> enum-specifier\n"); }
    ;

specifier_qualifier_list
    : type_specifier specifier_qualifier_list_opt { printf("specifier-qualifier-list -> type-specifier specifier-qualifier-list-opt\n"); }
    | type_qualifier specifier_qualifier_list_opt { printf("specifier-qualifier-list -> type-qualifier specifier-qualifier-list-opt\n"); }
    ;

specifier_qualifier_list_opt
    : specifier_qualifier_list { printf("specifier-qualifier-list-opt -> specifier-qualifier-list\n"); }
    | { printf("specifier-qualifier-list-opt -> epsilon\n"); }
    ;

enum_specifier
    : ENUM identifier_opt CURLY_BRACKET_OPEN enumerator_list CURLY_BRACKET_CLOSE { printf("enum-specifier -> enum identifier-opt { enumerator-list-opt }\n"); }
    | ENUM identifier_opt CURLY_BRACKET_OPEN enumerator_list COMMA CURLY_BRACKET_CLOSE { printf("enum-specifier -> enum identifier-opt { enumerator-list , }\n"); }
    | ENUM IDENTIFIER { printf("enum-specifier -> enum identifier\n"); }
    ;

identifier_opt 
    : IDENTIFIER { printf("identifier-opt -> identifier\n"); }
    | { printf("identifier-opt -> epsilon\n"); }
    ;

enumerator_list
    : enumerator { printf("enumerator-list -> enumerator\n"); }
    | enumerator_list COMMA enumerator { printf("enumerator-list -> enumerator-list , enumerator\n"); }
    ;

enumerator
    : IDENTIFIER { printf("enumerator -> enumeration-constant\n"); }
    | IDENTIFIER ASSIGN constant_expression { printf("enumerator -> enumeration-constant = constant-expression\n"); }
    ;

type_qualifier
    : CONST { printf("type-qualifier -> const\n"); }
    | RESTRICT { printf("type-qualifier -> restrict\n"); }
    | VOLATILE { printf("type-qualifier -> volatile\n"); }
    ;

function_specifier
    : INLINE { printf("function-specifier -> inline\n"); }
    ;

declarator
    : pointer_opt direct_declarator { printf("declarator -> pointer-opt direct-declarator\n"); }
    ;

pointer_opt
    : pointer { printf("pointer-opt -> pointer\n"); }
    | { printf("pointer-opt -> epsilon\n"); }
    ;

direct_declarator
    : IDENTIFIER { printf("direct-declarator -> identifier\n"); }
    | ROUND_BRACKET_OPEN declarator ROUND_BRACKET_CLOSE { printf("direct-declarator -> ( declarator )\n"); }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list_opt assignment_expression_opt SQUARE_BRACKET_CLOSE { printf("direct-declarator -> direct-declarator [ type-qualifier-list-opt assignment-expression-opt ]\n"); }
    | direct_declarator SQUARE_BRACKET_OPEN STATIC type_qualifier_list_opt assignment_expression SQUARE_BRACKET_CLOSE { printf("direct-declarator -> direct-declarator [ static type-qualifier-list-opt assignment-expression ]\n"); }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list STATIC assignment_expression SQUARE_BRACKET_CLOSE { printf("direct-declarator -> direct-declarator [ type-qualifier-list static assignment-expression ]\n"); }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list_opt MULTIPLY SQUARE_BRACKET_CLOSE { printf("direct-declarator -> direct-declarator [ type-qualifier-list-opt * ]\n"); }
    | direct_declarator ROUND_BRACKET_OPEN parameter_type_list ROUND_BRACKET_CLOSE { printf("direct-declarator -> direct-declarator ( parameter-type-list )\n"); }
    | direct_declarator ROUND_BRACKET_OPEN identifier_list_opt ROUND_BRACKET_CLOSE { printf("direct-declarator -> direct-declarator ( identifier-list-opt )\n"); }
    ;

identifier_list_opt
    : identifier_list { printf("identifier-list-opt -> identifier-list\n"); }
    | { printf("identifier-list-opt -> epsilon\n"); }
    ;

assignment_expression_opt
    : assignment_expression { printf("assignment-expression-opt -> assignment-expression\n"); }
    | { printf("assignment-expression-opt -> epsilon\n"); }
    ;

type_qualifier_list_opt
    : type_qualifier_list { printf("type-qualifier-list-opt -> type-qualifier-list\n"); }
    | { printf("type-qualifier-list-opt -> epsilon\n"); }
    ;

pointer 
    : MULTIPLY type_qualifier_list_opt { printf("pointer -> * type-qualifier-list-opt\n"); }
    | MULTIPLY type_qualifier_list_opt pointer { printf("pointer -> * type-qualifier-list-opt pointer\n"); }
    ;

type_qualifier_list
    : type_qualifier { printf("type-qualifier-list -> type-qualifier\n"); }
    | type_qualifier_list type_qualifier { printf("type-qualifier-list -> type-qualifier-list type-qualifier\n"); }
    ;

parameter_type_list
    : parameter_list { printf("parameter-type-list -> parameter-list\n"); }
    | parameter_list COMMA ELLIPSIS { printf("parameter-type-list -> parameter-list , ...\n"); }
    ;

parameter_list
    : parameter_declaration { printf("parameter-list -> parameter-declaration\n"); }
    | parameter_list COMMA parameter_declaration { printf("parameter-list -> parameter-list , parameter-declaration\n"); }
    ;

parameter_declaration
    : declaration_specifiers declarator { printf("parameter-declaration -> declaration-specifiers declarator\n"); }
    | declaration_specifiers { printf("parameter-declaration -> declaration-specifiers\n"); }
    ;

identifier_list
    : IDENTIFIER { printf("identifier-list -> identifier\n"); }
    | identifier_list COMMA IDENTIFIER { printf("identifier-list -> identifier-list , identifier\n"); }
    ;

type_name
    : specifier_qualifier_list { printf("type-name -> specifier-qualifier-list\n"); }
    ;

initializer
    : assignment_expression { printf("initializer -> assignment-expression\n"); }
    | CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE { printf("initializer -> { initializer-list }\n"); }
    | CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE { printf("initializer -> { initializer-list , }\n"); }
    ;

initializer_list
    : designation_opt initializer { printf("initializer-list -> designation-opt initializer\n"); }
    | initializer_list COMMA designation_opt initializer { printf("initializer-list -> initializer-list , designation-opt initializer\n"); }
    ;

designation_opt
    : designation { printf("designation-opt -> designation\n"); }
    | { printf("designation-opt -> epsilon\n"); }
    ;

designation
    : designator_list ASSIGN { printf("designation -> designator-list =\n"); }
    ;

designator_list
    : designator { printf("designator-list -> designator\n"); }
    | designator_list designator { printf("designator-list -> designator-list designator\n"); }
    ;

designator
    : SQUARE_BRACKET_OPEN constant_expression SQUARE_BRACKET_CLOSE { printf("designator -> [ constant-expression ]\n"); }
    | DOT IDENTIFIER { printf("designator -> . identifier\n"); }
    ;

// new
// part 3
statement 
    : labeled_statement { printf("statement -> labeled-statement\n"); }
    | compound_statement { printf("statement -> compound-statement\n"); }
    | expression_statement { printf("statement -> expression-statement\n"); }
    | selection_statement { printf("statement -> selection-statement\n"); }
    | iteration_statement { printf("statement -> iteration-statement\n"); }
    | jump_statement { printf("statement -> jump-statement\n"); }
    ;

labeled_statement
    : IDENTIFIER COLON statement { printf("labeled-statement -> identifier : statement\n"); }
    | CASE constant_expression COLON statement { printf("labeled-statement -> case constant-expression : statement\n"); }
    | DEFAULT COLON statement { printf("labeled-statement -> default : statement\n"); }
    ;

compound_statement
    : CURLY_BRACKET_OPEN block_item_list_opt CURLY_BRACKET_CLOSE { printf("compound-statement -> { block-item-list-opt }\n"); }
    ;

block_item_list_opt
    : block_item_list { printf("block-item-list-opt -> block-item-list\n"); }
    | { printf("block-item-list-opt -> epsilon\n"); }
    ;

block_item_list
    : block_item { printf("block-item-list -> block-item\n"); }
    | block_item_list block_item { printf("block-item-list -> block-item-list block-item\n"); }
    ;

block_item
    : declaration { printf("block-item -> declaration\n"); }
    | statement { printf("block-item -> statement\n"); }
    ;

expression_statement
    : expression_opt SEMICOLON { printf("expression-statement -> expression-opt ;\n"); }
    ;

expression_opt
    : expression { printf("expression-opt -> expression\n"); }
    | { printf("expression-opt -> epsilon\n"); }
    ;

selection_statement
    : IF ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement { printf("selection-statement -> if ( expression ) statement\n"); }
    | IF ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement ELSE statement { printf("selection-statement -> if ( expression ) statement else statement\n"); }
    | SWITCH ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement { printf("selection-statement -> switch ( expression ) statement\n"); }
    ;

iteration_statement
    : WHILE ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement { printf("iteration-statement -> while ( expression ) statement\n"); }
    | DO statement WHILE ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE SEMICOLON { printf("iteration-statement -> do statement while ( expression ) ;\n"); }
    | FOR ROUND_BRACKET_OPEN expression_opt SEMICOLON expression_opt SEMICOLON expression_opt ROUND_BRACKET_CLOSE statement { printf("iteration-statement -> for ( expression-opt ; expression-opt ; expression-opt ) statement\n"); }
    | FOR ROUND_BRACKET_OPEN declaration expression_opt SEMICOLON expression_opt ROUND_BRACKET_CLOSE statement { printf("iteration-statement -> for ( declaration expression-opt ; expression-opt ) statement\n"); }
    ;

jump_statement
    : GOTO IDENTIFIER SEMICOLON { printf("jump-statement -> goto identifier ;\n"); }
    | CONTINUE SEMICOLON { printf("jump-statement -> continue ;\n"); }
    | BREAK SEMICOLON { printf("jump-statement -> break ;\n"); }
    | RETURN expression_opt SEMICOLON { printf("jump-statement -> return expression-opt ;\n"); }
    ;


// part 4
translation_unit
    : external_declaration { printf("translation-unit -> external-declaration\n"); }
    | translation_unit external_declaration { printf("translation-unit -> translation-unit external-declaration\n"); }
    ;

external_declaration
    : function_definition { printf("external-declaration -> function-definition\n"); }
    | declaration { printf("external-declaration -> declaration\n"); }
    ;

function_definition
    : declaration_specifiers declarator declaration_list_opt compound_statement { printf("function-definition --> declaration-specifiers declarator declaration-list-opt compound-statement\n"); }
    ;

declaration_list_opt
    : declaration_list { printf("declaration-list-opt -> declaration-list\n"); }
    | { printf("declaration-list-opt -> epsilon\n"); }
    ;

declaration_list
    : declaration { printf("declaration-list -> declaration\n"); }
    | declaration_list declaration { printf("declaration-list -> declaration-list declaration\n"); }
    ;

%%

void yyerror(char* s) {
    printf("Error: %s\n", s);
    printf("Line: %d\n", yylineno);
    printf("Text: %s\n", yytext);
}