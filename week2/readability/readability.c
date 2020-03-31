#include <stdio.h>
#include <string.h>
#include <math.h>

const int N = 100000;

char* get_string(void);
float counting(char *paragraph);
float calculate_index(int letters, int words, int sentences);
void print_grade(float grade);

int main(void)
{
  char *text = get_string();
  float grade = round(counting(text));
  print_grade(grade);
  return 0;
}

// ask user input > string
char* get_string(void)
{
  printf("Text: ");
  char string[N];
  // accept a text as input
  fgets(string, N, stdin);
  printf("\n************\n\n");
  printf("The ensured text is:\n\n%s\n", string);

  return string;
}

// count the letters, words and sentences in the paragraph
// think about the ASCII codes!
float counting(char *paragraph)
{
  int letters = 0;
  // words start from zero => Hey! or hey
  // 1 word but not a sentence
  int words = 1;
  int sentences = 0;

  for (int i = 0; i < strlen(paragraph); i++)
  {
    if ((paragraph[i] >= 'a' && paragraph[i] <= 'z') || (paragraph[i] >= 'A' && paragraph[i] <= 'Z'))
    {
      letters++;
    }
    else if (paragraph[i] == ' ')
    {
      words++;
    }
    else if (paragraph[i] == '.' || paragraph[i] == '!' || paragraph[i] == '?')
    {
      sentences++;
    }
  }

  // User feedback about the details
  printf("************\n\n");
  printf("RESULTS:\n\n");
  printf("Letters: %d\n", letters);
  printf("Words: %d\n", words);
  printf("Sentences: %d\n\n", sentences);

  return calculate_index(letters, words, sentences);
}

// apply the Coleman-Liau index
float calculate_index(int letters, int words, int sentences)
{
  float L = (float)letters * 100 / words;
  float S = (float)sentences * 100 / words;
  float index = 0.0588 * L - 0.296 * S - 15.8;

  printf("INDEX: %f\n", index);
  return index;
}

// // round the result
// float grade = round(index);

// ensure proper feedback on the index
void print_grade(float grade)
{
  if (grade < 1)
  {
    printf("Before GRADE 1\n");
  }
  else if (grade >= 16)
  {
    printf("GRADE 16+\n");
  }
  else
  {
    printf("GRADE %d\n", (int)grade);
  }

  printf("\n************\n\n");
}