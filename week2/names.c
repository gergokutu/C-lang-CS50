#include <stdio.h>
#include <string.h>

int main(void)
{
    // create an array of strings
    // actually its a 2D array of char!!!
    char names[4][10] =
    {
      "EMMA",
      "RODRIGO",
      "BRIAN",
      "DAVID"
    };

    // Print Emma's name
    printf("%s\n", names[0]);
    printf("%c%c%c%c\n", names[0][0], names[0][1], names[0][2], names[0][3]);
}