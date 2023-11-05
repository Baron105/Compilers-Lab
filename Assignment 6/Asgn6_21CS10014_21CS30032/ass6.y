%{
    #include <iostream>
    #include "translator.h"
    using namespace std;

    extern int yylex();         
    void yyerror(string s);     
    extern char* yytext;        
    extern int yylineno;

    extern int next_instr;
    extern symbol_table global_symbol_table;
    extern symbol_table* current_symbol_table;
    extern vector<string> consts;
    extern quad_array quad_list;
    int string_count = 0;
    //    
%}




%union {
    int intval;
    float floatval;
    char charval;
    void* ptr;
    string* str;
    symbol_type* symType;
    symbol* symp;
    data_type types;
    opcode opc;
    expression* expr;
    declaration* dec;
    vector<declaration*>* dec_list;
    param* p;
    vector<param*>* p_list;
    
}

%token AUTO BREAK CASE CHAR_T CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT_T FOR GOTO IF INLINE INT_T LONG REGISTER RESTRICT RETURN_T SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID_T VOLATILE WHILE BOOL_T COMPLEX IMAGINARY

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
%token <str> STRING_LITERAL
%token <str> IDENTIFIER

%expect 1
%nonassoc ELSE

%token WS

%type <charval> unary_operator
%type <expr> expression primary_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression AND_expression exclusive_OR_expression inclusive_OR_expression logical_AND_expression logical_OR_expression conditional_expression assignment_expression postfix_expression unary_expression cast_expression  expression_statement statement compound_statement selection_statement iteration_statement labeled_statement jump_statement block_item  block_item_list initializer M N
%type <intval> pointer
%type <types> type_specifier declaration_specifiers
%type <dec> direct_declarator declarator init_declarator
%type <dec_list> init_declarator_list
%type <p> parameter_declaration
%type <p_list> parameter_list parameter_type_list parameter_type_list_opt argument_expression_list argument_expression_list_opt

%start translation_unit

%%

primary_expression
    : IDENTIFIER {
        $$ = new expression(); 
        string s = *($1);
        current_symbol_table->lookup(s);
        $$->loc = s;
    }
    | constant {
        $$ = new expression() ; 
        $$->$1 ;
    }
    | STRING_LITERAL { 
        $$ = new expression() ; 
        $$->loc = ".LC" + to_string(string_count++) ;
        consts.push_back(*($1));
    }
    | ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE { $$ = $2 ; }
    ;

constant
    : INTEGER_CONSTANT {
        $$ = new expression() ;
        $$->loc = current_symbol_table->gentemp(INT);
        emit($$->loc,$1,ASSIGN);
        symbol_value* val = new symbol_value();
        val->set_value($1);
        current_symbol_table-lookup($$->loc)->initial_value = val;
    }
    | FLOATING_CONSTANT { 
        $$ = new expression() ;
        $$->loc = current_symbol_table->gentemp(FLOAT);
        emit($$->loc,$1,ASSIGN);
        symbol_value* val = new symbol_value();
        val->set_value($1);
        current_symbol_table-lookup($$->loc)->initial_value = val;
     }
    | CHAR_CONSTANT {
        $$ = new expression() ;
        $$->loc = current_symbol_table->gentemp(CHAR);
        emit($$->loc,$1,ASSIGN);
        symbol_value* val = new symbol_value();
        val->set_value($1);
        current_symbol_table-lookup($$->loc)->initial_value = val;
    }
    ;

