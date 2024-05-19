#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isKeyValid(string key);
string encryptText(string key, string text);

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

    if (!isKeyValid(key))
    {
        printf("Key should contain each letter exactly once.\n");
        return 1;
    }

    string text = get_string("plaintext:  ");

    string cipher = encryptText(key, text);
    printf("ciphertext: %s\n", cipher);
}

bool isKeyValid(string key)
{
    bool letterCounts[26] = {false};

    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]))
        {
            key[i] = toupper(key[i]);
            if (letterCounts[key[i] - 65])
            {
                return false;
            }
            else
            {
                letterCounts[key[i] - 65] = true;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

string encryptText(string key, string text)
{
    int textSize = strlen(text);
    string cipher = malloc((textSize) * sizeof(char));
    cipher[textSize] = '\0';

    for (int i = 0; i < textSize; i++)
    {
        char textCharacter = text[i];
        if (!isalpha(textCharacter))
        {
            cipher[i] = textCharacter;
            continue;
        }

        bool islower = islower(textCharacter);
        int index = toupper(textCharacter) - 65;

        if (islower)
        {
            cipher[i] = tolower(key[index]);
        }
        else
        {
            cipher[i] = toupper(key[index]);
        }
    }

    return cipher;
}
