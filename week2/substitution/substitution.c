#include <stdio.h>
#include <string.h>

// accept a single command-line argument
int main(int argc, char **argv)
{
  // Check that program was run with one command-line argument
  if (argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  // Check if the key is 26 char long
  char *key = argv[1];
  if (strlen(key) != 26)
  {
    printf("Usage: ./substitution key\nKey should be 26 characters long\n");
    return 1;
  }

  printf("Success\n");
  return 0;
}