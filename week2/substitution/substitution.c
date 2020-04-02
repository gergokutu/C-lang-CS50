#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const int N = 10000;
bool validate_key(char key[]);
char *prompt_plaintext(int length);
void print_ciphertext(char *plaintext, char *key);

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  if (!validate_key(argv[1]))
  {
    return 1;
  }

  char *plaintext = prompt_plaintext(N);
  print_ciphertext(plaintext, argv[1]);

  printf("\n");
  return 0;
}

bool validate_key(char key[])
{
  // Check if the key is 26 char long
  int key_length = strlen(key);
  if (key_length != 26)
  {
    printf("Usage: ./substitution key\nKey should be 26 characters long!\n");
    return 0;
  }

  // Check if the key consists of only letters - case-insensitive
  for (int i = 0; i < key_length; i++)
  {
    char letter = toupper(key[i]);
    if (letter < 'A' || letter > 'Z')
    {
      printf("Usage: ./substitution key\nKey should contain only letters!\n");
      return 0;
    }
  }

  // Check if the key does not consist of repeating characters
  for (int i = 0; i < key_length; i++)
  {
    for (int j = 1; j < key_length; j++)
    {
      if ((toupper(key[i]) == toupper(key[j])) && i != j)
      {
        printf("Usage: ./substitution key\nKey should contain only unique letters!\n");
        return 0;
      }
    }
  }

  return 1;
}

char *prompt_plaintext(int length)
{
  printf("plaintext: ");
  char text[N];
  fgets(text, N, stdin);

  return text;
}

void print_ciphertext(char *plaintext, char *key)
{
  printf("ciphertext: ");

  char *abc = "abcdefghijklmnopqrstuvwxyz";
  int plain_length = strlen(plaintext);
  char ciphertext[plain_length];

  // implement cipher algorithm
  // Iterate over each character of the plaintext:
  for (int i = 0; i < plain_length; i++)
  {
    // check for letters
    if (isalpha(plaintext[i]))
    {
      for (int j = 0; j < strlen(abc); j++)
      {
        if (tolower(plaintext[i]) == abc[j])
        {
          // make it case sensitive
          isupper(plaintext[i]) ? printf("%c", toupper(key[j])) : printf("%c", tolower(key[j]));
        }
      }
    }
    else
    {
      // if not a letter > just return the special char itself
      printf("%c", plaintext[i]);
    }
  }
}