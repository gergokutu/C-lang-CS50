#include <stdio.h>

int main(void)
{
  char paragraph[100000];

  printf("Enter your paragraph: ");
  // scanf("%s", paragraph);
  fgets(paragraph, 100000, stdin);

  printf("The ensured paragraph is:\n\n%s\n", paragraph);
  
  return 0;
}