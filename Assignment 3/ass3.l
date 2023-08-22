%{
    #include <stdio.h>
    #define KEYWORD 1
    #define IDENTIFIER 2
    #define INTEGER_CONSTANT 3
    #define FLOATING_CONSTANT 4
    #define CHAR_CONSTANT 5
    #define STRING_LITERAL 6
    #define PUNCTUATOR 7
    
%}

/* defining regular expressions */

KEYWORD                             "auto" | "break" | "case" | "char" | "const" | "continue" | "default" | "do" | "double" | "else" | "enum" | "extern" | "float" | "for" | "goto" | "if" | "inline" | "int" | "long" | "register" | "restrict" | "return" | "short" | "signed" | "sizeof" | "static" | "struct" | "switch" | "typedef" | "union" | "unsigned" | "void" | "volatile" | "while" | "_Bool" | "_Complex" | "_Imaginary"
IDENTIFIER                          [a-zA-Z_][a-zA-Z0-9_]*

/* Should 0 be included in INTEGER_CONSTANT ? */
INTEGER_CONSTANT                    [1-9][0-9]*                 

DIGIT_SEQUENCE                      [0-9]+
EXPONENT_PART                       [eE][+-]?{DIGIT_SEQUENCE}
FRACTIONAL_CONSTANT                 ({DIGIT_SEQUENCE}?\.{DIGIT_SEQUENCE} )| ({DIGIT_SEQUENCE}\.)
FLOATING_CONSTANT                   ({FRACTIONAL_CONSTANT}{EXPONENT_PART}?) | ({DIGIT_SEQUENCE}{EXPONENT_PART})

ENUMERATION_CONSTANT                {IDENTIFIER}

/* check if this is correct */
ESCAPE_SEQUENCE                     [\'\"?\\] | \\[abfnrtv]
C_CHAR                              [^\'\\\n]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE                     {C_CHAR}+
CHAR_CONSTANT                       \'({C_CHAR_SEQUENCE})\'


CONSTANT                            {INTEGER_CONSTANT} | {FLOATING_CONSTANT} | {CHAR_CONSTANT} | {ENUMERATION_CONSTANT}


S_CHAR                              [^\"\\\n]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE                     {S_CHAR}+
STRING_LITERAL                      \" ({S_CHAR_SEQUENCE}?)\"

PUNCTUATOR                          "[" | "]" | "(" | ")" | "{" | "}" | "." | "->" | "++" | "--" | "&" | "*" | "+" | "-" | "~" | "!" | "/" | "%" | "<<" | ">>" | "<" | ">" | "<=" | ">=" | "==" | "!=" | "^" | "|" | "&&" | "||" | "?" | ":" | ";" | "..." | "=" | "*=" | "/=" | "%=" | "+=" | "-=" | "<<=" | ">>=" | "&=" | "^=" | "|=" | "," | "#" 
WS                                  [ \t\n]

%%

{KEYWORD}                           {return KEYWORD;}
{IDENTIFIER}                        {return IDENTIFIER;}
{PUCTUATOR}                         {return PUNCTUATOR;}
{INTEGER_CONSTANT}                  {return INTEGER_CONSTANT;}
{FLOATING_CONSTANT}                 {return FLOATING_CONSTANT;}
{CHAR_CONSTANT}                     {return CHAR_CONSTANT;}
{STRING_LITERAL}                    {return STRING_LITERAL;}

{WS}                                {/* ignore whitespace */}




%%