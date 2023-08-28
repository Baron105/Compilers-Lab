#include <stdio.h>

// macro definitions
#define SINGLELINE_COMMENT 1
#define MULTILINE_COMMENT 2
#define KEYWORD 3
#define IDENTIFIER 4
#define INTEGER_CONSTANT 5
#define FLOATING_CONSTANT 6
#define CHAR_CONSTANT 7
#define STRING_LITERAL 8
#define PUNCTUATOR 9

extern char *yytext;
extern int yylex();

int main()
{
    // read tokens from lex
    // while there are tokens
    int token;
    while ((token = yylex()))
    {
        // print token according to its type
        switch (token)
        {
        case SINGLELINE_COMMENT:
            printf("<SINGLELINE_COMMENT: %s , TOKEN: %d>\n", yytext, token);
            break;
        case MULTILINE_COMMENT:
            printf("<MULTILINE_COMMENT: %s , TOKEN: %d>\n", yytext, token);
            break;
        case KEYWORD:
            printf("<KEYWORD: %s , TOKEN: %d>\n", yytext, token);
            break;
        case IDENTIFIER:
            printf("<IDENTIFIER: %s , TOKEN: %d>\n", yytext, token);
            break;
        case INTEGER_CONSTANT:
            printf("<INTEGER_CONSTANT: %s , TOKEN: %d>\n", yytext, token);
            break;
        case FLOATING_CONSTANT:
            printf("<FLOATING_CONSTANT: %s , TOKEN: %d>\n", yytext, token);
            break;
        case CHAR_CONSTANT:
            printf("<CHAR_CONSTANT: %s , TOKEN: %d>\n", yytext, token);
            break;
        case STRING_LITERAL:
            printf("<STRING_LITERAL: %s , TOKEN: %d>\n", yytext, token);
            break;
        case PUNCTUATOR:
            printf("<PUNCTUATOR: %s , TOKEN: %d>\n", yytext, token);
            break;
        default:
            printf("<INVALID TOKEN: %s>\n", yytext);
            break;
        }
    }
    return 0;
}