#include <stdio.h>
#include <string.h>

int compare_strings(char arr1[], char arr2[]);

int main(void)
{
  char first[10], second[10];

  printf("First word: ");
  scanf("%s", first);

  printf("Second word: ");
  scanf("%s", second);

  printf("First word: %s and the second: %s\n", first, second);

  printf("\nMethod 1 > arr == arr\n");
  if (first == second)
  {
    printf("Same\n");
  }
  else
  {
    printf("With first == second it is always false because of different pointers!!!\n");
  }

  printf("\nMethod 2 > strcmp\n");
  if (strcmp(first, second) == 0)
  {
    printf("Same\n");
  }
  else
  {
    printf("Different\n");
  }

  printf("\nMethod 2 > without strcmp\n");
  if (compare_strings(first, second) == 1)
  {
    printf("Same\n");
  }
  else
  {
    printf("Different\n");
  }

  return 0;
}

int compare_strings(char arr1[], char arr2[])
{
  int i = 0, flag = 0;
  // Until at least one string ends > null terminating char
  while (arr1[i] != '\0' && arr2[i] != '\0')
  {
    // If they differ by a single character > don't iterate further
    // And set flag to 1
    if (arr1[i] != arr2[i])
    {
      flag = 1;
      break;
    }
    i++;
  }

  // If flag is 0 and both arr1 and arr2 reached the null terminating char
  // Return 1
  // If it's false > return 0
  if (flag == 0 && arr1[i] == '\0' && arr2[i] == '\0')
    return 1;
  else
    return 0;
}