postfix_expression
    : primary_expression {/* No Action Taken */}
    | postfix_expression SQUARE_BRACKET_OPEN expression SQUARE_BRACKET_CLOSE {
        symbol_type* t = current_symbol_table->lookup($1->loc)->type;
        string str = "" ;
        if(!($1->fold))
        {
            str = current_symbol_table->gentemp(INT);
            emit(str,0,ASSIGN);
            $1->folder = new string(str);
        }
        string temp = current_symbol_table->gentemp(INT);

        emit(temp,$3->loc,"",ASSIGN);
        emit(temp,temp,"4",MULTIPLY);
        emit(str,temp,"",ASSIGN);
        $$=$1;
    }
    | postfix_expression ROUND_BRACKET_OPEN ROUND_BRACKET_CLOSE 
    {
        // is for calling a function with no parameters
        symbol_table* table = global_symbol_table.lookup($1->loc)->nested_table;
        emit($1->loc,"0","",CALL);
    }
    | postfix_expression ROUND_BRACKET_OPEN argument_expression_list_opt ROUND_BRACKET_CLOSE { 
        // Corresponds to calling a function with the  function name and the appropriate number of parameters
        symbol_table* table = global_symbol_table.lookup($1->loc)->nested_table;
        vector<p> params = *($3);
        vector<symbol*> param_list = table->symbol_list;

        for(int i =0 ;i<(int)params.size();i++)
        {
            emit(params[i]->name,"","",PARAM);
        }

        data_type return_type = table->lookup("RETVAL")->type.type;       // making an entry to symbol table for the return value of the function
        if(return_type == VOID) emit($1->loc,(int)params.size(),CALL);
        else{
            string return_value = current_symbol_table->gentemp(return_type);
            emit($1->loc,to_string(params.size()),return_value,CALL);
            $$ = new expression();
            $$->loc = return_value;
        }
    }
    | postfix_expression DOT IDENTIFIER 
    { /* nothin */}
    | postfix_expression ARROW IDENTIFIER 
    { /* nothin */}
    | postfix_expression INCREMENT {
        $$ = new expression();
        symbol_type* t = current_symbol_table->lookup($1->loc)->type;
        if(t.type == ARR)
        {
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($1->loc)->type.nextType);
            emit($$->loc,$1->loc,*($1->folder),ARR_IDX_ARG);
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,$1->loc,*(1->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",PLUS);
            emit($1->loc,temp,*(1->folder),ARR_IDX_RES);
        }
        else 
        {
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($1->loc)->type.type);
            emit($$->loc,$1->loc,"",ASSIGN);
            emit($1->loc,$1->loc,"1",PLUS);
        }

    }
    | postfix_expression DECREMENT {
        $$ = new expression();
        $$->loc = ST->gentemp(ST->lookup($1->loc)->type.type);          // Generate a new temporary variable
        symbol_type* t = current_symbol_table->lookup($1->loc)->type;
        if(t.type == ARR)
        {
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($1->loc)->type.nextType);
            emit($$->loc,$1->loc,*($1->folder),ARR_IDX_ARG);
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,$1->loc,*(1->folder),ARR_IDX_ARG);
            emit($$->loc,temp,"",ASSIGN)
            emit(temp,temp,"1",MINUS);
            emit($1->loc,temp,*(1->folder),ARR_IDX_RES);
        }
        else 
        {
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($1->loc)->type.type);
            emit($$->loc,$1->loc,"",ASSIGN);
            emit($1->loc,$1->loc,"1",MINUS);
        }
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
        param* p = new param();
        p->name = $1->loc;
        p->type = current_symbol_table->lookup($1->loc)->type;
        $$ = new vector<param*>;
        $$->push_back(p);
    }
    | argument_expression_list COMMA assignment_expression { 
        param* p = new param();
        p->name = $3->loc;
        p->type = current_symbol_table->lookup(p->name)->type;
        $$ = $1;
        $$->push_back(p);
    }
    ;

