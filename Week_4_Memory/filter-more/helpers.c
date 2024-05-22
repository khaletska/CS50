#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;
            int average = round((blue + green + red) / 3.f);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int temp_blue = image[i][j].rgbtBlue;
            int temp_green = image[i][j].rgbtGreen;
            int temp_red = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][width - 1 - j].rgbtBlue = temp_blue;
            image[i][width - 1 - j].rgbtGreen = temp_green;
            image[i][width - 1 - j].rgbtRed = temp_red;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int sum_blue = 0;
            int sum_green = 0;
            int sum_red = 0;
            float count = 0.0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int box_row = row + i;
                    int box_col = col + j;

                    if (box_row >= 0 && box_row < height && box_col >= 0 && box_col < width)
                    {
                        sum_blue += image_copy[row + i][col + j].rgbtBlue;
                        sum_green += image_copy[row + i][col + j].rgbtGreen;
                        sum_red += image_copy[row + i][col + j].rgbtRed;
                        count += 1;
                    }
                }
            }

            image[row][col].rgbtBlue = round(sum_blue / count);
            image[row][col].rgbtGreen = round(sum_green / count);
            image[row][col].rgbtRed = round(sum_red / count);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            float sum_blue_gx = 0.0;
            float sum_green_gx = 0.0;
            float sum_red_gx = 0.0;
            float sum_blue_gy = 0.0;
            float sum_green_gy = 0.0;
            float sum_red_gy = 0.0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int box_row = row + i;
                    int box_col = col + j;

                    if (box_row >= 0 && box_row < height && box_col >= 0 && box_col < width)
                    {
                        sum_blue_gx += image_copy[row + i][col + j].rgbtBlue * gx[i + 1][j + 1];
                        sum_green_gx += image_copy[row + i][col + j].rgbtGreen * gx[i + 1][j + 1];
                        sum_red_gx += image_copy[row + i][col + j].rgbtRed * gx[i + 1][j + 1];
                        sum_blue_gy += image_copy[row + i][col + j].rgbtBlue * gy[i + 1][j + 1];
                        sum_green_gy += image_copy[row + i][col + j].rgbtGreen * gy[i + 1][j + 1];
                        sum_red_gy += image_copy[row + i][col + j].rgbtRed * gy[i + 1][j + 1];
                    }
                }
            }

            int blue_value = round(sqrt(sum_blue_gx * sum_blue_gx + sum_blue_gy * sum_blue_gy));
            int green_value =
                round(sqrt(sum_green_gx * sum_green_gx + sum_green_gy * sum_green_gy));
            int red_value = round(sqrt(sum_red_gx * sum_red_gx + sum_red_gy * sum_red_gy));

            image[row][col].rgbtBlue = blue_value > 255 ? 255 : blue_value;
            image[row][col].rgbtGreen = green_value > 255 ? 255 : green_value;
            image[row][col].rgbtRed = red_value > 255 ? 255 : red_value;
        }
    }

    return;
}
