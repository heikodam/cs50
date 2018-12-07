// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

typedef struct node
{
    bool isWord;
    struct node *nextLetter[28];
}
node;

#endif // DICTIONARY_
