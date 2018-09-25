#include <cs50.h>
#include <stdio.h>

int main(void){

    int height;

    do {
        height = get_int("Height: ");
    } while (height <= 0 && height > 25);

    char hash = '#';
    char space = ' ';
    int current = 2;

    for(int i=0; i<height; i++){
        for(int j=0;j<(height-current+1);j++){
            printf("%c", space);
        }
        for(int k=0; k<current;k++){
            printf("%c", hash);
        }
        printf("\n");
        current++;
    }
}
