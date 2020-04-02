#include <stdio.h>

// accept a single command-line argument
int main(int argc, char **argv)
{
  // Check that program was run with one command-line argument
  if (argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  printf("Success\n");
  return 0;
}