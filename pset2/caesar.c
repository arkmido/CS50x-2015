/*
* Mark Lester Gunido
*
* caesar.c
*
* shows how caesar cipher works
*/
#include <stdio.h>  // for prinft()
#include <cs50.h>   // for GetString()
#include <stdlib.h> // for atoi()
#include <string.h> // for strlen()
#include <ctype.h> // for isalpha(), isupper()


// take command line arguments for the key
int main(int argc, string argv[])
{
    // checks if contains atleast two arguments and argv[1] >= 0
    if (argc == 2 && (atoi(argv[1]) > -1))
    {
        int k = atoi(argv[1]);
        string msg = GetString();      
        
        // iterate through the string
        for(int i = 0, n = strlen(msg); i < n; i++)
        {
            // checks if character is an alphabet character
            if (isalpha(msg[i]))
            {
                // checks if uppercase
                if (isupper(msg[i]))
                {
                    printf("%c",(((msg[i] - 65) + k) % 26) + 65);
                }
                // handles lowercase    
                else
                    printf("%c", (((msg[i] - 97) + k) % 26) + 97);
            }
            // if not an alphabet, just print..
            else
                printf("%c", msg[i]);
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Invalid argument/s!\n");
        return 1;
    }
}
