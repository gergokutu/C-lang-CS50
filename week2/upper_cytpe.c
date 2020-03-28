// Uppercases string using ctype library

#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int N = 10;

// ver2
int main(void)
{
  char str[N];
  printf("Input: ");
  scanf("%s", str);

  printf("After:  ");
  for (int i = 0, n = strlen(str); i < n; i++)
  {
    // actually it works without the ver1 if statement
    // it applies to every char and
    // doesn't matter if it's capital or not...
    printf("%c", toupper(str[i]));
  }
  printf("\n");
}

// // ver 1
// int main(void)
// {
//   char str[N];
//   printf("Input: ");
//   scanf("%s", str);

//   printf("After:  ");
//   for (int i = 0, n = strlen(str); i < n; i++)
//   {
//     if (islower(str[i]))
//     {
//       printf("%c", toupper(str[i]));
//     }
//     else
//     {
//       printf("%c", str[i]);
//     }
//   }
//   printf("\n");
// }