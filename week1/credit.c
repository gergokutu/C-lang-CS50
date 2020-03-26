#include <math.h>
#include <stdio.h>

int main(void)
{
    // Declare and initialize a variable for card number
    // long long >> card_number is a pretty high number
    long long card_number = 0;
    
    do
    {
      // ask input from user >> long long
      printf("What is your card number? ");
      scanf("%lld", &card_number);
    }
    while (card_number < 0);

    // Determine whether the card_number has a valid number of digits
    int count = 0;
    long long digits = card_number;
    
    // check the number of digits by dividing it by 10 in every iteration
    while (digits > 0)
    {
        digits = digits / 10;
        count++;
    }
    
    // if the card_number does not have any valid length
    if ((count != 13) && (count != 15) && (count != 16))
    {
        printf("INVALID\n");
    }
    
    // create an array of count length
    // where every item is a digit of the card_number
    int number[count];
    
    for (int i = 0; i < count; i++)
    {
        // get the last digit
        number[i] = card_number % 10;
        // move 1 digit left
        card_number = card_number / 10;
    }
    
    // save the original card_number into a separate array
    int original_number[count];
    
    for (int i = 1; i < count; i++)
    {
        original_number[i] = number[i];
    }
    
    // multiple every other digit by 2
    for (int i = 1; i < count; i += 2)
    {
        number[i] = number[i] * 2;
    }
    
    // check the card_number validity
    // and decide the type of the card (AMEX, VISA, MASTERCARD, INVALID)
    int sum = 0;
    int temp_sum;
    
    if (count == 13)
    {
        // sum the products' digits of numbers multiplied by two
        // and not multiplied by two
        for (int i = 0; i < count; i++)
        {
            temp_sum = (number[i] % 10) + (number[i] / 10 % 10);
            sum = sum + temp_sum;
        }
        
        // check the validity per the respective length and card type
        if (original_number[12] == 4 && sum % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    if (count == 15)
    {
        /// sum the products' digits of numbers multiplied by two
        // and not multiplied by two
        for (int i = 0; i < count; i++)
        {
            temp_sum = (number[i] % 10) + (number[i] / 10 % 10);
            sum = sum + temp_sum;
        }
        
        // check the validity per the respective length and card type
        if (original_number[14] == 3 && sum % 10 == 0 && (original_number[13] == 4 || original_number[13] == 7))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    if (count == 16)
    {
        // sum the products' digits of numbers multiplied by two
        // and not multiplied by two
        for (int i = 0; i < count; i++)
        {
            temp_sum = (number[i] % 10) + (number[i] / 10 % 10);
            sum = sum + temp_sum;
        }
        
        // check the validity per the respective length and card type
        if (original_number[15] == 4 && sum % 10 == 0)
        {
            printf("VISA\n");
        }
        else if (original_number[15] == 5 && sum % 10 == 0 && (original_number[14] == 1 || original_number[14] == 2
                 || original_number[14] == 3 || original_number[14] == 4 || original_number[14] == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
  
    return 0;
}
