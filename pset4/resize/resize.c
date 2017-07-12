/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{   // ensure proper usage
    if (argc != 4)
    {   fprintf(stderr, "Usage: ./resize factor infile outfile\n");
        return 1;}

    // remember filenames
    float factor = atof(argv[1]); // ¿Sí?
    char *infile = argv[2];
    char *outfile = argv[3];

    // check resize value2 
    if ( (factor <= 0.0) || (factor > 100.0) )
    {   fprintf(stderr, "Not a valid value of factor\n");
        return 2;}
    
    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    int trackbiHeight = abs(bi.biHeight);
    int trackbiWidth = bi.biWidth;
    int trackPad =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // Update Headers
    bi.biWidth = bi.biWidth * factor;
    bi.biHeight = bi.biHeight * factor;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    int cdf = ceil(factor);
    int cdfinv = ceil(1/factor);
    
    // iterate over infile's scanlines WHICH LINES TO COPY...
    for (int i = 0; i < trackbiHeight; i = i + cdfinv) { 
        
        // copy the same line N times HOW MANY TIMES TO COPY THEM
        for (int m = 0; m < cdf; m++) {
            
            // iterate over pixels in scanline
            for (int j = 0; j < trackbiWidth; j = j + cdfinv) {
                // temporary storage
                RGBTRIPLE triple;
                // vamos con los píxeles por línea...
                for (int l = 0; l < round(factor) ; l++) {
                    fseek(inptr, round(factor), SEEK_CUR);
                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                    // copy the same pixel N times
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            // add outfile padding
            for (int k = 0; k < padding; k++) {
                fputc(0x00, outptr);
            }
            // come back except on the last copy time
            int aux = (trackbiWidth * sizeof(RGBTRIPLE));
            fseek(inptr, - aux, SEEK_CUR);
        }
        
        int aux = (trackbiWidth * sizeof(RGBTRIPLE)) + trackPad;
        fseek(inptr, cdfinv * aux, SEEK_CUR);
    }
    
    
    
    
    
    // close infile
    fclose(inptr);
    // close outfile
    fclose(outptr);
    // success
    return 0;
}