unary_expression
    : postfix_expression {}
    | INCREMENT unary_expression {
        $$ = new expression();  
        symbol_type t = current_symbol_table->lookup($2->loc)->type;
        if(type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,$2->loc,*($2->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",PLUS);
            emit($2->loc,temp,*(2->folder),ARR_IDX_RES);
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($2->loc)->type.nextType);
        }
        else{
            emit($2->loc,$2->loc,"1",PLUS);
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($2->loc)->type.type);
        }
        $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($2->loc)->type.type);
        emit($$->loc,$2->loc,"",ASSIGN);
    }
    | DECREMENT unary_expression {
        $$ = new expression();
        symbol_type t = current_symbol_table->lookup($2->loc)->type;
        if(tyoe.type == ARR)
        {
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,$2->loc,*($2->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",MINUS);
            emit($2->loc,temp,*(2->folder),ARR_IDX_RES);
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($2->loc)->type.nextType);
        }
        else 
        {
            emit($2->loc,$2->loc,"1",MINUS);
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($2->loc)->type.type);
        }
        emit($$->loc,$2->loc,"",ASSIGN);
    }
    | unary_operator cast_expression {
        switch($1)
        {
            case '&' :          // address 
                $$ = new expression();
                $$->loc = current_symbol_table->gentemp(PTR);
                emit($$->loc,$2->loc,"",REFERENCE);
                break;
            
            case '*' :          // dereference
                $$ = new expression();
                $$->loc = current_symbol_table->gentemp(INT);
                $$->fold = 1;
                $$->folder = new string($2->loc);
                emit($$->loc,$2->loc,"",DEREFERENCE);
                break;
            
            case '-' :
                $$= new expression();
                $$->loc = current_symbol_table->gentemp();
                emit($$->loc,$2->loc,"",UMINUS);
                break;

            
            case '!' :
                $$ = new expression();
                $$->loc = current_symbol_table->gentemp(INT);
                int temp = nextinstr + 2;
                emit(to_string(temp),$2->loc,"0",GOTO_EQ);
                temp = nextinstr + 3;
                emit(to_string(temp),"","",GOTO);
                emit($$->loc,"1","",ASSIGN);
                temp = nextinstr + 2;
                emit(to_string(temp),"","",GOTO);
                emit($$->loc,"0","",ASSIGN);
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
    : unary_expression { /* No Action Taken */ }
    | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE cast_expression { /* No Action Taken */ }
    ;

multiplicative_expression
    : cast_expression {
        $$ = new expression();
        symbol_type t = current_symbol_table->lookup($1->loc)->type;
        if(t.type = ARR)
        {
            string temp = current_symbol_table->gentemp(t.nextType);
            if($1->folder != NULL)
            {
                emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
                $1->loc = temp;
                $1->type = t.nextType;
                $$ = $1;
            }
            else 
            {
                $$ = $1;
            }
        }
        else 
        {
            $$ = $1;
        }
    }
    | multiplicative_expression MULTIPLY cast_expression {
        
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        // assign the result of the multiplication to a new temporary variable in the higher data type

        data_type result = ((s1.type.type > s2.type.type) ? s1.type.type : s2.type.type);
        $$->loc = current_symbol_table->gentemp(result);
        emit($$->loc,$1->loc,$3->loc,MULTIPLY);
    }
    | multiplicative_expression DIVIDE cast_expression {
        
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        // assign the result of the division to a new temporary variable in the higher data type
        data_type result = ((s1.type.type > s2.type.type) ? s1.type.type : s2.type.type);
        $$->loc = current_symbol_table->gentemp(result);
        emit($$->loc,$1->loc,$3->loc,DIVIDE);
    }
    | multiplicative_expression MODULO cast_expression {
        
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        // assign the result of the modulo to a new temporary variable in the higher data type
        data_type result = ((s1.type.type > s2.type.type) ? s1.type.type : s2.type.type);
        $$->loc = current_symbol_table->gentemp(result);
        emit($$->loc,$1->loc,$3->loc,MODULO);
    }
    ;

additive_expression
    : multiplicative_expression { /* No Action Taken */ }
    | additive_expression PLUS multiplicative_expression {

        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        // assign the result of the addition to a new temporary variable in the higher data type
        data_type result = ((s1.type.type > s2.type.type) ? s1.type.type : s2.type.type);
        $$->loc = current_symbol_table->gentemp(result);
        emit($$->loc,$1->loc,$3->loc,PLUS);
    }
    | additive_expression MINUS multiplicative_expression {
        
        
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        // assign the result of the subtraction to a new temporary variable in the higher data type
        data_type result = ((s1.type.type > s2.type.type) ? s1.type.type : s2.type.type);
        $$->loc = current_symbol_table->gentemp(result);
        emit($$->loc,$1->loc,$3->loc,MINUS);
    }
    ;

shift_expression
    : additive_expression { /* No Action Taken */ }
    | shift_expression LEFT_SHIFT additive_expression {
        
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        $$->loc = current_symbol_table->gentemp(s1.type.type);
        emit($$->loc,$1->loc,$3->loc,LEFT_SHIFT);
    }
    | shift_expression RIGHT_SHIFT additive_expression {
        
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        $$->loc = current_symbol_table->gentemp(s1.type.type);
        emit($$->loc,$1->loc,$3->loc,RIGHT_SHIFT);
    }
    ;

relational_expression
    : shift_expression { /* No Action Taken */ }
    | relational_expression LESS_THAN shift_expression
    {
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        $$ = new expression();
        $$->loc = current_symbol_table->gentemp();
        $$->type = BOOL;
        emit($$->loc,"1","",ASSIGN);
        $$->truelist = makelist(nextinstr);
        emit("",$1->loc,$3->loc,GOTO_LT);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);

    }
    | relational_expression GREATER_THAN shift_expression { 
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        $$ = new expression();
        $$->loc = current_symbol_table->gentemp();
        $$->type = BOOL;
        emit($$->loc,"1","",ASSIGN);
        $$->truelist = makelist(nextinstr);
        emit("",$1->loc,$3->loc,GOTO_GT);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);
    }
    | relational_expression LESS_THAN_EQUAL shift_expression {
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        $$ = new expression();
        $$->loc = current_symbol_table->gentemp();
        $$->type = BOOL;
        emit($$->loc,"1","",ASSIGN);
        $$->truelist = makelist(nextinstr);
        emit("",$1->loc,$3->loc,GOTO_LTE);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);

    }
    
    | relational_expression GREATER_THAN_EQUAL shift_expression 
    {
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        $$ = new expression();
        $$->loc = current_symbol_table->gentemp();
        $$->type = BOOL;
        emit($$->loc,"1","",ASSIGN);
        $$->truelist = makelist(nextinstr);
        emit("",$1->loc,$3->loc,GOTO_GTE);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);
    }
    
    ;

