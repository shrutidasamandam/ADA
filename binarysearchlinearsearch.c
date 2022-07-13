#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void insertion_sort(int n,int array[])
{
    int item,i,j;
    for(i=1;i<n;i++)
    {
        item=array[i];
        j=i-1;
        while(item<array[j] && j>=0)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=item;
    }
}
void main()
{
    int a[10000],n,t,i;
    clock_t end,start;
    printf("Enter the number of array elements:\n");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
      a[i]=rand()%1000;
      printf("%d\n",a[i]);
    }
    start=clock();
    for(int j=0;j<5000000;j++)
        t=900/900;
    insertion_sort(n,a);
    printf("Sorted array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
     end=clock();
     printf("Time taken to search an given element in an array of is %f\n",(((double)(end-start))/CLOCKS_PER_SEC));
}
