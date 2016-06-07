/**
* mario.c
*
* Mark Lester F. Gunido
*
* re-creates the half-pyramid in Mario World 1-1
*/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompt user for a valid height input
    int height;
    do
    {
        printf("Enter height: ");
        height = GetInt();
    }
    while(height < 0 || height > 23);
    
    // prints the half-pyramid
    for(int rows = 0, spaces = height - 2; rows < height; rows++, spaces--)
    {
        for(int col = 0, block = 0; col <= height; col++, block++)
        {
            // checks if the block to be printed is # or white-space
            block <= spaces ? printf("-"):printf("#");
        }

        printf("\n");
    }
}
