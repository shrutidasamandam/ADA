// LAB 8

/* Sort a given set of N integer elements using Merge Sort 
technique and compute its time taken. Run the program for different 
values of N and record the time taken to sort.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[],int l, int mid, int h)
{
    int b[1000000],i,j,k;
    i=l,j=mid+1,k=l;
    while(i<=mid && j<=h)
    {
        b[k++] = (a[i]<a[j]) ? a[i++] : a[j++];
    }
    while(i<=mid) b[k++] = a[i++];
    while(j<=h) b[k++] = a[j++];
    for(k=l; k<=h; k++) a[k] = b[k];
}

//writing merge sort function: divide array into 2 parts recursively

int mergeesort(int a[],int l, int h)
{
    int mid;
    if(l>=h)
    return -1;
    mid = (l+h)/2;
    mergeesort(a,l,mid); //left part of array
    mergeesort(a,mid+1,h); //right part of array
    merge(a,l,mid,h); 
}

int main()
{
    int a[100000],n,i;
    clock_t c;
    printf("\nEnter the size: ");
    scanf("%d",&n);
    printf("\n The elements before sorting ");
    for(i=0; i<n;i++)
    {
        a[i] = rand()%100;
        printf("%d\t",a[i]);
    }
    c = clock();
    mergeesort(a,0,n-1);
    c = c - clock();
    printf("\n The elements after sorting ");
    for(i=0; i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n Time taken is = %lu",c/CLOCKS_PER_SEC);
}
