#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int a[100],n;

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int selectionsort(int a[], int n)
{

  int i,j,min;
  for(i=0; i<n-1; i++)
  {
    min = i;
    for(j=i+1; j<n; j++)
    {
      if(a[j]<a[min])
      min = j;

      if(min!=i)
      swap(&a[min],&a[i]);
    }
  }
}

int main()
{
  clock_t start,end;

  printf("\nEnter number of elements: ");
  scanf("\n%d",&n);

  printf("\nRandom elements to be sorted: ");
  for(int i=0; i<n; i++)
  {
    a[i] = rand()%100;
    printf("\t%d",a[i]);
  }
  start = clock();
  selectionsort(a,n);
  end = clock();

  printf("\nRandom elements to be sorted: ");
  for(int i=0; i<n; i++)
  {
    printf("\t%d",a[i]);
  }
  printf("\nTime taken to sort is %f",(double)(end-start)/CLOCKS_PER_SEC);
}
