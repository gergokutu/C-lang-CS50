// Build pyramid
// Instead of nested for loop >
// Design it the recursive way
#include <stdio.h>

void draw(int h);

int main(void)
{
  int height;
  printf("Height: ");
  scanf("%d", &height);

  draw(height);
}

void draw(int h)
{
  // If nothing to draw > exit
  // base case, stop condition
  if (h == 0)
  {
    return;
  }

  // Draw pyramid with height - 1
  // recursion
  draw(h - 1);

  for (int i = 0; i < h; i++)
  {
    printf("#");
  }
  printf("\n");
}