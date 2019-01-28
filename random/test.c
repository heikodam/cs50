#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){

    int i = 0;
    while(i != 9){
        printf("%i\n",i);
        i ++;
        if(i > 50){
            break;
        }
        i++;
    }

   return 0;

}