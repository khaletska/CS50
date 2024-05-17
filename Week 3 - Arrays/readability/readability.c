#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int getLevel(string text);

int main(void)
{
    string text = get_string("Text: ");

    int level = getLevel(text);

    if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", level);
    }
}

int getLevel(string text)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int length = 0;

    while (text[length] != 0)
    {
        if (text[length] == ' ')
        {
            words++;
        }
        else if (text[length] == '.' || text[length] == '!' || text[length] == '?')
        {
            sentences++;
        }
        else
        {
            letters++;
        }

        length++;
    }
    words++;

    return 0.0588 * round(100 * (double) letters / (double) words) -
           0.296 * round(100 * (double) sentences / (double) words) - 15.8;
}
