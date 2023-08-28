%{
    #include <stdio.h>
    #define SINGLELINE_COMMENT 1
    #define MULTILINE_COMMENT 2
    #define KEYWORD 3
    #define IDENTIFIER 4
    #define INTEGER_CONSTANT 5
    #define FLOATING_CONSTANT 6
    #define CHAR_CONSTANT 7
    #define STRING_LITERAL 8
    #define PUNCTUATOR 9
%}

/* comments */
SINGLELINE_COMMENT                  [/][/][^\n]*
ANY                                 ([^*]|[*][^/])*
MULTILINE_COMMENT                   [/][*]{ANY}*[*][/]

/* all keywords */
KEYWORD                             "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary"

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
ESCAPE_SEQUENCE                     "\'"|"\""|"\?"|"\\"|"\a"|"\b"|"\f"|"\n"|"\r"|"\t"|"\v"
C_CHAR                              [^("\'"|"\\"|"\n")]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE                     {C_CHAR}+
CHAR_CONSTANT                       "\'"{C_CHAR_SEQUENCE}"\'"

/* all constants */
CONSTANT                            {INTEGER_CONSTANT}|{FLOATING_CONSTANT}|{CHAR_CONSTANT}|{ENUMERATION_CONSTANT}

/* string literals */
S_CHAR                              [^("\""|"\\"|"\n")]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE                     {S_CHAR}+
STRING_LITERAL                      "\""{S_CHAR_SEQUENCE}"\""

/* punctuators */
PUNCTUATOR                          "["|"]"|"("|")"|"{"|"}"|","|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"+="|"-="|"*="|"/="|"%="|"&="|"^="|"|="|"<<="|">>="|","|"#"|"<<"|">>"

/* whitespaces */
WS                                  [ \t\n]
                   
/* return tokens */
%%

{SINGLELINE_COMMENT}                { return SINGLELINE_COMMENT; }
{MULTILINE_COMMENT}                 { return MULTILINE_COMMENT; }
{KEYWORD}                           { return KEYWORD; }
{IDENTIFIER}                        { return IDENTIFIER; }
{PUNCTUATOR}                        { return PUNCTUATOR; }
{INTEGER_CONSTANT}                  { return INTEGER_CONSTANT; }
{FLOATING_CONSTANT}                 { return FLOATING_CONSTANT; }
{CHAR_CONSTANT}                     { return CHAR_CONSTANT; }
{STRING_LITERAL}                    { return STRING_LITERAL; }

{WS}                                {/* ignore whitespace */}

%%
