// Implements a phone book with structs
#include <stdio.h>
#include <string.h>

// create your own type > struct
typedef struct
{
  char name[11];
  char number[13];
} Person;

int main(void)
{
  Person People[4];

  // use strcpy() to fill the People array
  strcpy(People[0].name, "EMMA");
  strcpy(People[0].number, "617-555-0100");

  strcpy(People[1].name, "RODRIGO");
  strcpy(People[1].number, "617-555-0101");

  strcpy(People[2].name, "BRIAN");
  strcpy(People[2].number, "617-555-0102");

  strcpy(People[3].name, "DAVID");
  strcpy(People[3].number, "617-555-0103");

  int size = sizeof People / sizeof *People;
  printf("Size of People[]: %d\n", size);

  // Search for EMMA
  for (int i = 0; i < size; i++)
  {
    printf("Name: %s\n", People[i].name);

    if (strcmp(People[i].name, "BRIAN") == 0)
    {
      printf("Found %s\n", People[i].number);
      return 0;
    }
  }
  
  printf("Not found\n");
  return 1;
}
