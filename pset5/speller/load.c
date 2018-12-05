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
    while(fscanf(file, "%s", word) != EOF){

        node *new_node = malloc(sizeof(node));
        if(new_node == NULL){
            //unload();
            return false;
        }

        strcpy(new_node->word, word);
        new_node->next = head;
        head = new_node;

    }



    //check if word in list
    node *curser = head;
    char test[10] = "CAT";

    for(int i = 0; i < strlen(test); i++){
        test[i] = tolower(test[i]);
    }

    //curser = curser->next;
    //curser->x = 'h';
    //printf("\n\n\n%s\n\n\n\n", curser->x);

    while(curser != NULL){

        if(strcmp(test, curser->word) == 0){
            printf("Word Found\n");
            return 0;
        }

        curser = curser->next;
    }
    printf("MISSPELLED\n");
    return 0;

}