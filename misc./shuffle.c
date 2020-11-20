/**
 * 
 * shuffle algorithm
 * 
 * This algorithm takes an array of pointers and the length of that array.
 * It loops through the array swapping each element with a random element
 * 
 * */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap (int* a, int* b) 
{ 
    int *tmp = a; 
    a = b; 
    b = tmp;
} 

void shuffle_array(int *arr, int length)
{
    int i, j;

	int* const int_arr = (int*)arr;

    srand(time(NULL));
    for (i = 0; i < length; i++) {
        j = rand() % length;
    	swap(&(int_arr[i]), &(int_arr[j]));
    }
}

int main()
{
	int *a = malloc(sizeof(int)*10);
	
	for (int i = 0; i < 10; i++) {
		a[i] = i+1;
	}


	printf("array unshuffled: \n");
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}


	shuffle_array(*a, 10);

	printf("\narray shuffled: \n");

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}
