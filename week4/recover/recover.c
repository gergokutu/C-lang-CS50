#include <stdio.h>
#include <stdlib.h>
// because of uint8_t
#include <stdint.h>

#define BUFFER_SIZE 512

// create a new type => BYTE
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check if the comment has proper num of args
    // return 1
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // open card.raw
    // if not ok > inform user
    // return 1
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        printf("The file cannot be opened.\n");
        return 1;
    }

    // create variable to the block (512 => FAT)
    // allocate memory for it
    BYTE *buffer = malloc(BUFFER_SIZE);
    // we need a file name
    char fileName[8];
    // track the number of jpeg files
    int counter = 0;
    // define a pointer to the jpg
    FILE *jpg = NULL;

    // repeat until end of file
    // read 512 bytes into the buffer
    while (fread(buffer, BUFFER_SIZE, 1, inputFile) == 1)
    {
        // if start of new JPG
        // use bitwise & for the 4th byte >
        // make the last 4bit of the 4th byte 0...
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // close previous jpg file if it exists
            if (counter > 0)
            {
                fclose(jpg);
            }

            // create filename
            sprintf(fileName, "%03d.jpg", counter);

            // open new image file
            jpg = fopen(fileName, "w");

            // check if jpg file is successfully created
            if (jpg == NULL)
            {
                printf("Image file cannot be created\n");
                fclose(inputFile);
                free(buffer);
                return 1;
            }

            // increase jpg file counter
            counter++;  
        }

        // write the picture into the file
        // if there is at least 1 file...
        if (counter > 0)
        {
          fwrite(buffer, BUFFER_SIZE, 1, jpg);
        }   
    }

    // close the files
    fclose(jpg);
    fclose(inputFile);
    printf("Files closed.\nSuccesful operation > check the recoverd images!\n");

    // free up the allocated memory
    free(buffer);

    return 0;
}
