#include <stdio.h>
// #include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int N = 1000;

// accept a single command-line argument
int main(int argc, char **argv)
{
  // Check that program was run with one command-line argument
  if (argc != 2)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  // Iterate over the provided argument to make sure all characters are digits
  char *key = argv[1];
  for (int i = 0; i < strlen(key); i++)
  {
    if (key[i] < '0' || key[i] > '9')
    {
      printf("Usage: ./caesar key\n");
      return 1;
    }
  }

  // Convert that command-line argument from a string to an int
  int key_num = atoi(key);
  // make sure its bigger than 0
  if (key_num < 1)
  {
    printf("Usage: ./caesar key\nKey should be bigger than 0!!!\n");
    return 1;
  }

  // Prompt user for plaintext
  printf("plaintext: ");
  char plaintext[N];
  fgets(plaintext, N, stdin);
  
  printf("ciphertext: ");

  // implement ciper algorithm
  // Iterate over each character of the plaintext:
  for (int i = 0; i < strlen(plaintext); i++)
  {
    // If it is an uppercase letter
    if (isupper(plaintext[i]))
    {
      // rotate to upper and print out the char
      printf("%c", ((plaintext[i] + key_num - 65) % 26) + 65);
    }
    // If it is a lowercase letter
    else if (islower(plaintext[i]))
    {
      // rotate to lower and print out the char
      printf("%c", ((plaintext[i] + key_num - 97) % 26) + 97);
    }
    // If it is neither
    else
    {
      // keep the char and print out
      printf("%c", plaintext[i]);
    }
  }
  return 0;
}