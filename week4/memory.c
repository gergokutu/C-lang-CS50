// http://valgrind.org/docs/manual/quick-start.html#quick-start.prepare
#include <stdlib.h>
#include <stdio.h>

void f(void)
{
    int *x = malloc(10 * sizeof(int));
    // Not okay > x[10] excess our array size...
    // x[10] = 0;
    x[9] = 0;
    free(x);
}

int main(void)
{
    f();
    return 0;
}