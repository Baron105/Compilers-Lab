%{
    #include <iostream>
    #include "ass6_21CS10014_21CS30032_translator.h"
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

%token AUTO BREAK CASE CHAR_T CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT_T FOR GOTO_T IF INLINE INT_T LONG REGISTER RESTRICT RETURN_T SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID_T VOLATILE WHILE BOOL_T COMPLEX IMAGINARY

%token SQUARE_BRACKET_OPEN SQUARE_BRACKET_CLOSE ROUND_BRACKET_OPEN ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN CURLY_BRACKET_CLOSE
%token DOT ARROW INCREMENT DECREMENT
%token BIT_AND BIT_OR BIT_XOR BITWISE_NOT
%token LOGICAL_AND LOGICAL_OR LOGICAL_NOT
%token MULTIPLY DIVIDE MODULO PLUS MINUS
%token LEFT_SHIFT RIGHT_SHIFT LESS_THAN GREATER_THAN LESS_THAN_EQUAL GREATER_THAN_EQUAL EQUAL NOT_EQUAL
%token ASSIGN_T PLUS_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN MODULO_ASSIGN LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN BIT_AND_ASSIGN BIT_XOR_ASSIGN BIT_OR_ASSIGN
%token COMMA COLON SEMICOLON ELLIPSIS QUESTION_MARK HASH

%token <intval> INTEGER_CONSTANT
%token <floatval> FLOATING_CONSTANT
%token <charval> CHAR_CONSTANT
%token <str> STRING_LITERAL
%token <str> IDENTIFIER

%token WS

%type <charval> unary_operator
%type <expr> expression primary_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression AND_expression exclusive_OR_expression inclusive_OR_expression logical_AND_expression logical_OR_expression conditional_expression assignment_expression postfix_expression unary_expression cast_expression  expression_statement statement compound_statement selection_statement iteration_statement labeled_statement jump_statement block_item  block_item_list initializer M N
%type <intval> pointer
%type <types> type_specifier declaration_specifiers
%type <dec> direct_declarator declarator init_declarator function_prototype
%type <dec_list> init_declarator_list
%type <p> parameter_declaration
%type <p_list> parameter_list parameter_type_list parameter_type_list_opt argument_expression_list

%expect 1
%nonassoc ELSE

%start translation_unit

%%

primary_expression
    : IDENTIFIER {
        $$ = new expression(); 
        string s = *($1);
        current_symbol_table->lookup(s);
        $$->loc = s;
    }
    | CHAR_CONSTANT
    {
        $$ = new expression() ;
        $$->loc = current_symbol_table->gentemp(CHAR);
        emit($$->loc,$1,ASSIGN);
        symbol_value* val = new symbol_value();
        val->set_value($1);
        current_symbol_table->lookup($$->loc)->initial_value = val;
    }
    | STRING_LITERAL { 
        $$ = new expression() ; 
        $$->loc = ".LC" + to_string(string_count++) ;
        consts.push_back(*($1));
    }
    | FLOATING_CONSTANT 
    { 
        $$ = new expression() ;
        $$->loc = current_symbol_table->gentemp(FLOAT);
        emit($$->loc,$1,ASSIGN);
        symbol_value* val = new symbol_value();
        val->set_value($1);
        current_symbol_table->lookup($$->loc)->initial_value = val;
    }
    | INTEGER_CONSTANT {
        $$ = new expression() ;
        $$->loc = current_symbol_table->gentemp(INT);
        emit($$->loc,$1,ASSIGN);
        symbol_value* val = new symbol_value();
        val->set_value($1);
        current_symbol_table->lookup($$->loc)->initial_value = val;
    }
    | ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE { $$ = $2 ; }
    ;

postfix_expression
    : primary_expression {/* No Action Taken */}
    | postfix_expression SQUARE_BRACKET_OPEN expression SQUARE_BRACKET_CLOSE {
        symbol_type t = current_symbol_table->lookup($1->loc)->type;
        string str = "" ;
        if(!($1->fold))
        {
            str = current_symbol_table->gentemp(INT);
            emit(str,0,ASSIGN);
            $1->folder = new string(str);
        }
        string temp = current_symbol_table->gentemp(INT);

        emit(temp,$3->loc,"",ASSIGN);
        emit(temp,temp,"4",MULT);
        emit(str,temp,"",ASSIGN);
        $$=$1;
    }
    | postfix_expression ROUND_BRACKET_OPEN ROUND_BRACKET_CLOSE 
    {
        // is for calling a function with no parameters
        symbol_table* table = global_symbol_table.lookup($1->loc)->nested_table;
        emit($1->loc,"0","",CALL);
    }
    | postfix_expression ROUND_BRACKET_OPEN argument_expression_list ROUND_BRACKET_CLOSE { 
        // Corresponds to calling a function with the  function name and the appropriate number of parameters
        symbol_table* table = global_symbol_table.lookup($1->loc)->nested_table;
        vector<param*> params = *($3);
        vector<symbol*> param_list = table->symbol_list;

        for(int i =0 ;i<params.size();i++)
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
    { /* No Action Taken */}
    | postfix_expression ARROW IDENTIFIER 
    { /* No Action Taken */}
    | postfix_expression INCREMENT {
        $$ = new expression();
        symbol_type t = current_symbol_table->lookup($1->loc)->type;
        if(t.type == ARR)
        {
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($1->loc)->type.nextType);
            emit($$->loc,$1->loc,*($1->folder),ARR_IDX_ARG);
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",ADD);
            emit($1->loc,temp,*($1->folder),ARR_IDX_RES);
        }
        else 
        {
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($1->loc)->type.type);
            emit($$->loc,$1->loc,"",ASSIGN);
            emit($1->loc,$1->loc,"1",ADD);
        }

    }
    | postfix_expression DECREMENT {
        $$ = new expression();
        $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($1->loc)->type.type);          // Generate a new temporary variable
        symbol_type t = current_symbol_table->lookup($1->loc)->type;
        if(t.type == ARR)
        {
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($1->loc)->type.nextType);
            emit($$->loc,$1->loc,*($1->folder),ARR_IDX_ARG);
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,$1->loc,*($1->folder),ARR_IDX_ARG);
            emit($$->loc,temp,"",ASSIGN);
            emit(temp,temp,"1",SUB);
            emit($1->loc,temp,*($1->folder),ARR_IDX_RES);
        }
        else 
        {
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($1->loc)->type.type);
            emit($$->loc,$1->loc,"",ASSIGN);
            emit($1->loc,$1->loc,"1",SUB);
        }
    }
    | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE 
    { /* No Action Taken */}
    | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE 
    { /* No Action Taken */}
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
        if(t.type == ARR)
        {
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,$2->loc,*($2->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",ADD);
            emit($2->loc,temp,*($2->folder),ARR_IDX_RES);
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($2->loc)->type.nextType);
        }
        else{
            emit($2->loc,$2->loc,"1",ADD);
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($2->loc)->type.type);
        }
        $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($2->loc)->type.type);
        emit($$->loc,$2->loc,"",ASSIGN);
    }
    | DECREMENT unary_expression {
        $$ = new expression();
        symbol_type t = current_symbol_table->lookup($2->loc)->type;
        if(t.type == ARR)
        {
            string temp = current_symbol_table->gentemp(t.nextType);
            emit(temp,$2->loc,*($2->folder),ARR_IDX_ARG);
            emit(temp,temp,"1",SUB);
            emit($2->loc,temp,*($2->folder),ARR_IDX_RES);
            $$->loc = current_symbol_table->gentemp(current_symbol_table->lookup($2->loc)->type.nextType);
        }
        else 
        {
            emit($2->loc,$2->loc,"1",SUB);
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
                emit($$->loc,$2->loc,"",UNARY_MINUS);
                break;

            
            case '!' :
                $$ = new expression();
                $$->loc = current_symbol_table->gentemp(INT);
                int temp = next_instr + 2;
                emit(to_string(temp),$2->loc,"0",GOTO_EQ);
                temp = next_instr + 3;
                emit(to_string(temp),"","",GOTO);
                emit($$->loc,"1","",ASSIGN);
                temp = next_instr + 2;
                emit(to_string(temp),"","",GOTO);
                emit($$->loc,"0","",ASSIGN);
                break;
        }
    }
    | SIZEOF unary_expression 
    { /* No Action Taken */}
    | SIZEOF ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE 
    { /* No Action Taken */}
    ;

