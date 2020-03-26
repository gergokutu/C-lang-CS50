#include <stdio.h>

int main(void)
{
  int number;
  
  printf("Enter an integer number: ");
  scanf("%d", &number);

  if (number % 2 == 0)
  {
    printf("The ensured number: %d is even", number);
  }
  else
  {
    printf("The ensured number: %d is odd", number);
  }
  
  return 0;
}