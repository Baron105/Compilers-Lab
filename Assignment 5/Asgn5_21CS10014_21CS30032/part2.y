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
    | { /* No Action Taken */ }
    ;

declaration_specifiers
    : storage_class_specifier declaration_specifiers_opt { /* No Action Taken */ }
    | type_specifier declaration_specifiers_opt { /* No Action Taken */ }
    | type_qualifier declaration_specifiers_opt { /* No Action Taken */ }
    | function_specifier declaration_specifiers_opt { /* No Action Taken */ }
    ;

declaration_specifiers_opt
    : declaration_specifiers { /* No Action Taken */ }
    | { /* No Action Taken */ }
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
    | { /* No Action Taken */ }
    ;

enum_specifier
    : ENUM identifier_opt CURLY_BRACKET_OPEN enumerator_list CURLY_BRACKET_CLOSE { /* No Action Taken */ }
    | ENUM identifier_opt CURLY_BRACKET_OPEN enumerator_list COMMA CURLY_BRACKET_CLOSE { /* No Action Taken */ }
    | ENUM IDENTIFIER { /* No Action Taken */ }
    ;

identifier_opt 
    : IDENTIFIER { /* No Action Taken */ }
    | { /* No Action Taken */ }
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
        symbol_type* new = NULL;
        while(t->type == "arr")
        {
            new = t;
            t = t->ptr;
        }
        if (new == NULL)
        {
            int temp = atoi($3->loc->value.c_str());
            symbol_type* new_type = new symbol_type("arr", $1->type, temp);
            $$ = $1->update(new_type);
        }
        else
        {
            int temp = atoi($3->loc->value.c_str());
            new->ptr = new symbol_type("arr", t, temp);
            $$ = $1->update($1->type);
        }
    }
    | direct_declarator SQUARE_BRACKET_OPEN SQUARE_BRACKET_CLOSE
    {
        symbol_type* t = $1->type;
        symbol_type* new = NULL;
        while(t->type == "arr")
        {
            new = t;
            t = t->ptr;
        }
        if (new == NULL)
        {
            symbol_type* new_type = new symbol_type("arr", $1->type, 0);
            $$ = $1->update(new_type);
        }
        else
        {
            new->ptr = new symbol_type("arr", t, 0);
            $$ = $1->update($1->type);
        }
    }
    | direct_declarator ROUND_BRACKET_OPEN change_table parameter_type_list ROUND_BRACKET_CLOSE
    {
        current_symbol_table->name = $1->name;
        if ($1->type->type != "void")
        {
            symbol* new = current_symbol_table->lookup("return");
            new->update($1->type);
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
            symbol* new = current_symbol_table->lookup("return");
            new->update($1->type);
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
    | { /* No Action Taken */ }
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
    | { /* No Action Taken */ }
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
    | { $$ = new statement(); }
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
    : WHILE ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement { printf("iteration-statement -> while ( expression ) statement\n"); }
    | DO statement WHILE ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE SEMICOLON { printf("iteration-statement -> do statement while ( expression ) ;\n"); }
    | FOR ROUND_BRACKET_OPEN expression_opt SEMICOLON expression_opt SEMICOLON expression_opt ROUND_BRACKET_CLOSE statement { printf("iteration-statement -> for ( expression-opt ; expression-opt ; expression-opt ) statement\n"); }
    | FOR ROUND_BRACKET_OPEN declaration expression_opt SEMICOLON expression_opt ROUND_BRACKET_CLOSE statement { printf("iteration-statement -> for ( declaration expression-opt ; expression-opt ) statement\n"); }
    ;

F
    : { block_name = "for"; }
    ;

W
    : { block_name = "while"; }
    ;

D
    : { block_name = "do_while"; }
    ;

X
    : 
    {
        string new_ST = curent_symbol_table->name + "_" + block_name + "_" + to_string(symbol_table_counter++);
        symbol* new_symbol = curent_symbol_table->lookup(new_ST);
        new_symbol->nested_table = new symbol_table(new_ST);
        new_symbol->name = new_ST;
        new_symbol->nested_table->parent = curent_symbol_table;
        new_symbol->type = new symbol_type("block");
        current_symbol = new_symbol;
    }

change_table
    :
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
        curent_symbol_table->parent = global_symbol_table;
        symbol_table_counter = 0;
        switchTable(global_symbol_table);
    }
    ;

declaration_list_opt
    : declaration_list { /* No Action Taken */ }
    | { /* No Action Taken */ }
    ;

declaration_list
    : declaration { /* No Action Taken */ }
    | declaration_list declaration { /* No Action Taken */ }
    ;

%%

void yyerror(char* s) {
    // for error reporting
    printf("Error: %s\n", s);
    printf("Line: %d\n", yylineno);
    printf("Text: %s\n", yytext);
}