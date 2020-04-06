// Implements linear search for names
#include <stdio.h>
#include <string.h>

int main(void)
{
  // An array of names
  char *names[] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};

  // Search for EMMA
  for (int i = 0; i < 4; i++)
  {
    printf("Actual name: %s\n", names[i]);

    // use strcmp("first string", "second string")
    // to compare strings
    if (strcmp(names[i], "BRIAN") == 0)
    {
      printf("Found\n");
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}