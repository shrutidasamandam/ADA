// LAB 9

/*Sort a given set of N integer elements using Quick Sort technique and compute its time taken*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exch(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int part(int a[], int left, int right)
{
    int p,i,j;
    p = left;
    i = left;
    j = right;
    while (i<=j)
    {
        while(a[i]<=a[p])
        i++;
        while(a[j]>a[p])
        j--;
        exch(&a[i],&a[j]);
    }
    exch(&a[i],&a[j]);
    exch(&a[j],&a[p]);
    return j;
}

void quicksort(int a[], int left, int right)
{
    int s;
    if(left<right)
    {
        s = part(a,left,right);
        quicksort(a,left,s-1);
        quicksort(a,s+1,right);
    }
}

int main()
{
    int a[10000000],n,i;
    clock_t start, stop;
    printf("\nEnter the size of the array");
    scanf("%d",&n);
    printf("\nElements before sorting");
    for(i=0;i<n;i++)
    {
        a[i] = rand()%100;
        printf("%d\t",a[i]);
    }
    start = clock();
    quicksort(a,0,n);
    stop = clock();
    stop = stop-start;
    printf("\nElements after sorting");
      for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nTime taken = %ld",stop/CLOCKS_PER_SEC);
}
