/*
* Mark Lester F. Gunido
*
* vigenere.c
*
* encypts string using vigenere cipher
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// function prototypes
int shift(char keyChar);
bool valid(string arg);

int main(int argc, string argv[])
{
    // checks if arguments are valid
    if (argc == 2 && valid(argv[1]))
    {
        // get key and message
        string key = argv[1];
        string msg = GetString();
        
        int keyIndex = 0, keySize = (strlen(key));
        
        for(int i = 0, mLen = strlen(msg); i < mLen; i++)
        {
            // index rotation of the key
            keyIndex = (keyIndex % keySize);
            
            if (isalpha(msg[i]))
            {
                if (isupper(msg[i]))
                {
                    // sets appropriate value of shifts to be added
                    int shiftKey = shift(key[keyIndex]);
                    
                    // final value of the char after computations
                    printf("%c", (((msg[i] - 65) + shiftKey) % 26) + 65);
                    
                    // iterate the index of key after using
                    keyIndex++;  
                }
                else
                {
                    int shiftKey = shift(key[keyIndex]);
                    printf("%c", (((msg[i] - 97) + shiftKey) % 26) + 97);
                    
                    keyIndex++;  
                }         
            }
            else
            {
                printf("%c", msg[i]);
            }                                 
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Invalid argument/s\n");
        return 1;
    }
}
/*
* gets the ascii value of c
* checks if in uppercase or lowercase
* then subtract to corresponding values
* to get appropriate 0-25 alphabet index
*/
int shift(char keyChar)
{
    if (isupper(keyChar))
    {
        return keyChar - 65;
    }
    else
    {
        return keyChar - 97;
    }
}
/*
* checks whether the string argument of argv
* contains alpha characters only
*/
bool valid(string arg)
{
    bool isValid = true;
    for(int i = 0, n = strlen(arg); i < n; i++)
    {
        if(!isalpha(arg[i]))
            isValid = false;
    }
    return isValid;
}
