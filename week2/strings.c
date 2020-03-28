// Prints string char by char, one per line, using strlen, remembering string's length
#include <stdio.h>
#include <string.h>

const int N = 10;

int main(void)
{
    char str[N];
    printf("Input: ");
    scanf("%s", str);

    printf("Output:\n\n");
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        printf("%c\n", str[i]);
    }
    printf(
      "\nThe null terminating character at the end of every string => %d at position: str[%d]!!!\n",
      str[strlen(str) + 1],
      (int) strlen(str) + 1);
}