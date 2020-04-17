#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbGray;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Count avg of red, green and blue
            rgbGray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.000);

            // Set each of rgb to the avg
            image[i][j].rgbtBlue = rgbGray;
            image[i][j].rgbtGreen = rgbGray;
            image[i][j].rgbtRed = rgbGray;
        }
    }
    return;
}

// Stops max value at 255 preventing overflow
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int sepiaRed, sepiaBlue, sepiaGreen;
        for (int j = 0; j < width; j++)
        {
            // Apply the algorithm on every pixel
            sepiaRed = limit(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            sepiaGreen = limit(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            sepiaBlue = limit(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));

            // Modify the original due to the filter
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int i = 0; i < height; i++)
    {
        // Just iterate until the half of the width
        // Not to reflect back the picture immediately
        for (int j = 0; j < width / 2; j++)
        {
            // Save the original last row into a temporary variable
            temp[0] = image[i][j].rgbtRed;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtBlue;

            // Give the last row the first row's value
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            // Give the first row the temporary's value (last row's value)
            image[i][width - j - 1].rgbtRed = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtBlue = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumRed;
    int sumGreen;
    int sumBlue;
    // Counter needed the track the number of neighboor pixels
    float counter;
    // Create a temporary matrix of colors to keep original pixel colors
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;
            counter = 0.00;
            // For every pixel you have to iterate over a smaller matrix (2D array)
            // Smaller matrix contains every neighbor and the original pixel as well
            // Prev neighbor = -1, the next = +1 > iterate from -1 to 2, 2 excluded
            // Consider the edges of the picture!!!
            for (int h = -1; h < 2; h++)
            {
                // Consider the top and bottom edge
                // If it is skip this iteration and continue with the next
                if (i + h < 0 || i + h > height - 1)
                {
                    continue;
                }

                for (int w = -1; w < 2; w++)
                {
                    // Consider the left and right edge
                    // If it is skip this iteration and continue with the next
                    if (j + w < 0 || j + w > width - 1)
                    {
                        continue;
                    }

                    // Add pixel RGB values to sums
                    // Increment the counter
                    sumRed += image[i + h][j + w].rgbtRed;
                    sumGreen += image[i + h][j + w].rgbtGreen;
                    sumBlue += image[i + h][j + w].rgbtBlue;
                    counter++;
                }
            }

            // Calculate avg RGB values
            // Add it to the temporary matrix
            // Do not forget to round > RGB values are ints!!!
            temp[i][j].rgbtRed = round(sumRed / counter);
            temp[i][j].rgbtGreen = round(sumGreen / counter);
            temp[i][j].rgbtBlue = round(sumBlue / counter);
        }
    }

    // Copies values from temporary table to the original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }

    return;
}
