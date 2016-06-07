/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    // open file; this is the stream to be read
    FILE* fptr = fopen("card.raw", "r");
    
    // validation of file
    if(fptr == NULL) {
        printf("Could not open file\n");
        return 2;
    }
    
    // buffer holder
    uint8_t buffer[512];
    
    // vars writing jpg file with name
    char name[8];
    int ctr = 0;
    
    // file output
    FILE* outfptr;
    
    // read until jpeg is found then writes the first 512bytes
    while(1){
        fread(&buffer, 512, 1, fptr);
        if((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) &&
                 (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            sprintf(name, "%03d.jpg",ctr);
            ctr++;
            outfptr = fopen(name, "a");
            fwrite(&buffer, 512, 1, outfptr);
            break;
        }
    }
    // read 512 bytes from fptr and store to buffer until end of file
     while(fread(&buffer, 512, 1, fptr) == 1)
     {
            if((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) &&
                 (buffer[3] == 0xe0 || buffer[3] == 0xe1))
            {
                fclose(outfptr);
                sprintf(name, "%03d.jpg",ctr);
                ctr++;
                outfptr = fopen(name, "a");
                fwrite(&buffer, 512, 1, outfptr);
                
            }
            else
                fwrite(&buffer, 512, 1, outfptr);
      }
      
    fclose(fptr);
    fclose(outfptr);

    return 0;
}
