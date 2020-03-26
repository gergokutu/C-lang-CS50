// Integer overflow
#include <stdio.h>
// nexessary because of sleep() function
#include <unistd.h>

int main(void)
{
    // Iteratively double i
    for (int i = 1; ; i *= 2)
    {
        printf("%i\n", i);
        sleep(1);
    }
}

// goes wrong after 1073741824