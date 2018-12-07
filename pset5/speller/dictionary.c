// Implements a dictionary's functionality


#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#include "dictionary.h"



node *head;


// Returns true if word is in dictionary else false
bool check(char *word)
{


    //check if word in list
    node *curser = head;

    for(int i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }

    while(curser != NULL){

        if(strcmp(word, curser->word) == 0){
            return true;
        }

        curser = curser->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    head = malloc(sizeof(node));
    //opens the file
    FILE *file = fopen(dictionary, "r");

    char word[LENGTH + 1];
    while(fscanf(file, "%s", word) != EOF){

        node *new_node = malloc(sizeof(node));
        if(new_node == NULL){
            free(new_node);
            return false;
        }

        strcpy(new_node->word, word);
        new_node->next = head;
        head = new_node;

    }

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    node *curser = head;
    int x = 0;

    while(curser != NULL){

        x++;
        curser = curser->next;
    }
    return x-1;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *curser = head;

    while(curser != NULL){
        node *temp = curser;
        curser = curser->next;
        free(temp);
    }
    free(curser);
    free(head);

    return true;
}
