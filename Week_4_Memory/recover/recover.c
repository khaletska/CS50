#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool is_new_image(uint8_t buffer[512]);

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
            sprintf(directory, "%03d.jpg", pictures_count);
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

    return buffer[3] >= 0xe0 && buffer[3] <= 0xef;
}
