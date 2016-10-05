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
bool search(int value, int values[], int high)
{
    // TODO: implement a searching algorithm
    int middle =0;
    int low =0;
    
    while (low <= high)
    {
        middle = (low + high) / 2;

        if (value == values[middle])
            return true;
        else if(value < values[middle])
            high = middle -1;
        else
            low = middle +1;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
int temp = 0;  
bool exit = false; 

while (!exit) // buble sort
    {
    exit = true;
    for (int int_counter = 0; int_counter < (n - 1); int_counter++)  
        if (values[int_counter] > values[int_counter + 1]) 
        {
         temp = values[int_counter];
         values[int_counter] = values[int_counter + 1];
         values[int_counter + 1] = temp;
         exit = false;  
        }
    }
    return;
}