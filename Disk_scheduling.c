#include<stdio.h>
int a[100],N, max, prev, seek_time=0;
// commit 2
int abst(int a, int b)
{
  if(a>b)
  return(a-b);

  else
  return(b-a);
}

void bsort()
{ int temp, i,j;
  for(i =0; i<N; i++)
  for(j =0; j<N-i-1; j++)
    if(a[j+1]<a[j])
    {
      temp = a[j+1];
      a[j+1] = a[j];
      a[j] = temp;
    }
}

int search(int ele)
{
  for(int i = 0; i<N; i++)
  {
    if(a[i] == ele)
    return i;
  }
  return -1;
}

int main()
{
  printf("Enter the number of requests: ");
  scanf("%d", &N);

  printf("\nEnter the previous request: ");
  scanf("%d", &prev);

  printf("\nEnter the last request possible: ");
  scanf("%d", &max);

  printf("\nEnter the new requests: ");

  for(int i = 0; i< N; i++)
  scanf("%d", &a[i]);

  printf("\nThe result of FCFS is: \n");
  seek_time = 0;

  for(int i = 0; i<N-1; i++)
  seek_time += abst(a[i+1] , a[i]);

  printf("\nOrder of requests followed is: \n");

  for(int i = 0; i<N; i++)
  printf("%d ", a[i]);

  printf("\nThe total seek time is: %d", seek_time);

  printf("\n\nThe result of C-SCAN is: \n");

  int res = a[0];
  bsort();

  int dir;

  if(res > prev)
  dir = 1;

    else
    dir = 0;

   int pos = search(res), i;
   seek_time = 0;
  printf("\nOrder of requests followed is: \n");

  if(dir)
  { for(i=pos; i<N-1; i++)
    seek_time+= a[i+1] - a[i];

    if(pos != 0)
    { seek_time += (max - a[N-1]);
      seek_time += a[N-1] - a[0];
    }

    for(i=0; i<pos-1; i++)
      seek_time+= a[i+1] - a[i];

    for(i=pos; i<N; i++)
    printf("%d ", a[i]);

    for(i=0; i<pos; i++)
    printf("%d ", a[i]);
  }

  else
  {
    for(i=0; i<pos; i++)
    seek_time += a[i+1] - a[i];

    if(pos != N-1)
    {
      seek_time += a[0];
      seek_time += a[N-1];
    }

    for(i=pos+1; i<N-1; i++)
    seek_time += a[i+1] - a[i];

    for(i=pos; i>=0; i--)
    printf("%d ", a[i]);

    for(i=N-1; i>pos; i--)
    printf("%d ", a[i]);
  }

  printf("\nThe total seek time is: %d", seek_time);

  printf("\n\nThe result of LOOK is: \n");

  seek_time = 0;

  printf("\nOrder of requests followed is: \n");

  if(dir == 1)
  {
    for(i = pos; i<N-1; i++)
    seek_time += a[i+1] - a[i];

    seek_time += a[N-1] - a[0];

    for(i=pos; i<N; i++)
    printf("%d ", a[i]);

    for(i=pos-1; i>=0; i--)
    printf("%d ", a[i]);
  }
    else
    {
      for(i=0; i<pos; i++)
      seek_time += a[i+1] - a[i];

      seek_time += a[N-1] - a[0];

      for(i=pos; i>=0; i--)
      printf("%d ", a[i]);

      for(i=pos+1; i<N; i++)
      printf("%d ", a[i]);
    }

    printf("\nThe total seek time is: %d\n", seek_time);

  return 0;
}


