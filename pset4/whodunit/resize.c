/**
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }
    // TODO remember n resize
    int n_resize = atoi(argv[1]);
    if (n_resize < 1 | n_resize >= 100)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile  ( n in range 1 - 100 )\n");
        return 1;
}

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


    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding_new = (4 - (bi.biWidth * n_resize* sizeof(RGBTRIPLE)) % 4) % 4;
    
    //  sizes  headers only
    bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    //  set write position in first RGBTRIPLE, write HEADER after calculate it
    fseek(outptr, bf.bfSize, SEEK_SET);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // repit write n...
        for (int n = 0; n < n_resize; n++)   // 
        {
            if (n != 0)  
            {
                //  if resize >1 return to start of scanline 
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
            }
            
            //iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                //temporary storage
                RGBTRIPLE triple;

                //read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int k = 0; k < n_resize; k++)
                {
                    //write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    //  increment file size in write data
                    bf.bfSize = bf.bfSize + sizeof(RGBTRIPLE);
                }
            }
            // add padding
            for (int m = 0; m < padding_new; m++)
            {
                fputc(0x00, outptr);
                //  increment file size in write data
                bf.bfSize = bf.bfSize + 1;
            }
        }
        
        //skip over padding
        fseek(inptr, padding, SEEK_CUR);
    }

    // cheng data in  BITMAPFILEHEADER
    bi.biWidth = bi.biWidth * n_resize;
    bi.biHeight = bi.biHeight * n_resize;
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + padding_new) * abs(bi.biHeight); 
   
    // set write position and save new BITMAPFILEHEADER and BITMAPINFOHEADER
    fseek(outptr, 0, SEEK_SET); 
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    //close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}