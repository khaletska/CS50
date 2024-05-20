#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_level(string text);

int main(void)
{
    string text = get_string("Text: ");

    int level = get_level(text);

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

int get_level(string text)
{
    int count_letters = 0;
    int count_words = 0;
    int count_sentences = 0;

    for (int i = 0, text_length_char = strlen(text); i < text_length_char; i++)
    {
        char character = text[i];
        if (character == ' ')
        {
            count_words++;
        }
        else if (character == '.' || character == '!' || character == '?')
        {
            count_sentences++;
        }
        else
        {
            count_letters++;
        }
    }
    // there is no space in the end of the sentence so we need to add the last word manually
    count_words++;

    // if there is no punctuation in the world, we'll consider everything one sentence
    if (count_sentences == 0)
        count_sentences++;

    int letters_per_100_words = round(100 * (double) count_letters / (double) count_words);
    int sentences_per_100_words = round(100 * (double) count_sentences / (double) count_words);

    return 0.0588 * letters_per_100_words - 0.296 * sentences_per_100_words - 15.8;
}
