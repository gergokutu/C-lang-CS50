#include <stdio.h>

int main(void)
{
  char c1 = 'H';
  char c2 = 'I';
  char c3 = '!';

  printf("%c %c %c\n", c1, c2, c3);

  // casting > force the datatype
  // handle c1, c2, c3 as int
  printf("\nH: %i\nI: %i\n!: %i\n\n", (int) c1, (int) c2, (int) c3);

  // if you do not cast the datatype it is done implicitly
  printf("%i %i %i\n", c1, c2, c3);

  return 0;
}
