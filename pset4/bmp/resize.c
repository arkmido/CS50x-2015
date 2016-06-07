/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Based from copy.c, resizes a 24-bit bmp to value of n
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize size infile outfile\n");
        return 1;
    }

    // gets resize value
    int n = atoi(argv[1]);
    if (n > 100 || n < 1)
    {
        printf("Make sure resize value is 1-100 only\n");
        return 1;
    }
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
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
    
    // determine padding for scanlines
    int inFilepadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // modified section to scale bitmap to size of n
    
    // second instance of bi and bf to prevent overwriting
    BITMAPFILEHEADER outbf = bf;
    BITMAPINFOHEADER outbi = bi;
    
    // outbf and outbf node computations
    outbi.biWidth = bi.biWidth * n;
    outbi.biHeight = bi.biHeight * n;
    int outFilepadding = (4 - (outbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    outbi.biSizeImage = (outbi.biWidth * abs(outbi.biHeight) * 3) + (outFilepadding * abs(outbi.biHeight));
    outbf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + outbi.biSizeImage;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&outbf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&outbi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // cursor identifier
    int scanCtr = 0;
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // repeat writing until r = n
        int r = 0;
        do
        {
            // change file stream cursor
            fseek(inptr, ((sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER)) + scanCtr), SEEK_SET);   
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for(int m = 0; m < n; m++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            fseek(inptr, inFilepadding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < outFilepadding; k++)
            {
                fputc(0x00, outptr);
            }

            r++;
             
        }while(r < n);
        
        // add width*(3 bytes) + padding to move cursor to next row
        scanCtr = scanCtr+((bi.biWidth*3)+inFilepadding);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
