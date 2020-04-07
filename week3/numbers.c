#include <stdio.h>

int main(void)
{
  int numbers[] = {4, 8, 15, 16, 23, 42, 50};
  int size = sizeof numbers / sizeof *numbers;
  // Or
  // int size = sizeof numbers / sizeof numbers[];
  
  printf("Size of numbers: %lu\n", sizeof numbers);
  printf("Size of *numbers: %lu\n", sizeof *numbers);
  printf("Size of the array: %d\n", size);

  // Search for 50
  for (int i = 0; i < size; i++)
  {
    printf("Actual number: %d\n", numbers[i]);

    if (numbers[i] == 50)
    {
      printf("Found\n");
      return 0;
    }
  }

  printf("Not found\n");
  return 1;
}