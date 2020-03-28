#include <stdio.h>

float average(int length, int array[]);

int main(void)
{ 
  int n;
  printf("How many scores do you want to input? ");
  scanf("%d", &n);

  int scores[n];
  for (int i = 0; i < n; i++)
  {
    printf("Enter your score: ");
    scanf("%d", &scores[i]);
  }

  printf("Average: %.2f\n", average(n, scores));

  // return 0;
}

float average(int length, int array[])
{
  int sum;
  for (int i = 0; i < length; i++)
  {
    sum += array[i];
  }

  return (float) sum / (float) length;
}