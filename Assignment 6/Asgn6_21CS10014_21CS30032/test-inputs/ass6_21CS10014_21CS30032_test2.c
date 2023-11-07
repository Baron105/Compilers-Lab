// testing function and function calls

int printStr (char *ch);
int printInt (int n);
int readInt (int *eP);


int min(int a,int b);
int max(int a,int b);
int sum(int a,int b);

int min (int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int max (int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int sum (int a, int b)
{
    return a+b;
}

// testing nested function calls



int main()
{
    int x = 3 ;
    int y = 5;

    int k = min(x,y);
    int l = max(x,y);
    int m = sum(x,y);

    printStr("min = ");
    printInt(k);
    printStr("\n");
    return 0; }