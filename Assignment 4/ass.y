%{
    #include <stdio.h>
    extern int yylex();
    extern int yylineno;
    extern char* yytext;
    void yyerror(char* s);
}%

%union {
    int intval;
    float floatval;
    char charval;
    char* strval;
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

%token IDENTIFIER
%token <intval> INTEGER_CONSTANT
%token <floatval> FLOATING_CONSTANT
%token <charval> CHAR_CONSTANT
%token <strval> STRING_LITERAL

%token WS

%start translation_unit

%%

primary_expression
    : IDENTIFIER { printf("primary-expression -> identifier\n"); }
    | constant { printf("primary-expression -> constant\n"); }
    | STRING_LITERAL { printf("primary-expression -> string-literal\n"); }
    | ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE { printf("primary-expression -> ( expression )\n"); }
    ;

constant
    : INTEGER_CONSTANT { printf("constant -> integer-constant\n"); }
    | FLOATING_CONSTANT { printf("constant -> floating-constant\n"); }
    | CHAR_CONSTANT { printf("constant -> character-constant\n"); }
    ;

postfix_expression
    : primary_expression { printf("postfix-expression -> primary-expression\n"); }
    | postfix_expression SQUARE_BRACKET_OPEN expression SQUARE_BRACKET_CLOSE { printf("postfix-expression -> postfix-expression [ expression ]\n"); }
    | postfix_expression ROUND_BRACKET_OPEN ROUND_BRACKET_CLOSE { printf("postfix-expression -> postfix-expression ( )\n"); }
    | postfix_expression ROUND_BRACKET_OPEN argument_expression_list_opt ROUND_BRACKET_CLOSE { printf("postfix-expression -> postfix-expression ( argument-expression-list )\n"); }
    | postfix_expression DOT IDENTIFIER { printf("postfix-expression -> postfix-expression . identifier\n"); }
    | postfix_expression ARROW IDENTIFIER { printf("postfix-expression -> postfix-expression -> identifier\n"); }
    | postfix_expression INCREMENT { printf("postfix-expression -> postfix-expression ++\n"); }
    | postfix_expression DECREMENT { printf("postfix-expression -> postfix-expression --\n"); }
    | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE { printf("postfix-expression -> ( type-name ) { initializer-list }\n"); }
    | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE { printf("postfix-expression -> ( type-name ) { initializer-list , }\n"); }
    ;

argument_expression_list_opt

