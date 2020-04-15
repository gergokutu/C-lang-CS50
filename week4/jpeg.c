// Detects if a file is a JPEG
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    // if (!file)
    if (file == NULL)
    {
        return 1;
    }

    // Read first three bytes
    // with unsigned > it's a num from 0 to 255
    unsigned char bytes[3];
    // 3 > read the first 3 bytes
    // 1 > read them 1 time
    fread(bytes, 3, 1, file);

    // Check first three bytes
    // Convention > every jpg starts with the following 3 numbers >
    // 0xff 0xd8 0xff
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("Maybe\n");
    }
    else
    {
        printf("No\n");
    }

    // Close file
    fclose(file);
}