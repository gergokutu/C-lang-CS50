#include <stdio.h>
#include <string.h>

const int N = 100000;

int main(void)
{
  char paragraph[N];

  printf("Enter your paragraph: ");
  // scanf("%s", paragraph);
  // accept a paragraph as input
  fgets(paragraph, N, stdin);

  printf("The ensured paragraph is:\n\n%s\n", paragraph);

  // count the letters, words and sentences in the paragraph
  // think about the ASCII codes!
  int letters;
  // words start from zero => Hey! or hey
  // 1 word but not a sentence
  int words = 1;
  int sentences;

  for (int i = 0; i < strlen(paragraph); i++)
  {
    // letters
    if (paragraph[i] >= 'a' && paragraph[i] <= 'z') letters++;
    if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') letters++;

    // words
    if (paragraph[i] == ' ') words++;

    // sentences
    if ((paragraph[i] == '.' || paragraph[i] == '!' || paragraph[i] == '?') 
      && paragraph[i - 1] != '.' 
      && paragraph[i - 1] != '!' 
      && paragraph[i - 1] != '?') sentences++;
  }

  printf("Letters: %d\n", letters);
  printf("Words: %d\n", words);
  printf("Sentences: %d\n", sentences);
  
  return 0;
}