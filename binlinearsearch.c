// LAB 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearsearch(int a[],int n, int key)
{
    if(n<0) return -1;
    else if (key == a[n-1]) return n-1;
    else return linearsearch(a,n-1,key);
}

int binarysearch(int a[], int low, int high, int key)
{
    int mid;
    mid = (low+high)/2;
    if(low>high) return -1;
    else if (key==a[mid]) return mid;
    else if (key<a[mid]) return binarysearch(a,low,mid-1,key);
    else return binarysearch(a,mid+1,high,key);
}

int main()
{
    int a[100000],pos,key,i,ch,n;
    clock_t c;
    printf("\nEnter number of elements");
    scanf("%d",&n);
    while(1)
    {
        printf("\n1.Linear Search \n2.Binary Search \n3.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nThe elements are: ");
            for(i=0; i<n; i++)
            {
                a[i]=rand()%100;
                printf("%2d\t",a[i]);
            }
            printf("\nEnter the search key");
            scanf("%d",&key);
            c = clock();
            pos = linearsearch(a,n,key);
            c = c-clock();
            if(pos<0)
            {
                printf("\nElement not found");
            }else {
                printf("\nElement found at position %d",pos+1);
            }
            printf("\nTime taken to search is = %ld",c/CLOCKS_PER_SEC);
            break;
            
            case 2: printf("\nThe elements are: ");
            for(i=0; i<n; i++)
            {
                a[i]=rand()%100;
                printf("%2d\t",a[i]);
            }
            printf("\nEnter the search key");
            scanf("%d",&key);
            c = clock();
            pos = binarysearch(a,0,n,key);
            c = c-clock();
            if(pos<0)
            {
                printf("\nElement not found");
            }else {
                printf("\nElement found at position %d",pos+1);
            }
            printf("\nTime taken to search is = %ld",c/CLOCKS_PER_SEC);
            break;
            
            case 3:
            printf("\nExiting");
            exit(0);
            break;
        }
    }
}