unary_operator
    : BIT_AND { $$ = '&'; }
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

        data_type result = ((s1->type.type > s2->type.type) ? s1->type.type : s2->type.type);
        $$->loc = current_symbol_table->gentemp(result);
        emit($$->loc,$1->loc,$3->loc,MULT);
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
        data_type result = ((s1->type.type > s2->type.type) ? s1->type.type : s2->type.type);
        $$->loc = current_symbol_table->gentemp(result);
        emit($$->loc,$1->loc,$3->loc,DIV);
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
        data_type result = ((s1->type.type > s2->type.type) ? s1->type.type : s2->type.type);
        $$->loc = current_symbol_table->gentemp(result);
        emit($$->loc,$1->loc,$3->loc,MOD);
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
        data_type result = ((s1->type.type > s2->type.type) ? s1->type.type : s2->type.type);
        $$->loc = current_symbol_table->gentemp(result);
        emit($$->loc,$1->loc,$3->loc,ADD);
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
        data_type result = ((s1->type.type > s2->type.type) ? s1->type.type : s2->type.type);
        $$->loc = current_symbol_table->gentemp(result);
        emit($$->loc,$1->loc,$3->loc,SUB);
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

        $$->loc = current_symbol_table->gentemp(s1->type.type);
        emit($$->loc,$1->loc,$3->loc,SL);
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

        $$->loc = current_symbol_table->gentemp(s1->type.type);
        emit($$->loc,$1->loc,$3->loc,SR);
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
        $$->truelist = makelist(next_instr);
        emit("",$1->loc,$3->loc,GOTO_LT);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(next_instr);
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
        $$->truelist = makelist(next_instr);
        emit("",$1->loc,$3->loc,GOTO_GT);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(next_instr);
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
        $$->truelist = makelist(next_instr);
        emit("",$1->loc,$3->loc,GOTO_LTE);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(next_instr);
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
        $$->truelist = makelist(next_instr);
        emit("",$1->loc,$3->loc,GOTO_GTE);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(next_instr);
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
        $$->truelist = makelist(next_instr);
        emit("",$1->loc,$3->loc,GOTO_EQ);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(next_instr);
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
        $$->truelist = makelist(next_instr);
        emit("",$1->loc,$3->loc,GOTO_NEQ);
        emit($$->loc,"0","",ASSIGN);
        $$->falselist = makelist(next_instr);
        emit("", "", "", GOTO);
    }
    ;

