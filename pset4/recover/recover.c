/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t  BYTE;
const int block = 512;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2) {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL) {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    char filename[8] = "000.jpg"; // OJO
    int NumPic = 0;
    BYTE buffer[block];
    FILE *outptr = NULL;

    while ( fread(&buffer, sizeof(BYTE), block, inptr) == block ) {
        
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) {
            
            // if there was something open, close it
            if (outptr != NULL) {
                fclose(outptr);}
                
            // build the filename name
            sprintf(filename, "%03i.jpg" , NumPic);
            NumPic++;
                
            // open a new JPEG file
            outptr = fopen(filename, "w");
                
            // sanity check in case it couldn't open
            if (outptr == NULL) { fclose(inptr);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }
        }
        
        if (outptr != NULL) {    
            // write the buffer on our current JPEG
            fwrite(&buffer, sizeof(BYTE), block, outptr);
        }
    }
    
    // close infile
    fclose(inptr);
    
    // close outfile
    fclose(outptr);
        
    // success
    return 0;
}