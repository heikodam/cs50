#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


#include "dictionarytemp.h"


int main(int argc, char *argv[])
{
    if(argc > 5){
        return 1;
    }
    const char *dictionary = argv[1];


    //opens the file
    FILE *file = fopen(dictionary, "r");

    node *head = malloc(sizeof(node));

    char word[LENGTH + 1];
    //loop through words
    while(fscanf(file, "%s", word) != EOF){
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
                node *new_node = malloc(sizeof(node));
                temp->nextLetter[index] = new_node;
            }
            //go to the node that pointer is pointing to
            temp = temp->nextLetter[index];
        }
        // indicate that there is the end of a word
        temp->isWord = true;
    }


    //see if word is in dictionary
    char test[4] = "CAT";
    node *temp = head;
    for(int i = 0; i < strlen(test);i++){
        test[i] = tolower(test[i]);
        int pos = test[i] - 'a';
        temp = temp->nextLetter[pos];
    }
    if(temp->isWord){
            printf("Word Found\n");
        } else {
            printf("Word NOT Found\n");
        }







    // strcpy(new_node->word, word);
    //     new_node->next = head;
    //     head = new_node;

    // //check if word in list
    // node *curser = head;
    // char test[10] = "CAT";

    // for(int i = 0; i < strlen(test); i++){
    //     test[i] = tolower(test[i]);
    // }


    // while(curser != NULL){

    //     if(strcmp(test, curser->word) == 0){
    //         printf("Word Found\n");
    //         return 0;
    //     }

    //     curser = curser->next;
    // }
    // printf("MISSPELLED\n");
    // return 0;

}