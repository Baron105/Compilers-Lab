// Name - Barun Parua
// Roll Number - 21CS10014
// Assignment - 2

#include "myl.h"
#define BUFF 200

// function to print a string and return the number of characters printed
int printStr(char *s)
{
    // declare a counter variable
    int i = 0;

    // loop till the end of the string ie till '\0' is encountered
    while (s[i] != '\0') i++;
    
    // system call to print the string
    __asm__ __volatile__(       
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(s), "d"(i)
        );

    // return the number of characters printed
    return i;
}

// function to print an integer and return the number of characters printed
int printInt(int n)
{
    // declare a buffer to store the integer and some other auxiliary variables
    // zero is the ASCII value of '0' to make easier conversions
    char buff[BUFF]={'\0'}, zero = '0';
    int i = 0, j, k;

    // if the integer is 0, then print 0, consider this case separately
    if (n == 0) buff[i++] = zero;

    // for non zero integers adopting the get last digit and dividing number by 10 in each case is performed
    else
    {
        // if the integer is negative, then storing '-', incrementing counter and making the integer positive
        if (n < 0)
        {
            buff[i++] = '-';
            n = -n;
        }

        // get the last digit of the integer and store it in the buffer
        // repeat the process till the integer becomes 0
        while (n)
        {
            int dig = n % 10;
            buff[i++] = (char)(zero + dig);
            n /= 10;
        }

        // if the integer was negative, then the '-' is stored at the 0th index of the buffer
        if (buff[0] == '-') j = 1;
        else j = 0;

        // the number is stored in reverse order in the buffer, so reversing the number, using a temp variable to swap
        // k is the index of the last digit of the integer
        k = i - 1;
        while (j < k)
        {
            char temp = buff[j];
            buff[j++] = buff[k];
            buff[k--] = temp;
        }
    }

    // system call to print the integer
    __asm__ __volatile__(
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(buff), "d"(i)
        );
    
    // return the number of characters printed
    return i;
}

// function to print a floating point number and return the number of characters printed
int printFlt (float f)
{
    // declare a buffer to store the floating point number and some other auxiliary variables
    // zero is the ASCII value of '0' to make easier conversions
    char buff[BUFF]={'\0'}, zero = '0';
    int i = 0, j, k;

    // if the number is negative, then storing '-', incrementing counter and making the number positive
    if (f < 0)
    {
        buff[i++] = '-';
        f = -f;
    }

    // get the integral and fractional part (till 4 digits) of the floating point number
    int ip = (int)f;
    int fp = (int)((f - ip) * 10000);

    // handling the integral part = 0 case separately
    if (ip == 0) buff[i++] = zero;
    else
    {
        // for non zero integers adopting the get last digit and dividing number by 10 in each case is performed
        while (ip)
        {
            int dig = ip % 10;
            buff[i++] = (char)(zero + dig);
            ip /= 10;
        }
        
        // if the integer was negative, then the '-' is stored at the 0th index of the buffer
        // now accordingly, j and k are set to reverse the integer
        if (buff[0] == '-') j = 1;
        else j = 0;
        k = i - 1;

        // the number is stored in reverse order in the buffer, so reversing the number, using a temp variable to swap
        while (j < k)
        {
            char temp = buff[j];
            buff[j++] = buff[k];
            buff[k--] = temp;
        }
    }

    // storing the decimal point in the buffer
    buff[i++] = '.';
    // taking till 4 digits of the fractional part
    i += 4;

    // iterating for the fractional part till 4 digits
    int l = 0;
    while (l < 4)
    {
        // getting the last digit of the fractional part and storing it in the buffer
        buff[i - l - 1] = (char)(zero + fp % 10);
        fp /= 10;
        l++;
    }

    // system call to print the floating point number
    __asm__ __volatile__(
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(buff), "d"(i)
        );
    
    // return the number of characters printed
    return i;
}

