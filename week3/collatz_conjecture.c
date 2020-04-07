/* 
  So here's what the Collatz conjecture is >
  it applies to every positive integer.
  And it speculates that it's always possible to get back
  to 1 if you follow these steps:
    > If n is 1, stop (We've got back to 1 if n is 1).
    > Otherwise:
      > if n is even, go through this process again on n divided by 2.
        And see if you can get back to 1.
      > if n is odd, go through this process again on 3 times n plus 1.
*/

#include <stdio.h>

int collatz(int n);

int main(void)
{
  int number;
  printf("Enter a positive whole number: ");
  scanf("%d", &number);

  printf("From %d the num of neccessary steps to reach 1 are %d\n", number, collatz(number));

  return 0;
}

// int collatz(int n)
// {
//   // base case
//   if (n == 1)
//   {
//     return 0;
//   }
//   // multiple recursive cases
//   else if (n % 2 == 0)
//   {
//     return 1 + collatz(n / 2);
//   }
//   else
//   {
//     return 1 + collatz(3 * n + 1);
//   }
// }

// short
int collatz(int n)
{
  if (n == 1) return 0;
  return n % 2 == 0 ? 1 + collatz(n / 2) : 1 + collatz(3 * n + 1);
}