#include <stdio.h>

int main(void)
{ 
  int number[] = {0, 1, 2};
  int n = 3;

  for (int i = 0; i < n; ++i)
  {
    printf("Before: %d\n", number[i]);
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = i + 1; j < n; ++j)
    {
      if (number[i] < number[j])
      {
        int a = number[i];
        number[i] = number[j];
        number[j] = a;
      }
    }
  }

  printf("The numbers arranged in descending order are given below\n");

  for (int i = 0; i < n; ++i)
  {
    printf("After: %d\n", number[i]);
  }

  return 0;
}
