#include <stdio.h>

int LEFT_TO_RIGHT = 1;
int RIGHT_TO_LEFT = 0;

// finding position of largest mobile integer in a[]
int searcharray(int a[], int n, int mobile)
{
  for(int i=0; i<n; i++)
  if(a[i]==mobile)
  return i+1;
}

// finding largest largest movile integer
int getmobile(int a[], int dir[], int n)
{
  int mobile_prev=0, mobile=0;
  for(int i=0; i<n; i++)
  {
    // direction 0 is RIGHT TO LEFT ->
    if(dir[a[i]-1] == RIGHT_TO_LEFT && i!=0)
    {
      if(a[i]>a[i-1] && a[i] > mobile_prev)
      {
        mobile = a[i];
        mobile_prev = mobile;
      }
    }

    // direction 1 is LEFT to RIGHT
    if(dir[a[i]-1] == LEFT_TO_RIGHT && i!=n-1)
    {
      if(a[i]>a[i-1] && a[i]>mobile_prev)
      {
        mobile = a[i];
        mobile_prev = mobile;
      }
    }
  }
  if(mobile == 0 && mobile_prev == 0)
  return 0;
  else
  return mobile;
}

int printperm(int a[], int dir[], int n)
{
  int mobile = getmobile(a,dir,n);
  int pos = searcharray(a,n,mobile);

  // swapping elements inorder to direction
  if(dir[a[pos-1]-1] == RIGHT_TO_LEFT)
  {
    int temp;
    temp = a[pos-1];
    a[pos-1] = a[pos-2];
    a[pos-2] = temp;
  } else if (dir[a[pos-1]-1] == LEFT_TO_RIGHT)
  {
    int temp;
    temp = a[pos];
    a[pos] = a[pos-1];
    a[pos-1] = temp;
  }
  printf("\n");
  for(int i=0; i<n; i++)
  {
    if(a[i]>mobile)
    {
      if(dir[a[i]-1]== LEFT_TO_RIGHT)
      dir[a[i]-1] = RIGHT_TO_LEFT;
      else if (dir[a[i]-1] == RIGHT_TO_LEFT)
      dir[a[i]-1] = LEFT_TO_RIGHT;
    }
  }
  for(int i=0; i<n; i++)
  printf("%d",a[i]);
}

int factorial(int n)
{
  int res = 1;
  int i;
  for(i=1; i<=n; i++)
  {
    res = res * i;
  }
  return res;
}

void printallperm(int n)
{
  int a[n];
  int dir[n];
  for(int i=0; i<n; i++)
  {
    a[i] = i+1;
    printf("%d",a[i]);
  }
  for(int i=0; i<n; i++)
  dir[i] = RIGHT_TO_LEFT;
  for(int i=1; i<factorial(n); i++)
  printperm(a,dir,n);
}

int main()
{
  int n = 4;
  printallperm(n);
  return 0;
}
