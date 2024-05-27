// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 78;
unsigned int word_count = 0;

// Hash table
node *table[N] = {NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int length = strlen(word) + 1;
    char lowercase_word[length];
    lowercase_word[length] = '\0';
    for (int index = 0; index < length; index++)
    {
        lowercase_word[index] = tolower(word[index]);
    }

    unsigned int index = hash(lowercase_word);
    node *current = table[index];

    while (current != NULL)
    {
        if (strcmp(current->word, lowercase_word) == 0)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    switch (strlen(word))
    {
        case 0:
            return 0;
        case 1:
            return toupper(word[0]) - 'A';
        case 2:
            return (toupper(word[0]) - 'A') + (toupper(word[1]) - 'A');
        default:
            return (toupper(word[0]) - 'A') + (toupper(word[1]) - 'A') + (toupper(word[2]) - 'A');
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if (source == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    // Read each word in the file
    while (fscanf(source, "%s", word) != EOF)
    {
        // Add each word to the hash table
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(source);
            return false;
        }

        strcpy(new_node->word, word);
        unsigned int index = hash(word);
        new_node->next = table[index];
        table[index] = new_node;

        word_count++;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int index = 0; index < N; index++)
    {
        node *current = table[index];
        while (current != NULL)
        {
            node *tmp = current;
            current = current->next;
            free(tmp);
        }
        table[index] = NULL;
    }

    return true;
}
