// Name - Barun Parua
// Roll Number - 21CS10014
// Assignment - 3

#include "myl.h"
#define BUFF 500

// function to print a string and return the number of characters printed

int printStr(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    __asm__ __volatile__(
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(s), "d"(i)
        );
    return i;
}

// function to print an integer and return the number of characters/digits printed

int printInt(int n)
{
    char buff[BUFF], zero = '0';
    int i = 0, j, k, bytes;
    if (n == 0) buff[i++] = zero;
    else
    {
        if (n < 0)
        {
            buff[i++] = '-';
            n = -n;
        }
        while (n)
        {
            int dig = n % 10;
            buff[i++] = (char)(zero + dig);
            n /= 10;
        }
        if (buff[0] == '-') j = 1;
        else j = 0;
        k = i - 1;
        while (j < k)
        {
            char temp = buff[j];
            buff[j++] = buff[k];
            buff[k--] = temp;
        }
    }
    buff[i] = '\n';
    bytes = ++i;
    __asm__ __volatile__(
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(buff), "d"(bytes)
        );
    return bytes;
}

// function to print a float and return the number of characters printed

int printFlt (float n)
{
    char buff[BUFF], zero = '0';
    int i = 0, j, k, bytes;
    if (n < 0)
    {
        buff[i++] = '-';
        n = -n;
    }

    int intp = (int)n;
    int floatp = (int)((n - intp) * 10000);

    if (intp == 0) buff[i++] = zero;
    else
    {
        while (intp)
        {
            int dig = intp % 10;
            buff[i++] = (char)(zero + dig);
            intp /= 10;
        }

        if (buff[0] == '-') j = 1;
        else j = 0;
        k = i - 1;

        while (j < k)
        {
            char temp = buff[j];
            buff[j++] = buff[k];
            buff[k--] = temp;
        }
    }

    buff[i++] = '.';
    i+=4;

    int l = 0;
    while (l < 4)
    {
        buff[i - l - 1] = (char)(zero + floatp % 10);
        floatp /= 10;
        l++;
    }

    buff[i] = '\n';
    bytes = ++i;

    __asm__ __volatile__(
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(buff), "d"(bytes)
        );
    return bytes;
}