#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    // pass the address
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

// define that the arguments are pointers
// int *a connected to &x (by memory address)
// changing the value of a will change the value of x
// because they have the same memory address
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}