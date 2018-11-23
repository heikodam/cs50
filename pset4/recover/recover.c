#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bmp.h"

char* concat(const char *s1, const char *s2);
bool isJPG(BYTE buffer[]);


int main (int argc, char *argv[])
{
    //checking for correct usage
    if(argc != 2){
        fprintf(stderr, "Usage: InputFile");
        return 1;
    }

    //declaring varibles
    //infile
    char *infile = argv[1];
    //outfile
    int outfileNum = 0;
    char outfile[9];
    //declare buffer array
    BYTE buffer[512];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //printf("Starting first While\n");

    do
    {
        printf("Running first while\n");
        //read inflie and save values in buffer
        fread(&buffer, 1, 512, inptr);

    } while(!isJPG(buffer));

    //printf("Out of first While and going into second\n");


    while(1){

        //printf("In second while\n");
        //setting the name for the outfile
        sprintf(outfile, "%03i.jpg", outfileNum);
        // open and create the outfile
        FILE *outptr = fopen(outfile, "w");
        //write buffer to the outfile
        fwrite(&buffer, 1, 512, outptr);
        fread(&buffer, 1, 512, inptr);

        while(!isJPG(buffer))
        {
            printf("In third While\n");
            //read inflie and save values in buffer
            if(fread(&buffer, 1, 512, inptr) < 512){
                fclose(outptr);
                return 0;
            }

            fwrite(&buffer, 1, 512, outptr);
        }
        //printf("Out of third while and in second\n");
        fclose(outptr);
        outfileNum += 1;


    }

    //printf("End of main funciton\n");

    return 1;

} //End of main Function



bool isJPG(BYTE buffer[])
{
    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
        return true;
    }
    else
    {
        return false;
  }
}