#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

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
    int countLetters = 0;
    int countWords = 0;
    int countSentences = 0;
    int textLengthChar = strlen(text);

    for (int i = 0; i < textLengthChar; i++)
    {
        char character = text[i];
        if (character == ' ')
        {
            countWords++;
        }
        else if (character == '.' || character == '!' || character == '?')
        {
            countSentences++;
        }
        else
        {
            countLetters++;
        }
    }
    // there is no space in the end of the sentence so we need to add the last word manually
    countWords++;

    // if there is no punctuation in the world, we'll consider everything one sentence
    if (countSentences == 0)
        countSentences++;

    int lettersPer100Words = round(100 * (double) countLetters / (double) countWords);
    int sentencesPer100Words = round(100 * (double) countSentences / (double) countWords);

    return 0.0588 * lettersPer100Words - 0.296 * sentencesPer100Words - 15.8;
}
