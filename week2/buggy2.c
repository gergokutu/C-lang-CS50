// Buggy example for printf
// to include debugging information to named executable >
// clang -g buggy2.c -o buggy2
// do not forget to set the path in launch.json > lldb part >
// "program": "${workspaceFolder}/_afterC/C/CS50/week2/buggy2",
// and you have to choose the correct configuration for debugging!!!
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        printf("#\n");
    }
}