// Name - Barun Parua
// Roll Number - 21CS10014
// Assignment - 2

#include "myl.h"

int main()
{
    int ret;
    printStr("Welcome to the test program for Assignment 2!\n");
    printStr("\n\n");
    printStr("Part 1: Checking printStr, printInt, printFlt\n");
    printStr("\n");
    printStr("Checking printStr\n");
    ret = printStr("Name: Barun Parua");
    printStr("\n");
    printStr("Number of characters printed: ");
    printInt(ret);
    printStr("\n");
    ret = printStr("Roll Number: 21CS10014");
    printStr("\n");
    printStr("Number of characters printed: ");
    printInt(ret);
    printStr("\n");
    ret = printStr("Assignment: 2");
    printStr("\n");
    printStr("Number of characters printed: ");
    printInt(ret);
    printStr("\n");
    ret = printStr("abcdefghijklmnopqrstuvwxyz");
    printStr("\n");
    printStr("Number of characters printed: ");
    printInt(ret);
    printStr("\n\n");


    printStr("Checking printInt\n");

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
    printStr("Note: The precision of the float is set to 4 decimal places\n");

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
    printStr("3. Exit the program\n");
    printStr("Any other choice will be considered invalid and you will be asked to enter again\n");
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