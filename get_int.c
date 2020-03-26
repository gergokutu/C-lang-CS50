#include <stdio.h>

int main(void)
{
  int number;

  printf("Enter a integer number: ");
  // do not forget the pointer > &!!!
  scanf("%d", &number);
  printf("The number you entered is %d.\n", number);

  return 0;
}