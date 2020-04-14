#include <stdio.h>

int main(void)
{
    char s[] = "EMMA";
    // Prints a string
    printf("1: %s\n", s);

    // Prints a string's address
    printf("2: %p\n", s);

    // Prints a string's address as well the addresses of its chars
    printf("\n3: \n");
    // In case of arrays > it prints the address of the first item
    // So s and &s[0] is the same!!!
    printf("%p\n", s);
    printf("%p\n\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("%p\n\n", &s[4]);

    // Prints a string's chars
    printf("\n4: \n");
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
    printf("%c\n", s[3]);

    // Prints a string's chars via pointer arithmetic
    printf("\n5: \n");
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));
    printf("%c\n\n", *(s+3));

    // Prints a string's address via pointer arithmetic
    // They are addresses right after each other
    printf("\n6: \n");
    printf("%p\n", s);
    printf("%p\n", (s+1));
    printf("%p\n", (s+2));
    printf("%p\n", (s+3));
}