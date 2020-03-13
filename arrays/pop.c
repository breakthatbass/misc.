#include <stdio.h>

int main()
{

  // initialize original array: numbers 1 - 10
  int arr[100] = { 0 };
  int i, x, pos, n = 10;

  // initial array size of 10
  for (i = 0; i < 10; i++)
  {
    arr[i] = i + 1;
  }

  // print the array now
  printf("original array is: ");
  for (i = 0; i < 10; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  /*--------------------------------------*/

  // removes element at position mentioned and returns it

  // get position, var pos
  pos = 5;

  // return element at that position
  printf("element at position %i is: %d\n", pos, arr[pos]);


  // move all elements in array back one at that position on
  for (i = pos; i < n - 1; i++)
  {
    arr[i] = arr[i + 1];
  }

  // print the new array
  printf("the new array is: ");
  for (i =0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

}
