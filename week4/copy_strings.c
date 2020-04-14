#include <stdio.h>
#include <string.h>
// for malloc
#include <stdlib.h>

int main(void)
{
  // Copy string without strcpy!!!
  char string[] = "Copy this";
  printf("Original string: ");
  scanf("%s", string);

  // Create another variable with the same memory size
  // Use malloc
  // Do not forget about the null terminating char!!!s
  char *copied = malloc(strlen(string) + 1);

  // loop over the string and copy each element 1 by 1
  // i < len + 1 - because of the null terminating char at the end!!!
  for (int i = 0, len = strlen(string); i < len + 1; i++)
  {
    // assign original chars to copied
    copied[i] = string[i];
  }

  printf("Copied string: %s\n", copied);
  return 0;
}