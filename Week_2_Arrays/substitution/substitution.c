#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_key_valid(string key);
string encrypt_text(string key, string text);

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

    if (!is_key_valid(key))
    {
        printf("Key should contain each letter exactly once.\n");
        return 1;
    }

    string text = get_string("plaintext:  ");

    string cipher = encrypt_text(key, text);
    printf("ciphertext: %s\n", cipher);
}

bool is_key_valid(string key)
{
    bool letter_counts[26] = {false};

    for (int i = 0, key_length = strlen(key); i < key_length; i++)
    {
        if (isalpha(key[i]))
        {
            key[i] = toupper(key[i]);
            if (letter_counts[key[i] - 'A'])
            {
                return false;
            }
            else
            {
                letter_counts[key[i] - 'A'] = true;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

string encrypt_text(string key, string text)
{
    string cipher = text;

    for (int i = 0, text_size = strlen(text); i < text_size; i++)
    {
        char text_character = text[i];
        if (!isalpha(text_character))
        {
            cipher[i] = text_character;
            continue;
        }

        bool islower = islower(text_character);
        int index = toupper(text_character) - 'A';

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
