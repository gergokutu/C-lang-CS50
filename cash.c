#include <stdio.h>
#include <math.h>
// #include <cs50.h>

int main()
{
  int cents;

  // ask user input >> nonnegative floating numbers
  do
  {
    float dollars;
    printf("Enter a number: ");
    scanf("%f", &dollars);
    // change the dollars to cent
    cents = round(dollars * 100);
  } while (cents <= 0);

  // define the minimum number of coins per type
  int quarters = cents / 25;
  int dimes = (cents % 25) / 10;
  int nickels = ((cents % 25) % 10) / 5;
  int pennies = ((cents % 25) % 10) % 5;

  // define the total minimum number of coins
  int num_of_coins = quarters + dimes + nickels + pennies;

  // print out the results
  printf("%d\n", num_of_coins);
}