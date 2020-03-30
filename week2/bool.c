// in C you need a header file to use bool
#include <stdbool.h>
#include <stdio.h>

bool valid_triangle(float x, float y, float z);

int main(void)
{
  // ask sides from user
  float side1, side2, side3;

  printf("Enter side 1: ");
  scanf("%f", &side1);

  printf("Enter side 2: ");
  scanf("%f", &side2);

  printf("Enter side 3: ");
  scanf("%f", &side3);

  printf("Side1: %.2f\nSide2: %.2f\nSide3: %.2f\n", side1, side2, side3);

  bool result = valid_triangle(side1, side2, side3);
  // notice the printf format specifier!!!
  printf("The ensured sides can result in a triangle => %s\n", result ? "true" : "false");

  return 0;
}

bool valid_triangle(float x, float y, float z)
{
  // only positive numbers ok for triangle sides
  if (x <= 0 || y <= 0 || z <= 0)
  {
    return false;
  }

  // add any of the two sides > should be greater than the 3rd
  if (x + y <= z || x + z <= y || y + z <= x)
  {
    return false;
  }

  // if ok it's a triangle
  return true;
}
