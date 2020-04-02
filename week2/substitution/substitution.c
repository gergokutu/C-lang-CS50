#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
  int key_length = strlen(key);
  if (key_length != 26)
  {
    printf("Usage: ./substitution key\nKey should be 26 characters long!\n");
    return 1;
  }

  // Check if the key consists of only letters - case-insensitive
  for (int i = 0; i < key_length; i++)
  {
    char letter = toupper(key[i]);
    if (letter < 'A' || letter > 'Z')
    {
      printf("Usage: ./substitution key\nKey should contain only letters!\n");
      return 1;
    }
  }

  // Check if the key does not consist of repeating characters
  for (int i = 0; i < key_length; i++)
  {
    for (int j = 1; j < key_length; j++)
    {
      // printf("key[i]: %c --- key[j]: %c\n", key[i], key[j]);
      // printf("I: %d --- J: %d\n", i, j);
      if ((toupper(key[i]) == toupper(key[j])) && i != j)
      {
        printf("Usage: ./substitution key\nKey should contain only unique letters!\n");
        return 1;
      }
    }
  }

  printf("Success\n");
  return 0;
}