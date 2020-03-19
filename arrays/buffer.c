#include <stdio.h>

int main()
{

  // initialize original array: numbers 1 - 10
  int arr[100] = { 1, 2, 3, 1, 2, 5 };
  int i, x, remove, pos, n = 10;

  // print the array now
  printf("original array is: ");
  for (i = 0; i < 6; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  /*--------------------------------------*/

  // get address in memory of array
  printf("the address of the array is: %pn\n", &arr);

  // and since buffer_info() in python returns length of array,
  // we will do that here too

  size_t len = sizeof(arr)/sizeof(arr[0]);

  printf("the length of the array is: %zu\n", len);
}
