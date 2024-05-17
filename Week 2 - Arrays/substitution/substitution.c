#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool isValid(string key);
int getIndex(char letter);

int SIZE = 26;
char ALPHABET[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int values[26];

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage ./substitution key.\n");
        return 1;
    }

    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (!isValid(key))
    {
        printf("Key should contaim each letter exactly once.\n");
        return 1;
    }

    string text = get_string("plaintext:  ");

    int textSize = strlen(text);
    char cipher[textSize];
    cipher[textSize] = '\0';

    for (int i = 0; i < textSize; i++)
    {
        char ch = text[i];
        if (!isalpha(ch))
        {
            cipher[i] = ch;
            continue;
        }

        bool islower = islower(ch);
        char upper = toupper(ch);
        int index = getIndex(upper);

        if (islower)
        {
            cipher[i] = tolower(key[index]);
        }
        else
        {
            cipher[i] = toupper(key[index]);
        }
    }

    printf("ciphertext: %s\n", cipher);
}

int getIndex(char letter)
{
    char uppercase = toupper(letter);
    for (int i = 0; i < SIZE; i++)
    {
        if (ALPHABET[i] == uppercase)
        {
            return i;
        }
    }
    return -1;
}

bool isValid(string key)
{
    for (int i = 0; i < SIZE; i++)
    {
        char symbol = key[i];
        int index = getIndex(symbol);
        if (index == -1)
            return false;
        if (values[index] > 0)
            return false;
        values[index] = 1;
    }

    return true;
}