equality_expression
    : relational_expression { $$ = new expression() ;$$ = $1; }
    | equality_expression EQUAL relational_expression {
        
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        $$ = new expression();
        $$->loc = current_symbol_table->gentemp();
        $$->type = BOOL;
        emit($$->loc,"1","",ASSIGN);
        $$->truelist = makelist(nextinstr);
        emit("",$1->loc,$3->loc,GOTO_EQ);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);
    }
    | equality_expression NOT_EQUAL relational_expression {
        
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR)
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        $$ = new expression();
        $$->loc = current_symbol_table->gentemp();
        $$->type = BOOL;
        emit($$->loc,"1","",ASSIGN);
        $$->truelist = makelist(nextinstr);
        emit("",$1->loc,$3->loc,GOTO_NEQ);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(nextinstr);
        emit("", "", "", GOTO);
    }
    ;

AND_expression
    : equality_expression {}
    | AND_expression BITWISE_AND equality_expression { 
        
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        $$ = new expression();
        $$->loc = current_symbol_table->gentemp();
        emit($$->loc,$1->loc,$3->loc,BITWISE_AND);
    }
    ;

exclusive_OR_expression
    : AND_expression { $$ = $1; }
    | exclusive_OR_expression BITWISE_XOR AND_expression {
        
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        $$ = new expression();
        $$->loc = current_symbol_table->gentemp();
        emit($$->loc,$1->loc,$3->loc,BITWISE_XOR);
    }
    ;

inclusive_OR_expression
    : exclusive_OR_expression {new expression() ;$$ = $1;}
    | inclusive_OR_expression BITWISE_OR exclusive_OR_expression {
        
        $$ = new expression();
        symbol * s1 = current_symbol_table->lookup($1->loc);
        symbol * s2 = current_symbol_table->lookup($3->loc);

        if(s2->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s2->type.nextType);
            emit(temp,$3->loc,*($3->folder),ARR_IDX_ARG);
            $3->loc = temp;
            $3->type = s2->type.nextType;
        }
        if(s1->type.type == ARR) 
        {
            string temp = current_symbol_table->gentemp(s1->type.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            $1->loc = temp;
            $1->type = s1->type.nextType;
        }

        $$ = new expression();
        $$->loc = current_symbol_table->gentemp();
        emit($$->loc,$1->loc,$3->loc,BITWISE_OR);
    }
    ;

logical_AND_expression
    : inclusive_OR_expression {}
    | logical_AND_expression LOGICAL_AND M inclusive_OR_expression {
        
        /* 
            here we have made few changes to the grammar to incorporate non terminal M to handle backpatching
        */

        backpatch($1->truelist,$3->instruction);
        $$->falselist = merge($1->falselist,$4->falselist);
        $$->truelist = $4->truelist;
        $$->type = BOOL;
    }
    ;

logical_OR_expression
    : logical_AND_expression {}
    | logical_OR_expression LOGICAL_OR M logical_AND_expression {
        
        backpatch($1->falselist,$3->instruction);
        $$->truelist = merge($1->truelist,$4->truelist);
        $$->falselist = $4->falselist;
        $$->type = BOOL;
    }
    ;

// my part

conditional_expression
    : logical_OR_expression { /* No Action Taken */ }
    | logical_OR_expression N QUESTION_MARK M expression N COLON M conditional_expression {
        // add here
    }
    ;

M:  %empty
    {
        $$ = new expression();
        $$->instruction = next_instr;
    }
    ;

N:  %empty
    {
        $$ = new expression();
        $$->nextlist = makelist(next_instr);
        emit("", "", "", GOTO);
    }
    ;

assignment_expression
    : conditional_expression { /* No Action Taken */ }
    | unary_expression assignment_operator assignment_expression {
        symbol* s1 = sy
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
    : %empty
    { current_block_name = "for"; }
    ;

W
    : %empty
    { current_block_name = "while"; }
    ;

D
    : %empty
    { current_block_name = "do_while"; }
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