#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Here, we allocate enough memory to fit three integers, and our variable
    // list will point to the first integer.
    int *list = malloc(3 * sizeof(int));
    // We should check that we allocated memory correctly, since malloc might
    // fail to get us enough free memory.
    if (list == NULL)
    {
        return 1;
    }

    // With this syntax, the compiler will do pointer arithmetic for us, and
    // calculate the byte in memory that list[0], list[1], and list[2] maps to,
    // since integers are 4 bytes large.
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Now, if we want to resize our array to fit 4 integers, we'll try to allocate
    // enough memory for them, and temporarily use tmp to point to the first:
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        return 1;
    }

    // Now, we copy integers from the old array into the new array ...
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    // ... and add the fourth integer:
    tmp[3] = 4;

    // We should free the original memory for list, which is why we need a
    // temporary variable to point to the new array ...
    free(list);

    // ... and now we can set our list variable to point to the new array that
    // tmp points to:
    list = tmp;

    // Now, we can print the new array:
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // And finally, free the memory for the new array.
    free(list);
}