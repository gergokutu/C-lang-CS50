// #include <cs50.h>
#include <stdio.h>

// int get_positive(void);
void build_pyramid(int height);

int main(void)
{
    // int height = get_positive();
    int height = 8;
    printf("Height: %i\n", height);
    build_pyramid(height);
}

// int get_positive(void)
// {
//     int number;
    
//     do
//     {
//        number = get_int("Ensure the height of thy pyramid /1-8/: ");
//     }
//     while ( number < 1 || number > 8 );
    
//     return number;
// }

void build_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {   
        for (int space = (height - i); space > 0; space--)
        {
            printf(" ");
        }
        for (int hash = 0; hash < i + 1; hash++)
        {
            printf("#"); // prints the hashtags
        }
        printf("\n");
    }
}