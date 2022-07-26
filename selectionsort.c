#include <stdio.h>
  
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
  
void selectionsort(int list[], int size)
{
    int i, j, min;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        min = i;
        for (j = i+1; j < size; j++)
          if (list[j] < list[min])
            min = j;
  
        // Swap the found minimum element with the first element
        swap(&list[min], &list[i]);
    }
}
  
/* Function to print an array */
void printArray(int list[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", list[i]);
    printf("\n");
}
  
// Driver program to test above functions
int main()
{
    int size, list[25];

    printf("Enter the size of the list: ");
    scanf("%d",&size);

    printf("Enter the elements of the list: ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&list[i]);
    }
    
    selectionsort(list, size);
    printf("After selection sort: \n");
    printArray(list, size);
    return 0;
}
