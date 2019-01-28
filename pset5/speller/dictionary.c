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
int DicSize;


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char tempWord[strlen(word)];
    strcpy(tempWord, word);
    node *temp = head;
    for(int i = 0; i < strlen(tempWord);i++){
        tempWord[i] = tolower(tempWord[i]);

        int pos;
        if(tempWord[i] > '\''){
                pos = tempWord[i] - 'a';
            } else {
                pos = 26;
            }

        if(temp->nextLetter[pos] == NULL){

            return false;
        }
        temp = temp->nextLetter[pos];
    }
    if(temp->isWord){
            return true;
        } else {
            return false;
        }

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    DicSize = 0;
    //opens the file
    FILE *file = fopen(dictionary, "r");

    head = calloc(1,sizeof(node));
    head->isWord = false;

    char word[LENGTH + 1];
    //loop through words
    while(fscanf(file, "%s", word) != EOF){
        DicSize++;
        node *temp = head;
        //loop through char's of current word
        for(int x = 0; x < strlen(word); x++){
            char letter = word[x];
            //get the index fo char
            int index;
            if(letter > '\''){
                index = letter - 'a';
            } else {
                index = 26;
            }

            if(temp -> nextLetter[index] == NULL){
                //create new node, in that index and go to that node
                node *new_node = calloc(1,sizeof(node));
                new_node->isWord = false;
                temp->nextLetter[index] = new_node;
            }
            //go to the node that pointer is pointing to
            temp = temp->nextLetter[index];
        }
        // indicate that there is the end of a word
        temp->isWord = true;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // node *curser = head;
    // int x = 0;

    // while(curser != NULL){

    //     x++;
    //     curser = curser->next;
    // }
    return DicSize;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    // destroy(head);
    // //free(head);
    // return true;

    node *curser = head;
    bool isEmpty = true;
    node *temp;
    int count;

    while(curser != NULL){
        isEmpty = true;
        for(int i = 0; i < 27; i++){


            //if there is a pointer to another node go to that node
            if(curser->nextLetter[i] != NULL){
                //printf("i: %i \n", i);
                temp = curser;
                count = i;
                curser = curser->nextLetter[i];
                isEmpty = false;
                break;
            }
        }
        //if there are only NULL Pointers in that node free that node
            if(isEmpty){
                if(curser == head){
                    free(curser);
                    break;
                }
                //printf("Freeing\n");
                temp -> nextLetter[count] = NULL;
                free(curser);
                curser = head;
            }
    }
    return true;





    // node *curser = head;

    // while(curser != NULL){
    //     node *temp = curser;
    //     curser = curser->next;
    //     free(temp);
    // }
    // free(curser);
    // free(head);


}


// bool destroy(node *curNod)
// {
//     //printf("going into destroy\n");
//     // Recursively delete Trie
//     if (curNod)
//     {

//         for (int i = 0; i < 27; i++)
//         {

//             // Free children if avaible
//             if (curNod->nextLetter[i]){
//               destroy(curNod->nextLetter[i]);
//             }
//         }
//         free(curNod);
//     }
//     return 1;
// }