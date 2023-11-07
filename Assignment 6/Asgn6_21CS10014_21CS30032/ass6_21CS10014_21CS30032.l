%{
    #include <stdio.h>
    #include "ass6_21CS10014_21CS30032_translator.h"
    #include "ass6_21CS10014_21CS30032.tab.h"
%}

%option yylineno
%option noyywrap

/* comments */
SINGLELINE_COMMENT                  [/][/][^\n]*
ANY                                 ([^*]|[*][^/])*
MULTILINE_COMMENT                   [/][*]{ANY}*[*][/]

/* all keywords */
/* KEYWORD                             "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary" */

/* identifiers */
IDENTIFIER                          [a-zA-Z_][a-zA-Z0-9_]*

/* numeric constants */
INTEGER_CONSTANT                    [0]|[1-9][0-9]*                
DIGIT_SEQUENCE                      [0-9]+
EXPONENT_PART                       [eE][+-]?{DIGIT_SEQUENCE}
FRACTIONAL_CONSTANT                 ({DIGIT_SEQUENCE}?\.{DIGIT_SEQUENCE})|({DIGIT_SEQUENCE}\.)
FLOATING_CONSTANT                   ({FRACTIONAL_CONSTANT}{EXPONENT_PART}?)|({DIGIT_SEQUENCE}{EXPONENT_PART})

/* enumeration constants */
ENUMERATION_CONSTANT                {IDENTIFIER}

/* character constants */
/* check the escape sequences */
ESCAPE_SEQUENCE                     \\['"?\\abfnrtv]
C_CHAR                              [^\'\\\n]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE                     {C_CHAR}+
CHAR_CONSTANT                       \'{C_CHAR_SEQUENCE}\'

/* all constants */
CONSTANT                            {INTEGER_CONSTANT}|{FLOATING_CONSTANT}|{CHAR_CONSTANT}|{ENUMERATION_CONSTANT}

/* string literals */
S_CHAR                              [^\"\\\n]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE                     {S_CHAR}+
STRING_LITERAL                      \"{S_CHAR_SEQUENCE}\"


/* whitespaces */
WS                                  [ \t\n]
                   
/* return tokens */


%%

{SINGLELINE_COMMENT}                { }
{MULTILINE_COMMENT}                 { }

"auto"                              { return AUTO; }
"break"                             { return BREAK; }
"case"                              { return CASE; }
"char"                              { return CHAR_T; }
"const"                             { return CONST; }
"continue"                          { return CONTINUE; }
"default"                           { return DEFAULT; }
"do"                                { return DO; }
"double"                            { return DOUBLE; }
"else"                              { return ELSE; }
"enum"                              { return ENUM; }             
"extern"                            { return EXTERN; }
"float"                             { return FLOAT_T; }
"for"                               { return FOR; }
"goto"                              { return GOTO_T; }
"if"                                { return IF; }
"inline"                            { return INLINE; }
"int"                               { return INT_T; }
"long"                              { return LONG; }
"register"                          { return REGISTER; }
"restrict"                          { return RESTRICT; }
"return"                            { return RETURN_T; }
"short"                             { return SHORT; }
"signed"                            { return SIGNED; }
"sizeof"                            { return SIZEOF; }
"static"                            { return STATIC; }
"struct"                            { return STRUCT; }
"switch"                            { return SWITCH; }
"typedef"                           { return TYPEDEF; }
"union"                             { return UNION; }
"unsigned"                          { return UNSIGNED; }
"void"                              { return VOID_T; }
"volatile"                          { return VOLATILE; }
"while"                             { return WHILE; }
"_Bool"                             { return BOOL_T; }
"_Complex"                          { return COMPLEX; }
"_Imaginary"                        { return IMAGINARY; }

"["                                 { return SQUARE_BRACKET_OPEN; }
"]"                                 { return SQUARE_BRACKET_CLOSE; }
"("                                 { return ROUND_BRACKET_OPEN; }
")"                                 { return ROUND_BRACKET_CLOSE; }
"{"                                 { return CURLY_BRACKET_OPEN; }
"}"                                 { return CURLY_BRACKET_CLOSE; }
"."                                 { return DOT; }
"->"                                { return ARROW; }
"++"                                { return INCREMENT; }
"--"                                { return DECREMENT; }
"&"                                 { return BIT_AND; }
"*"                                 { return MULTIPLY; }
"+"                                 { return PLUS; }
"-"                                 { return MINUS; }
"~"                                 { return BITWISE_NOT; }
"!"                                 { return LOGICAL_NOT; }
"/"                                 { return DIVIDE; }
"%"                                 { return MODULO; }
"<<"                                { return LEFT_SHIFT; }
">>"                                { return RIGHT_SHIFT; }
"<"                                 { return LESS_THAN; }
">"                                 { return GREATER_THAN; }
"<="                                { return LESS_THAN_EQUAL; }
">="                                { return GREATER_THAN_EQUAL; }
"=="                                { return EQUAL; }
"!="                                { return NOT_EQUAL; }
"^"                                 { return BIT_XOR; }
"|"                                 { return BIT_OR; }
"&&"                                { return LOGICAL_AND; }
"||"                                { return LOGICAL_OR; }
"?"                                 { return QUESTION_MARK; }
":"                                 { return COLON; }
";"                                 { return SEMICOLON; }
"..."                               { return ELLIPSIS; }
"="                                 { return ASSIGN_T; }
"*="                                { return MULTIPLY_ASSIGN; }
"/="                                { return DIVIDE_ASSIGN; }
"%="                                { return MODULO_ASSIGN; }
"+="                                { return PLUS_ASSIGN; }
"-="                                { return MINUS_ASSIGN; }
"<<="                               { return LEFT_SHIFT_ASSIGN; }
">>="                               { return RIGHT_SHIFT_ASSIGN; }
"&="                                { return BIT_AND_ASSIGN; }
"^="                                { return BIT_XOR_ASSIGN; }
"|="                                { return BIT_OR_ASSIGN; }
","                                 { return COMMA; }
"#"                                 { return HASH; }


{IDENTIFIER}                        { yylval.str = new string(yytext); return IDENTIFIER; }

{INTEGER_CONSTANT}                  { yylval.intval = atoi(yytext); return INTEGER_CONSTANT; }
{FLOATING_CONSTANT}                 { yylval.floatval = atof(yytext); return FLOATING_CONSTANT; }

{CHAR_CONSTANT}                     { yylval.charval = yytext[0]; return CHAR_CONSTANT; }
{STRING_LITERAL}                    { yylval.str = new string(yytext); return STRING_LITERAL; }

{WS}                                {/* ignore whitespace */}

%%
