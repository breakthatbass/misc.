/**
 * 
 * shuffle algorithm
 * 
 * This algorithm takes an array of pointers and the length of that array.
 * It loops through the array swapping each element with a random element
 * 
 * */

#include <stdlib.h>
#include <time.h>

void swap (int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void shuffle_array(void **arr, int length)
{
    int i, j;
    
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        j = rand() % length;
       swap(arr[i], arr[j]);
    }
}