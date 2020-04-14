#include <stdio.h>

int main(void)
{
    int n = 50;

    // Prints the integer itself
    printf("1: %d\n", n);

    // Prints an integer's address
    printf("2: %p\n", &n);

    // Prints an integer via its address
    // * reverse the affect of &
    // & > what is the address?
    // * > go to the address and get the value
    printf("3: %i\n", *&n);

    // Stores and prints an integer's address
    // Specify both the variable data type and that it's a pointer
    // Pointer p stores the address of n
    int *p = &n;
    printf("4: %p\n", p);
    // * > go to the address and get the value
    printf("5: %d\n", *p);
}