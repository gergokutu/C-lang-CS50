// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Word counter
int wordCount = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    // Obtain the hash value
    unsigned int index = hash(word);
    // Point at the right element of the array
    node *toCheck = table[index];

    // Compare the words > case insensitive!
    if (strcasecmp(toCheck->word, word) == 0)
    {
        return true;
    }

    // Until the last item of the list
    while (toCheck->next != NULL)
    {
        toCheck = toCheck->next;
        if (strcasecmp(toCheck->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
// Simply used one bucket for every letter, a = 0, b = 1 ... z = 25
unsigned int hash(const char *word)
{
    // TODO
    unsigned int n = (unsigned int) tolower(word[0]) - 97;
    return n;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    // Open the file
    // Return false if could not
    FILE *inputFile = fopen(dictionary, "r");
    // Read strings from the file until EOF
    char *dictWord = malloc(LENGTH);
    if (dictWord == NULL)
    {
        return false;
    }

    while (fscanf(inputFile, "%s", dictWord) != EOF)
    {
        // Create a new node and allocate memory
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy the word into the node word prop
        // Do not forget to track the words
        strcpy(n->word, dictWord);
        wordCount++;

        // Set *next to point at the beginning of list
        n->next = table[hash(dictWord)];

        // Set the array to point at the word (n) which becomes new beginning of the list
        table[hash(dictWord)] = n;
    }

    // Close the file
    fclose(inputFile);
    // Free memory allocated to the word temporarily
    free(dictWord);
    // And return true in case of success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // Creates two pointers to traverse the linked list
    // And cancel its element without losing its address
    node *tmp;
    node *toUnload;

    // Repeats for every index in the table
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }

        toUnload = table[i];
        tmp = toUnload;

        // Until the end of the list keeps freeing the memory allocated in load
        while (toUnload->next != NULL)
        {
            toUnload = toUnload->next;
            free(tmp);
            tmp = toUnload;
        }
        free(toUnload);
    }

    return true;
}
