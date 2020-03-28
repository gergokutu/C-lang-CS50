// argc is an integer number that contains the number of parameters > 
// that were provided in the command line.
// argv is an array of strings
// argv[0] > the program
// argv[1] > first parameter
// try ./exit_argv & ./exit_argv <name>

#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Incorrect command line instruction! Syntax => ./argv_exit <name>\n");
    printf("argc => %d\n", argc);
    return 1;
  }
  else
  {
    printf("Hello %s!\n", argv[1]);
  }

  printf("argv[0] => %s\n", argv[0]);
  return 0;
}