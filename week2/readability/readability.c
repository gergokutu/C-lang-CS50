#include <stdio.h>
#include <string.h>
#include <math.h>

const int N = 100000;

int main(void)
{
    char paragraph[N];

    printf("Text: ");

    // accept a paragraph as input
    fgets(paragraph, N, stdin);
    printf("\n************\n\n");
    printf("The ensured paragraph is:\n\n%s\n", paragraph);

    // count the letters, words and sentences in the paragraph
    // think about the ASCII codes!
    int letters = 0;
    // words start from zero => Hey! or hey
    // 1 word but not a sentence
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(paragraph); i++)
    {
        // letters
        if (paragraph[i] >= 'a' && paragraph[i] <= 'z')
        {
            letters++;
        }
        if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
        {
            letters++;
        }
        // words
        if (paragraph[i] == ' ')
        {
            words++;
        }
        // sentences
        if ((paragraph[i] == '.' || paragraph[i] == '!' || paragraph[i] == '?')
            && paragraph[i - 1] != '.'
            && paragraph[i - 1] != '!'
            && paragraph[i - 1] != '?')
        {
            sentences++;
        }
    }

    // User feedback about the details
    printf("************\n\n");
    printf("Results: \n");
    printf("Letters: %d\n", letters);
    printf("Words: %d\n", words);
    printf("Sentences: %d\n\n", sentences);

    // apply the Coleman-Liau index
    float L = letters * 100 / words;
    float S = sentences * 100 / words;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    printf("INDEX: %f\n", index);

    // round the result
    int grade = round(index);

    // ensure proper feedback on the index
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
        printf("GRADE %d\n", grade);
    }

    printf("\n************\n\n");

    return 0;
}