#include <stdio.h>

int fact(int n);

int main(void)
{
  int number;
  printf("Enter a positive whole number: ");
  scanf("%d", &number);

  printf("Factorial %d equals to %d\n", number, fact(number));
  return 0;
}

int fact(int n)
{
  if (n == 1)
  {
    return 1;
  }

  return n * fact(n - 1);  
}

// int fact(int n)
// {
//   if (n >= 1)
//   {
//     return n * fact(n - 1);
//   }
//   else
//   {
//     return 1;
//   }
// }