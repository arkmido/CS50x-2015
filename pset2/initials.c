/*
* Mark Lester Gunido
*
* initials.c
*
* prints initials from an input name
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();
    
    // check if variable name is not empty
    if (name != NULL)
    {
        // prints the first character of the name
        printf("%c", toupper(name[0]));
        
        // checks if there's a space, then print the next character
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            if (name[i] == 32)
            {
                printf("%c",toupper(name[i + 1]));
            }
        }
        printf("\n");
    }
}

