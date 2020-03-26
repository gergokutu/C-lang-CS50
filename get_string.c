#include <stdio.h>

int main(void)
{
  char name[20];

  printf("Enter name: ");
  scanf("%s", name);
  printf("Your name is %s.\n", name);

  return 0;
}