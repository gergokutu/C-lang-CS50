#include <stdio.h>

int get_positive(void);
void build_staircase(int height);

int main(void)
{
  int height = get_positive();
  printf("Height: %i\n", height);
  build_staircase(height);
}

int get_positive(void)
{
  // Get input from user
  // int number;
  // printf("Ensure the height of thy staircase /1-8/: ");
  // scanf("%d", &number);
  int number;

  do
  {
    printf("Ensure the height of thy staircase /1-8/: ");
    scanf("%d", &number);
  }
  while ( number < 1 || number > 8 );

  return number;
}

void build_staircase(int height)
{
  for (int i = 0; i < height; i++)
  {
    for (int space = (height - i - 1); space > 0; space--)
    {
      printf(" ");
    }
    for (int hash = 0; hash < i + 1; hash++)
    {
      printf("#");
    }
    printf("\n");
  }
}