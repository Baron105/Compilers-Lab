#include "head.h"

int main()
{
    char str[100];
    int n,intl,fltl;
    printStr("Enter a string: ");
    intl = printInt(5);
    printStr("Number of characters printed: ");
    printInt(intl);
    fltl = printFlt(5.5);
    printStr("Number of characters printed: ");
    printInt(fltl);
    return 0;
}