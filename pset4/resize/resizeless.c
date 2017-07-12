/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{   // ensure proper usage
    if (argc != 4)
    {   fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;}

    // remember filenames
    int n = atoi(argv[1]); // ¿Sí?
    char *infile = argv[2];
    char *outfile = argv[3];

    // check resize value2 
    if ( (n <= 0) || (n > 100) )
    {   fprintf(stderr, "Not a valid value of n\n");
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
    bi.biWidth = bi.biWidth * n;
    bi.biHeight = bi.biHeight * n;
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0; i < trackbiHeight; i++) {
        
        // copy the same line N times
        for (int m = 0; m < n; m++) {
            
            // iterate over pixels in scanline
            for (int j = 0; j < trackbiWidth; j++) {
                // temporary storage
                RGBTRIPLE triple;
                
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // copy the same pixel N times
                for (int l = 0; l < n; l++) {
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
        
        // skip over infile padding, if any
        fseek(inptr, (int) (trackbiWidth * sizeof(RGBTRIPLE) + trackPad), SEEK_CUR);
    }
    
    
    
    // close infile
    fclose(inptr);
    // close outfile
    fclose(outptr);
    // success
    return 0;
}
