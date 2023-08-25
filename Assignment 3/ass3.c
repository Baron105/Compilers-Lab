#include <stdio.h>

// macro definitions
#define KEYWORD 1
#define IDENTIFIER 2
#define INTEGER_CONSTANT 3
#define FLOATING_CONSTANT 4
#define CHAR_CONSTANT 5
#define STRING_LITERAL 6
#define PUNCTUATOR 7
#define MULTILINECOMMENT 8
#define SINGLELINECOMMENT 9

extern char *yytext;
extern int yylex();

int main()
{
    int token;
    while ((token = yylex()))
    {
        switch (token)
        {
        case KEYWORD:
            printf("<KEYWORD, %d, %s>\n", token, yytext);
            break;
        case IDENTIFIER:
            printf("<IDENTIFIER, %d, %s>\n", token, yytext);
            break;
        case INTEGER_CONSTANT:
            printf("<INTEGER_CONSTANT, %d, %s>\n", token, yytext);
            break;
        case FLOATING_CONSTANT:
            printf("<FLOATING_CONSTANT, %d, %s>\n", token, yytext);
            break;
        case CHAR_CONSTANT:
            printf("<CHAR_CONSTANT, %d, %s>\n", token, yytext);
            break;
        case STRING_LITERAL:
            printf("<STRING_LITERAL, %d, %s>\n", token, yytext);
            break;
        case PUNCTUATOR:
            printf("<PUNCTUATOR, %d, %s>\n", token, yytext);
            break;
        case MULTILINECOMMENT:
            printf("<MULTILINECOMMENT, %d, %s>\n", token, yytext);
            break;
        case SINGLELINECOMMENT:
            printf("<SINGLELINECOMMENT, %d, %s>\n", token, yytext);
            break;
        default:
            printf("<INVALID_TOKEN, %s>\n", yytext);
            break;
        }
    }
    return 0;
}