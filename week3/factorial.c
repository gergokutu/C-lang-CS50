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

// // my 1st
// int fact(int n)
// {
//   if (n == 1)
//   {
//     return 1;
//   }

//   return n * fact(n - 1);  
// }

// // shortest > 1 liner with ternary
int fact(int n)
{
  return n == 1 ? 1 : n * fact(n - 1);  
}

// // shorter
// int fact(int n)
// {
//   if (n == 1) return 1;
//   return n * fact(n - 1);  
// }

// // short
// int fact(int n)
// {
//   if (n == 1) return 1;
//   else return n * fact(n - 1);  
// }

// // // CS50
// int fact(int n)
// {
//   if (n == 1)
//   {
//     return 1;
//   }
//   else
//   {
//     return n * fact(n - 1);
//   }  
// }

// // another
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