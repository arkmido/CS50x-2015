#include <stdio.h>

int main(void)
{
    for(char c = 'a'; c <= 'z'; c++)
        printf("%c = %d\n",c , c - 'a');
        
    printf("' = %d\n", 26);
}
