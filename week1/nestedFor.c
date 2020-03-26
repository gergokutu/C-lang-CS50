#include <stdio.h>

int main(void)
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        printf("%d\n", k);
      }
      printf("level1\n");
    }
    printf("level0\n");
  }

  return 0;
}