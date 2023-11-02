// testing arithmetic and logical operations

int a,b,c,d,e,f,g,h,i,j;

int main()
{
    int x = 3 ;
    int y = 5;

    if (x)
    {
        x = x + 1;
    }
    else
    {
        y = y + 1;
    } 
    a = x + y;
    b = x - y;
    c = x * y;
    d = x / y;
    e = x % y;
    f = x & y;
    g = x | y;
    h = x ^ y;
    i = x << y;
    j = x >> y;
}