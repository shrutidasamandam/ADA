// LAB 9

/*Sort a given set of N integer elements using Quick Sort technique and compute its time taken*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}



int partition(int array[],int low, int high)
{
  int pivot_index = low + (rand()%(high-low));
  if(pivot_index!=high)
  swap(&array[pivot_index],&array[high]);
  int pivot_value = array[high];
  int i = low;
  for (int j = low; j < high; j++)
  {
    if(array[j] <= pivot_value)
    {
      swap(&array[i],&array[j]);
      i++;
    }
  }
  swap(&array[i],&array[high]);
  return i;
}

void quicksort_recur(int array[],int low, int high)
{
  if(low<high)
  {
    int pivot_index = partition(array,low,high);
    quicksort_recur(array,low,pivot_index-1);
    quicksort_recur(array,pivot_index+1,high);
  }
}

void quicksort(int array[],int length)
{
  quicksort_recur(array,0,length-1);
}

int main()
{
  int k;
  // create a test array
  /*
  printf("\nEnter length of array");
  scanf("\n%d",&length);
  printf("\nEnter elements of array: ");
  for(k=1; k<length; k++)
  {
    scanf("%d\t",&a[k]);
  }
  */
  int a[] = {10,11,23,44,8,15,3,9,12,45,56,45,45};
  int length = 13;
  // use quicksort to sort the array
  quicksort(a, length);
  
  // print out the array to ensure it has been sorted
  for (int i = 0; i < length; i++)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}
