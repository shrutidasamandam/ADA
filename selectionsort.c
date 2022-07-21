#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int selectionsort(int a[1000],int length)
{
  for(int i = 0; i < length - 1; i++)
    {
        int min_pos = i;
        for(int j = i+1; j<length; j++)
        {
            if(a[j] < a[min_pos])
            min_pos = j;
            
        if(min_pos!=i)
        {
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
        }
    }
    for(int i=0; i<length; i++)
    printf("a[%d]=%d\n",i,a[i]);
    return 0;
}

int main()
{
    int a[10000],length,k;
    clock_t c;
    printf("\nEnter length of array: ");
    scanf("%d",&length);
    printf("\nEnter elements of array");
    for(k=0; k<length; k++)
    {
      scanf("%d",&a[k]);
    }
    c = clock();
    selectionsort(a,length);
    c = c - clock();
    printf("\nTime taken to sort is = %ld",c/CLOCKS_PER_SEC);
    return 0;
}
