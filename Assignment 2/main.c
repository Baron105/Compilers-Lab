// Name - Barun Parua
// Roll Number - 21CS10014
// Assignment - 3

#include "myl.h"

int main()
{
    printStr("Welcome to the test program for Assignment 2!\n");
    printStr("Select an option:\n");
    printStr("Part 1: Checking printStr, printInt, printFlt\n");
    printStr("\n");
    printStr("Checking printStr\n");
    printStr("Name: Barun Parua\n");
    printStr("Roll Number: 21CS10014\n");
    printStr("Assignment: 3\n\n");

    printStr("Checking printInt\n");

    int ret;
    printStr("Printing -40: ");
    ret = printInt(-40);
    printStr("\n");
    printStr("Number of characters printed: ");
    printInt(ret);
    printStr("\n");

    printStr("Printing INT_MAX: ");
    ret = printInt(2147483647);
    printStr("\n");
    printStr("Number of characters printed: ");
    printInt(ret);
    printStr("\n");
    
    printStr("Printing 42 (the answer to life, the universe and everything): ");
    ret = printInt(42);
    printStr("\n");
    printStr("Number of characters printed: ");
    printInt(ret);
    printStr("\n");

    printStr("\n");
    printStr("Checking printFlt\n");

    printStr("Printing pi: ");
    ret = printFlt(3.1415926535);
    printStr("\n");
    printStr("Number of characters printed: ");
    printInt(ret);
    printStr("\n");

    printStr("Printing -273.15 (Absolute zero in Celsius): ");
    ret = printFlt(-273.15);
    printStr("\n");
    printStr("Number of characters printed: ");
    printInt(ret);
    printStr("\n");

    printStr("Printing e: ");
    ret = printFlt(2.718281828);
    printStr("\n");
    printStr("Number of characters printed: ");
    printInt(ret);
    printStr("\n");

    printStr("\n");
    printStr("Part 2: Checking readInt, readFlt\n");
    printStr("\n");
    int choice;
    int i;
    float f;
    printStr("This part will ask your choice of input type, then read the input and print it and the number of characters printed\n");
    printStr("1. Enter an integer and print it\n");
    printStr("2. Enter a float and print it\n");
    printStr("3. Exit\n");
    while(1)
    {
        printStr("\n");
        printStr("Enter your choice: ");
        ret = readInt(&choice);
        if(choice == 1)
        {
            printStr("Enter an integer: ");
            ret = readInt(&i);
            if(ret == ERR)
            {
                printStr("Invalid integer\n");
                continue;
            }
            printStr("The integer you entered is: ");
            ret = printInt(i);
            printStr("\n");
            printStr("Number of characters printed: ");
            printInt(ret);
            printStr("\n");
        }
        else if(choice == 2)
        {
            printStr("Enter a float: ");
            ret = readFlt(&f);
            if(ret == ERR)
            {
                printStr("Invalid float\n");
                continue;
            }
            printStr("The float you entered is: ");
            ret = printFlt(f);
            printStr("\n");
            printStr("Number of characters printed: ");
            printInt(ret);
            printStr("\n");
        }
        else if (choice == 3)
        {
            printStr("Exiting the program!\n");
            printStr("Thank you for using the test program!\n");
            break;
        }
        else 
        {
            printStr("Invalid choice\n");
        }
    }
    return 0;
}