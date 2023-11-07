// testing function and function calls 

int min(int a,int b);
int max(int a,int b);
int sum(int a,int b);
void find_max_min(int a,int b);

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

void find_max_min(int a, int b)
{
    int k = min(a,b);
    int l = max(a,b);
    return;
}

int main()
{
    int x = 3 ;
    int y = 5;

    int k = min(x,y);
    int l = max(x,y);
    int m = sum(x,y);

    find_max_min(x,y);
}