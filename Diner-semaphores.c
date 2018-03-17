#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int N;

int D[100] = {0};

void print()
{ printf("\nThe status of philosophers are: ");
  for(int i =0; i<N; i++)
  { if(D[i] == 0)
    printf("T ");
      else if(D[i] == 1)
      printf("H ");
        else if(D[i] == 2)
        printf("E ");
  }
}

void left(int pos)
{
  if(D[(pos-1)%N] == 1 && D[(pos-2)%N] != 2)
  {
    D[(pos-1)%N] = 2;
  }
}

void right(int pos)
{
  if(D[(pos+1)%N] == 1 && D[(pos+2)%N] != 2)
  {
    D[(pos+1)%N] = 2;
  }
}

void exec(int pos)
{
  if(D[pos] == 0)
  {   if(D[(pos-1)%N] !=2 && D[(pos+1)%N] != 2)
        D[pos] = 2;

      else
        D[pos] = 1;
  }

    else if(D[pos] == 2)
    {
      D[pos] = 0;
      left(pos);
      right(pos);
    }
}


int main()
{
  int t, pos;

  printf("\nEnter number of philosophers: ");
  scanf("%d", &N);
 printf("\nEnter number of iterations: ");
  scanf("%d", &t);

  printf("\nInitially: ");
  print();

  srand(time(NULL));

  for(int i = 1; i<=t; i++)
  {
    printf("\nAfter iteration %d: ", i);
    pos = rand() % N;
    exec(pos);
    print();
  }

  printf("\n");
  return 0;

commit 1;

}


