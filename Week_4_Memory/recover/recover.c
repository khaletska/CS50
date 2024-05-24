#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool is_new_image(uint8_t buffer[512]);
bool is_fourth_byte_correct(uint8_t byte);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover <file name>\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    uint8_t buffer[512];
    int pictures_count = 0;
    FILE *output = NULL;

    while (fread(&buffer, sizeof(buffer), 1, input) != 0)
    {
        if (is_new_image(buffer))
        {
            if (output != NULL)
                fclose(output);

            char directory[15];
            sprintf(directory, "images/%03d.jpg", pictures_count);
            output = fopen(directory, "w");
            if (output == NULL)
            {
                printf("Could not open file.\n");
                fclose(input);
                return 1;
            }

            pictures_count++;
        }

        if (output != NULL)
            fwrite(&buffer, sizeof(buffer), 1, output);
    }

    if (output != NULL)
        fclose(output);
    fclose(input);

    return 0;
}

bool is_new_image(uint8_t buffer[512])
{
    uint8_t image_first_bytes[3] = {0xff, 0xd8, 0xff};
    for (int index = 0; index < 3; index++)
    {
        if (buffer[index] != image_first_bytes[index])
            return false;
    }

    if (!is_fourth_byte_correct(buffer[3]))
        return false;

    return true;
}

bool is_fourth_byte_correct(uint8_t byte)
{
    uint8_t image_fourth_byte[16] = {0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7,
                                     0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef};

    for (int index = 0; index < 16; index++)
    {
        if (image_fourth_byte[index] == byte)
            return true;
    }

    return false;
}
