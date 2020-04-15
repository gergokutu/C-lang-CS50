#include <stdio.h>

int main(void)
{
  int number = 50;
  int *pointer = &number;
  int **address_of_pointer = &pointer;

  printf("Number: %d\n", number);
  printf("Pointer: %p\n", pointer);
  printf("Address of the pointer: %p\n", address_of_pointer);
  printf("Value of the address_of_pointer: %p should be the same: %p\n", *address_of_pointer, pointer);

  return 0;
}