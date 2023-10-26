// testing array and loops

// function to find average of elements of 2d array
int avg(int a[2][2])
{
    int sum = 0;
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            sum += a[i][j];
        }
    }
    return sum/4;
}

// using this function in main
int main()
{
    int a[2][2] ;

    // manually set the elements of array
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    

    int b = avg(a);
    return 0;
}