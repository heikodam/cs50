//Not my Code this is from Aman the Hacker; I am a White Hat Hacker that I got  his Code... :) Regards Me
#include <stdio.h>
#include <stdint.h>
typedef uint8_t  BYTE;

//function to check 1st four bytes to see if it is jpeg
int checkJPEG(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
//main function
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage ./recover image");
        return 1;
    }
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    BYTE buffer[512];
    int filenumber = 0;
    char outfile[8];
    FILE *outptr = NULL;
    //iterates over file
    while (fread(&buffer, 512, 1, raw_file))
    {
        if (checkJPEG(buffer) == 0)
        {
            // it there is output file already opened it closes it.
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            // create a output filename
            sprintf(outfile,"%03i.jpg", filenumber);
            filenumber++;
            //open the output file
            outptr = fopen(outfile, "w");
            fwrite(&buffer, 512, 1, outptr);
        }
        else if (outptr != NULL)
        {
            fwrite(&buffer, 512, 1, outptr);
        }
    }
    fclose(raw_file);
    fclose(outptr);
}