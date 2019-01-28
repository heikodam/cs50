// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: n (resize factor) inPicture outPicture\n");
        return 1;
    }

    int n = atoi(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //MY CODE
    BITMAPINFOHEADER new_bi = bi;
    BITMAPFILEHEADER new_bf = bf;

    //Change Header Info
    new_bi.biWidth *= n;
    new_bi.biHeight *= n;
    new_bi.biSizeImage = bi.biSizeImage * n * n;
    new_bf.bfSize = new_bi.biSizeImage + sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER);

    //END OF MY CODE

    // write outfile's BITMAPFILEHEADER
    fwrite(&new_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&new_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    int countPixelBytes = 0;
    //int curserPos;
    int total = 54;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

        //curserPos = SEEK_CUR;
        //duplicate the whole line n times
        for (int l = 0; l < n; l++)
        {
            //fseek(inptr, (curserPos - SEEK_CUR) * 3 - padding, SEEK_CUR);
            fseek(inptr, total , SEEK_SET);

            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                //duplicate pixel horizontal n times
                for(int k = 0;  k < n; k++)
                {
                // write RGB triple to outfile
                //printf("Printing Pixel k: %i\n", k);
                countPixelBytes += 3;
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            int new_padding = (4 - (countPixelBytes) % 4) % 4;

            printf("Bytes: %i   new_padding: %i   padding: %i\n", countPixelBytes, new_padding,padding);

            countPixelBytes = 0;

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }


        }

        total += bi.biWidth * 3 + padding;

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
