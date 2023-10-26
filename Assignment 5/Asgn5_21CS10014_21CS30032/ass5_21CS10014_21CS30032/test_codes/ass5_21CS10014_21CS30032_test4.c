//testing pointers and arrays

// swap function with pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp; 
}

// bubble sort function
void bubble_sort(int a[], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                swap(&a[j+1],&a[j]);
            }
        }
    }
}

// main function
int main()
{
    int a[5];
    a[0] = 5;
    a[1] = 4;
    a[2] = 3;
    a[3] = 2;
    a[4] = 1;

    bubble_sort(a,5);
    return 0;
}