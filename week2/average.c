#include <stdio.h>

// const naming convention is the capitalization
const int N = 3;

int main(void)
{
  int scores[N] = {72, 73, 33};

  // scores[0] = 72;
  // scores[1] = 73;
  // scores[2] = 33;

  // if the dividend or the divisor is cast to float that's enough to have a float as a result...
  printf("The average is %.2f\n", (float) (scores[0] + scores[1] + scores[2]) / (float) N );

  return 0;
}