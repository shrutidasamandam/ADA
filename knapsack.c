#include <stdio.h>

int max(int a, int b)
{
  if(a>b)
  return a;
  else
  return b;
}

int knapsack(int W, int wt[], int val[], int n)
{
  int i,w;
  int K[n+1][W+1];
  for(i=0; i<=n; i++)
  {
    for(w=0; w<=W; w++)
    {
      if(i==0 || w==0)
        K[i][w] = 0;
      else if(wt[i-1]<=w)
        K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
      else 
        K[i][w] = K[i-1][w];
    }
  }
  return K[n][W];
}

int main()
{
  int i,n,val[20],wt[20],W;
  printf("\nEnter number of items: ");
  scanf("%d",&n);
  printf("\nEnter value and weight of items: ");
  for(i=0; i<n; ++i){
    scanf("%d%d",&val[i],&wt[i]);
  }
  printf("\nEnter size of knapsack: ");
  scanf("%d",&W);
  printf("%d",knapsack(W,wt,val,n));
  return 0;
}
/*
Enter number of items: 3

Enter value and weight of items: 
100 20
50 10
150 30

Enter size of knapsack: 50
250

*/
