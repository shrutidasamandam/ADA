//LAB 1A

#include <stdio.h>

void towers(int,char,char,char);

int main()
{
  int num;
  printf("\nEnter number of disks");
  scanf("%d",&num);
  printf("\nThe sequence of moves involved in the Tower of Hanoi are: \n");
  towers(num,'A','C','B');
  return 0;
}

void towers(int num, char frompeg, char topeg, char auxpeg)
{
  if(num == 1)
  {
    printf("\nMove disk 1 from peg %c to %c",frompeg,topeg);
    return;
  }
  towers(num-1,frompeg,auxpeg,topeg);
  printf("\nMove disk %d from peg %c to %c",num,frompeg,topeg);
  towers(num-1,auxpeg,topeg,frompeg);
}
