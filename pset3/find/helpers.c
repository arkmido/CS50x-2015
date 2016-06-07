/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    // Linear Search
    /*
    for (int i = 0; i < n; i++)
    {
        if ( values[i] == value )
            return true;
    }
    return false; */
    // Binary Search
    int upper = n-1;
    int lower = 0;
    if(upper < lower)
        return -1;
    else{
        while (lower <= upper){
            int mid = (upper + lower)/2;
            if(value < values[mid])
                upper = mid-1;
            else if(value > values[mid])
                lower = mid+1;
            else
                return true;
        }
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // Selection sort
    for (int i = 0; i < (n-1); i++)
    {
        int min = i;
        
        for (int j = i+1; j < n; j++)
        {
            if (values[j] < values[min])
                min = j;
        }
        
        if (min != i)
        {
            int temp = values[i];
            values[i] = values[min];
            values[min] = temp;
        }
    }
    return;
}
