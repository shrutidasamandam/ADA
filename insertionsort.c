// LAB 5 - Sort a given set of N integer elements using Insertion Sort technique and compute its time taken. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int a[], int n)
{
  int current,i,j;
  for(i=1; i<=n; i++)
  {
    current = a[i];
    j=i-1;
    while(j>=0 && a[j]>current)
    {
      a[j+1] = a[j];
      j--;
    }
      a[j+1] = current;
  }
}

void main()
{
  int num,i,j,a[10000];
  printf("\nEnter number of elements");
  scanf("%d",&num);
  for(int i=1; i<=num; i++)
  {
    a[i] = rand()%100;
    printf("\t%d",a[i]);
  }
  insertionsort(a,num);
  printf("\nSorted elementd: ");
  for(int i=1; i<=num; i++)
  {
    printf("\n%d",a[i]);
  }
}
    {
        printf("%d\t",a[i]);
    }
    printf("\nTime taken to sort %lu",c/CLOCKS_PER_SEC);
}
