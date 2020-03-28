// Uppercases a string
// think about the ASCII codes
// 'A' is 32 before 'a'...

#include <stdio.h>
#include <string.h>

const int N = 10;

int main(void)
{
  char str[N];
  printf("Input: ");
  scanf("%s", str);

  printf("After:  ");
  for (int i = 0, n = strlen(str); i < n; i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      printf("%c", str[i] - 32);
    }
    else
    {
      printf("%c", str[i]);
    }
  }
  printf("\n");
}