// function to read an integer from the standard input and return whether the read was successful or not
// OK is returned if the read was successful, ERR otherwise
int readInt(int *n)
{
    // declare a buffer to store the integer and some other auxiliary variables
    char buff[BUFF]={'\0'};
    int i = 0, j;
    int neg = 0;

    // system call to read the integer from the standard input
    __asm__ __volatile__(
        "movl $0, %%eax \n\t"
        "movq $0, %%rdi \n\t"
        "syscall \n\t"
        : "=r"(j)
        : "S"(buff), "d"(BUFF)
    );

    // if the read was unsuccessful, then return ERR
    // first check if length of the string is <= 0, if yes, then return ERR
    if (j <= 0) return ERR;

    // check if the first symbol is a '-', '+' or a digit, if not, then return ERR
    if (buff[i] != '-' && buff[i] != '+' && (buff[i] < '0' || buff[i] > '9')) return ERR;

    // if the first symbol is a '-', then set neg to 1 and increment i
    // else if the first symbol is a '+', then increment i
    if (buff[i] == '-')
    {
        neg = 1;
        i++;
    }
    else if (buff[i] == '+') i++;

    // initialize the integer to 0
    int num = 0;

    // now iterate over the string till the end of the string or till a non digit character is encountered
    // if a non digit character is encountered, then return ERR
    // also the bound for integers is checked, number must lie between -2147483648 and 2147483647, if not, then return ERR

    while(buff[i]!=' '&&buff[i]!='\n'&&buff[i]!='\t'&&buff[i]!='\0')
    {
        // if the character is not a digit, then return ERR
        if (buff[i] < '0' || buff[i] > '9') return ERR;
        
        int dig = buff[i] - '0';

        // check if the number is within bounds, if not, then return ERR
        if (!neg && (num > 214748364 || (num == 214748364 && dig > 7))) return ERR;
        else if (neg && (num > 214748364 || (num == 214748364 && dig > 8))) return ERR;

        // update the integer
        num = num * 10 + dig;
        i++;
    }

    // if the integer was negative, then make it negative
    if (neg) num = -num;

    // store the integer in the pointer and return OK
    *n = (int)num;
    return OK;
}

// function to read a floating point number from the standard input and return whether the read was successful or not
// OK is returned if the read was successful, ERR otherwise
int readFlt(float *n)
{
    // declare a buffer to store the integer and some other auxiliary variables
    char buff[BUFF]={'\0'};
    int i = 0, j;
    int neg = 0;

    // system call to read the floating point number from the standard input
    __asm__ __volatile__(
        "movl $0, %%eax \n\t"
        "movq $0, %%rdi \n\t"
        "syscall \n\t"
        : "=r"(j)
        : "S"(buff), "d"(BUFF)
    );

    // if the read was unsuccessful, then return ERR
    // first check if length of the string is <= 0, if yes, then return ERR
    if (j <= 0) return ERR;

    // check if the first symbol is a '-', '+', '.' or a digit, if not, then return ERR
    if (buff[i] != '-' && buff[i] != '+' && buff[i] != '.' && (buff[i] < '0' || buff[i] > '9')) return ERR;

    // if the first symbol is a '-', then set neg to 1 and increment i
    // else if the first symbol is a '+', then increment i
    if (buff[i] == '-')
    {
        neg = 1;
        i++;
    }
    else if (buff[i] == '+') i++;

    // initialize the integer and fractional part to 0
    int ip = 0;
    double fp = 0.0;

    // now iterate over the string till the end of the string or till a non digit character is encountered
    // if a non digit character (except a single .) is encountered, then return ERR

    while(buff[i]!=' '&&buff[i]!='\n'&&buff[i]!='\t'&&buff[i]!='\0')
    {
        // if the character is not a digit or a '.', then return ERR
        if (buff[i] != '.' && (buff[i] < '0' || buff[i] > '9')) return ERR;
        
        // if a '.', then break the loop
        if (buff[i] == '.') break;

        int dig = buff[i] - '0';

        // check if the number is within bounds, if not, then return ERR
        if (!neg && (ip > 214748364 || (ip == 214748364 && dig > 7))) return ERR;
        else if (neg && (ip > 214748364 || (ip == 214748364 && dig > 8))) return ERR;

        // update the integer
        ip = ip * 10 + dig;
        i++;
    }

    // if a '.', then increment i
    if (buff[i] == '.') i++;

    // now iterate over the string till the end of the string or till a non digit character is encountered
    // if a non digit character is encountered, then return ERR

    // ad is the number of digits after the decimal point
    int l = 0, ad = 0;
    while(buff[i]!=' '&&buff[i]!='\n'&&buff[i]!='\t'&&buff[i]!='\0')
    {
        // if the character is not a digit, then return ERR
        if (buff[i] < '0' || buff[i] > '9') return ERR;
        
        int dig = buff[i] - '0';

        // check till 4 digits after the decimal point
        if (l < 4)
        {
            fp = fp * 10 + dig;
            l++;
            ad++;
        }
        i++;
    }

    // divide the fractional part by 10^ad to get the actual fractional part
    while (ad)
    {
        fp /= 10.0;
        ad--;
    }

    // store the floating point number in the pointer according to the sign
    // return OK
    if (neg) *n = (float)(-ip - fp);
    else *n = (float)(ip + fp);
    return OK;
}