/**
* Mark Lester F. Gunido
* 
* greedy.c
*
* Simulates greedy algorithm
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{   
    // gets user input
    float change;
    do
    {
        printf("Change owed $: ");
        change = GetFloat();   
    }
    while(change < 0);
   
    // converts input to cents and initialize number of coins
    int cents = roundf(change * 100);
    int coins = 0;
    
    // deduct change with highest possible cent value
    if (cents >= 25)
    {
        coins += cents / 25;
        cents %= 25;
    }
    if (cents >= 10)
    {
        coins += cents / 10;
        cents %= 10;
    }
    if (cents >= 5)
    {
        coins += cents / 5;
        cents %= 5;
    }
    if (cents >= 1)
    {
        coins += cents / 1;
        cents %= 1;
    }
    
    printf("%d\n", coins);
    
}