AND_expression
    : equality_expression {}
    | AND_expression BIT_AND equality_expression { 
        
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
    | exclusive_OR_expression BIT_XOR AND_expression {
        
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
    : exclusive_OR_expression { $$=new expression() ;$$ = $1;}
    | inclusive_OR_expression BIT_OR exclusive_OR_expression {
        
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
    : logical_OR_expression { $$ = $1; }
    | logical_OR_expression N QUESTION_MARK M expression N COLON M conditional_expression {
        symbol* s1 = current_symbol_table->lookup($5->loc);
        $$->loc = current_symbol_table->gentemp(s1->type.type);
        $$->type = s1->type.type;

        emit($$->loc, $9->loc, "", ASSIGN);
        list<int> templist = makelist(next_instr);
        emit("", "", "", GOTO);
        backpatch($6->nextlist, next_instr);
        emit($$->loc, $5->loc, "", ASSIGN);
        list<int> temp = makelist(next_instr);
        templist = merge(templist, temp);
        emit("", "", "", GOTO);

        backpatch($2->nextlist, next_instr);
        inttobool($1);
        backpatch($1->truelist, $4->instruction);
        backpatch($1->falselist, $8->instruction);
        backpatch($2->nextlist, next_instr);

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
        symbol* s1 = current_symbol_table->lookup($1->loc);
        symbol* s2 = current_symbol_table->lookup($3->loc);
        if ($1->fold == 0)
        {
            if (s1->type.type != ARR) emit($1->loc, $3->loc, "", ASSIGN);
            else emit($1->loc, $3->loc, *($1->folder), ARR_IDX_RES);
        }
        else emit(*($1->folder), $3->loc, "", L_DEREF);

        $$ = $1;
    }
    ;

assignment_operator
    : ASSIGN_T
    { /* No Action Taken */}
    | MULTIPLY_ASSIGN 
    { /* No Action Taken */}
    | DIVIDE_ASSIGN 
    { /* No Action Taken */}
    | MODULO_ASSIGN 
    { /* No Action Taken */}
    | PLUS_ASSIGN 
    { /* No Action Taken */}
    | MINUS_ASSIGN 
    { /* No Action Taken */}
    | LEFT_SHIFT_ASSIGN 
    { /* No Action Taken */}
    | RIGHT_SHIFT_ASSIGN 
    { /* No Action Taken */}
    | BIT_AND_ASSIGN 
    { /* No Action Taken */}
    | BIT_XOR_ASSIGN 
    { /* No Action Taken */}
    | BIT_OR_ASSIGN 
    { /* No Action Taken */}
    ;

// my part

expression
    : assignment_expression { /* No Action Taken */ }
    | expression COMMA assignment_expression { /* No Action Taken */ }
    ;

constant_expression
    : conditional_expression { /* No Action Taken */ }
    ;


declaration
    : declaration_specifiers SEMICOLON { /* No Action Taken */ }
    | declaration_specifiers init_declarator_list SEMICOLON 
    {
        data_type curr_type = $1;
        int curr_size = -1;
        if (curr_type == INT) curr_size = SIZE_OF_INT;
        else if (curr_type == FLOAT) curr_size = SIZE_OF_FLOAT;
        else if (curr_type == CHAR) curr_size = SIZE_OF_CHAR;

        vector<declaration*> decl_list = *($2);
        for (vector<declaration*>::iterator it = decl_list.begin();it!=decl_list.end();it++)
        {
            declaration* curr_decl = *it;
            if (curr_decl->type == FUNC)
            {
                current_symbol_table = &global_symbol_table;
                emit(curr_decl->name, "", "", FUNC_END);
                symbol* s1 = current_symbol_table->lookup(curr_decl->name);
                symbol* s2 = s1->nested_table->lookup("RETVAL", curr_type, curr_decl->ptrs);
                s1->size = 0;
                s1->initial_value = NULL;
                continue ;
            }

            symbol* s3 = current_symbol_table->lookup(curr_decl->name, curr_type);
            s3->nested_table = NULL;

            if(curr_decl->instr_list == vector<int>() && curr_decl->ptrs == 0)
            {
                s3->size = curr_size;
                s3->type.type = curr_type;
                if (curr_decl->initial_value)
                {
                    string rval = curr_decl->initial_value->loc;
                    emit(s3->name, rval, "", ASSIGN);
                    s3->initial_value = current_symbol_table->lookup(rval)->initial_value;
                }
                else s3->initial_value = NULL;
            }

            else if (curr_decl->instr_list != vector<int>())
            {
                s3->type.type = ARR;
                s3->type.nextType = curr_type;
                s3->type.dimensions = curr_decl->instr_list;
                vector<int> temp = s3->type.dimensions;

                int temp_size = curr_size;
                for (int i = 0; i < temp.size(); i++)
                {
                    temp_size *= temp[i];
                }
                current_symbol_table->offset += temp_size;
                s3->size = temp_size;
                current_symbol_table->offset -= 4;
            }

            else if (curr_decl->ptrs != 0)
            {
                s3->type.type = PTR;
                s3->type.nextType = curr_type;
                s3->type.ptr = curr_decl->ptrs;
                current_symbol_table->offset += (SIZE_OF_PTR - curr_size);
                s3->size = SIZE_OF_PTR;
            }
        }
    }
    ;

declaration_specifiers: 
        storage_class_specifier declaration_specifiers
        {}
        |storage_class_specifier
        {}
        | type_specifier declaration_specifiers
        {}
        | type_specifier
        {}
        | type_qualifier declaration_specifiers
        {}
        | type_qualifier
        {}
        | function_specifier declaration_specifiers
        {}
        | function_specifier
        {}
        ;

init_declarator_list 
    : init_declarator { 
        $$ = new vector<declaration*>;
        $$->push_back($1);
     }
    | init_declarator_list COMMA init_declarator {
        $1->push_back($3);
        $$ = $1;
    }
    ;

init_declarator
    : declarator 
    { 
        $$ = $1;
        $$->initial_value = NULL;
    }
    | declarator ASSIGN_T initializer
    {
        $$ = $1;
        $$->initial_value = $3;
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
    : VOID_T { $$ = VOID; }
    | CHAR_T { $$ = CHAR; }
    | SHORT { /* No Action Taken */ }
    | INT_T { $$ = INT; }
    | LONG { /* No Action Taken */ }
    | FLOAT_T { $$ = FLOAT; }
    | DOUBLE { /* No Action Taken */ }
    | SIGNED { /* No Action Taken */ }
    | UNSIGNED { /* No Action Taken */ }
    | BOOL_T { /* No Action Taken */ }
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
    | IDENTIFIER ASSIGN_T constant_expression { /* No Action Taken */ }
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
        $$ = $2;
        $$->ptrs = $1;
    }
    | direct_declarator
    {
        $$ = $1;
        $$->ptrs = 0;
    }
    ;

direct_declarator
    : IDENTIFIER
    {
        $$ = new declaration();
        $$->name = *($1);
    }
    | ROUND_BRACKET_OPEN declarator ROUND_BRACKET_CLOSE
    {
        /* No Action Taken */
    }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list_opt SQUARE_BRACKET_CLOSE
    {
        $1->type = ARR;
        $1->next_type = INT;
        $$ = $1;
        $$->instr_list.push_back(0); 
    }
    | direct_declarator SQUARE_BRACKET_OPEN STATIC type_qualifier_list_opt assignment_expression SQUARE_BRACKET_CLOSE
    {
        /* No Action Taken */
    }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list STATIC assignment_expression SQUARE_BRACKET_CLOSE
    {
        /* No Action Taken */
    }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list_opt assignment_expression SQUARE_BRACKET_CLOSE
    {
        $1->type = ARR;
        $1->next_type = INT;
        $$ = $1;
        int id = current_symbol_table->lookup($4->loc)->initial_value->int_val;
        $$->instr_list.push_back(id);
        // check
    }
    | direct_declarator ROUND_BRACKET_OPEN parameter_type_list_opt ROUND_BRACKET_CLOSE
    {
        $$ = $1;
        $$->type = FUNC;
        symbol* s1 = current_symbol_table->lookup($$->name, $$->type);
        symbol_table* st = new symbol_table();
        s1->nested_table = st;

        vector<param*> param_list = *($3);
        for (int i = 0; i < param_list.size(); i++)
        {
            param* curr_param = param_list[i];
            
            if (curr_param->type.type == ARR)
            {
                st->lookup(curr_param->name, curr_param->type.type);
                st->lookup(curr_param->name)->type.nextType = INT;
                st->lookup(curr_param->name)->type.dimensions.push_back(0);
            }
            
            else if (curr_param->type.type == PTR)
            {
                st->lookup(curr_param->name, curr_param->type.type);
                st->lookup(curr_param->name)->type.nextType = INT;
                st->lookup(curr_param->name)->type.dimensions.push_back(0);
            }
            
            else
            {
                st->lookup(curr_param->name, curr_param->type.type);
            }
        }

        current_symbol_table = st;
        emit($1->name, "", "", FUNC_BEG);
    }
    | direct_declarator ROUND_BRACKET_OPEN identifier_list ROUND_BRACKET_CLOSE
    {
        /* No Action Taken */
    }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list_opt MULTIPLY SQUARE_BRACKET_CLOSE
    {
        $1->type = PTR;
        $1->next_type = INT;
        $$ = $1;
    }
    ;

parameter_type_list_opt:
        parameter_type_list
        {}
        | %empty
        {
            $$ = new vector<param*>;
        }
        ;
    


type_qualifier_list_opt
    : type_qualifier_list { /* No Action Taken */ }
    | %empty { /* No Action Taken */ }
    ;

pointer 
    : MULTIPLY type_qualifier_list { /* No Action Taken */ }
    | MULTIPLY type_qualifier_list pointer { /* No Action Taken */ }
    | MULTIPLY pointer { $$ = 1+$2; }
    | MULTIPLY { /* No Action Taken */ }
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
    : parameter_declaration 
    {
        $$ = new vector<param*>();
        $$->push_back($1);
    }
    | parameter_list COMMA parameter_declaration
    {
        $1->push_back($3);  
        $$ = $1;
    }
    ;

parameter_declaration
    : declaration_specifiers declarator 
    {
        $$ = new param();
        $$->name = $2->name;
        if ($2->type == ARR)
        {
            $$->type.type = ARR;
            $$->type.nextType = $1;
        }
        else if ($2->pc)
        {
            $$->type.type = PTR;
            $$->type.nextType = $1;
        }
        else
        {
            $$->type.type = $1;
        }
    }
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
    : assignment_expression { /* No Action Taken */ }
    | CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE { /* No Action Taken */ }
    | CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE { /* No Action Taken */ }
    ;

initializer_list
    : designation_opt initializer { /* No Action Taken */ }
    | initializer_list COMMA designation_opt initializer { /* No Action Taken */ }
    ;

designation_opt
    : designation { /* No Action Taken */ }
    | %empty { /* No Action Taken */ }
    ;

designation
    : designator_list ASSIGN_T { /* No Action Taken */ }
    ;

designator_list
    : designator { /* No Action Taken */ }
    | designator_list designator { /* No Action Taken */ }
    ;

designator
    : SQUARE_BRACKET_OPEN constant_expression SQUARE_BRACKET_CLOSE { /* No Action Taken */ }
    | DOT IDENTIFIER { /* No Action Taken */ }
    ;

statement
    : labeled_statement { /* No Action Taken */ }
    | compound_statement { /* No Action Taken */ }
    | expression_statement { /* No Action Taken */ }
    | selection_statement { /* No Action Taken */ }
    | iteration_statement { /* No Action Taken */ }
    | jump_statement { /* No Action Taken */ }
    ;

labeled_statement
    : IDENTIFIER COLON statement { /* No Action Taken */ }
    | CASE constant_expression COLON statement { /* No Action Taken */ }
    | DEFAULT COLON statement { /* No Action Taken */ }
    ;

compound_statement
    : CURLY_BRACKET_OPEN CURLY_BRACKET_CLOSE { /* No Action Taken */ }
    | CURLY_BRACKET_OPEN block_item_list CURLY_BRACKET_CLOSE { $$ = $2; }
    ;

block_item_list
    : block_item 
    { 
        $$ = $1; 
        backpatch($1->nextlist, next_instr);
    }
    | block_item_list M block_item
    {
        $$ = new expression();
        backpatch($1->nextlist, $2->instruction);
        $$->nextlist = $3->nextlist;
    }
    ;

block_item
    : declaration { $$ = new expression(); }
    | statement { /* No Action Taken */ }
    ;

expression_statement
    : expression SEMICOLON { /* No Action Taken */ }
    | SEMICOLON { $$ = new expression(); }

selection_statement
    : IF ROUND_BRACKET_OPEN expression N ROUND_BRACKET_CLOSE M statement N
    {
        backpatch($4->nextlist, next_instr);
        inttobool($3);
        $$ = new expression();
        backpatch($3->truelist, $6->instruction);

        $7->nextlist = merge($8->nextlist, $7->nextlist);
        $$->nextlist = merge($3->falselist, $7->nextlist);
    }
    | IF ROUND_BRACKET_OPEN expression N ROUND_BRACKET_CLOSE M statement N ELSE M statement N
    {
        backpatch($4->nextlist, next_instr);
        inttobool($3);
        $$ = new expression();
        backpatch($3->truelist, $6->instruction);
        backpatch($3->falselist, $10->instruction);

        $$->nextlist = merge($7->nextlist, $8->nextlist);
        $$->nextlist = merge($$->nextlist, $11->nextlist);
        $$->nextlist = merge($$->nextlist, $12->nextlist);
    }
    | SWITCH ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement { /* No Action Taken */ }
    ;

iteration_statement
    : WHILE M ROUND_BRACKET_OPEN expression N ROUND_BRACKET_CLOSE M statement
    {
        $$ = new expression();
        emit("", "", "", GOTO);
        backpatch(makelist(next_instr-1), $2->instruction);
        backpatch($5->nextlist, next_instr);
        inttobool($4);
        $$->nextlist = $4->falselist;
        backpatch($4->truelist, $7->instruction);
        backpatch($8->nextlist, $2->instruction);
    }
    | DO M statement M WHILE ROUND_BRACKET_OPEN expression N ROUND_BRACKET_CLOSE SEMICOLON
    {
        $$ = new expression();
        backpatch($8->nextlist, next_instr);
        inttobool($7);
        $$->nextlist = $7->falselist;
        backpatch($7->truelist, $2->instruction);
        backpatch($3->nextlist, $4->instruction);
    }
    | FOR ROUND_BRACKET_OPEN expression_statement M expression_statement N M expression N ROUND_BRACKET_CLOSE M statement
    {
        $$ = new expression();
        emit("", "", "", GOTO);
        auto temp = makelist(next_instr-1);
        $12->nextlist = merge($12->nextlist, temp);
        backpatch($12->nextlist, $7->instruction);
        backpatch($6->nextlist, next_instr);
        backpatch($9->nextlist, $4->instruction);
        inttobool($5);
        backpatch($5->truelist, $11->instruction);
        $$->nextlist = $5->falselist;
    }
    ;

jump_statement
    : GOTO_T IDENTIFIER SEMICOLON { /* No Action Taken */ }
    | CONTINUE SEMICOLON { /* No Action Taken */ }
    | BREAK SEMICOLON { /* No Action Taken */ }
    | RETURN_T SEMICOLON
    {
        if (current_symbol_table->lookup("RETVAL")->type.type == VOID) emit("", "", "", RETURN);
        $$ = new expression();
    }
    | RETURN_T expression SEMICOLON
    {
        if (current_symbol_table->lookup("RETVAL")->type.type == current_symbol_table->lookup($2->loc)->type.type) emit($2->loc, "", "", RETURN);
        $$ = new expression();
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
    : declaration_specifiers declarator declaration_list compound_statement { /* No Action Taken */ }
    | function_prototype compound_statement
    {
        current_symbol_table = &global_symbol_table;
        emit($1->name, "", "", FUNC_END);
    }
    ;

function_prototype
    : declaration_specifiers declarator
    {
        data_type temp = $1;
        int size = 0;
        if (temp == CHAR) size = SIZE_OF_CHAR;
        else if (temp == INT) size = SIZE_OF_INT;
        else if (temp == FLOAT) size = SIZE_OF_FLOAT;
        declaration* new1 = $2;
        symbol* new2 = current_symbol_table->lookup(new1->name);
        if (new1->type == FUNC)
        {
            symbol* return_value = new2->nested_table->lookup("RETVAL", temp, new1->ptrs);
            new2->size = 0;
            new2->initial_value = NULL;
        }
        $$ = $2;
    }

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