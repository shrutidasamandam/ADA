// LAB 5 - Sort a given set of N integer elements using Insertion Sort technique and compute its time taken. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int a[],int n)
{
    int current,i,j;
    for(i=1;i<=n;i++)
    {
        current = a[i];
        j = i-1;
        while(j>=0 && a[j]>current)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=current;
    }
}

int main()
{
    int a[100000],n,i;
    clock_t c;
    printf("\n enter size of array");
    scanf("%d",&n);
    printf("\n elements before sorting");
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
        printf("%d\t",a[i]);
    }
    c = clock();
    insertion(a,n);
    c = c-clock();
    printf("\n elements after sorting");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nTime taken to sort %lu",c/CLOCKS_PER_SEC);
}
