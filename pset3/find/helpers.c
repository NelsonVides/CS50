/**
 * helpers.c
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

#include "helpers.h"



/**
 * Swaps two given values
 * call by swap(&a,&b)
 */
void swap(int* a, int* b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}

#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 * We are already assuming a sorted array!
 */
bool search(int value, int values[], int n)
{
    if (n <= 0) //sanity check for impossible array size
        {return false;}

    int midPoint = trunc( (n-1) / 2);
    
    int aux = values[midPoint];
    
while (n > 0) {
    if (aux == value)
        {return true;}
    else if (value < aux)   //search left
        {   return (search(value, values, midPoint));   }
    else if (aux < value)   //search right
        {   return (search(value, values + midPoint + 1, n - 1 - midPoint));    }
}
return false;
}



/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // Selection sort
int min = 0;
int   i = 0;
int   j = 0;
    for (i = 0 ; i < n - 1 ; i++)
    {
        min = i;
        //find smallest element from i to n-1;
        for (j = i + 1; j < n ; j++)
        {
            if (values[j] < values[min])
                {   min = j;   }
        }
        
        if (min != i)
        {
            swap( (values+min) , (values+i) );
        }
    }
}