// Saves names and numbers to a CSV file
#include <stdio.h>
#include <string.h>

int main(void)
{
  // Open CSV file
  FILE *file = fopen("phonebook.csv", "a");
  if (!file)
  {
    return 1;
  }

  // Get name and number
  char name[100] = "Copy this";
  printf("Name: ");
  scanf("%s", name);

  char number[100] = "Copy this";
  printf("Phone number: ");
  scanf("%s", number);

  // Print to file
  fprintf(file, "%s,%s\n", name, number);

  // Close file
  fclose(file);
}