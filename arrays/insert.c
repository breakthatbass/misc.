#include <stdio.h>

// get element to be inserted, x
// get position where it'll be inserted, pos
// shift all elements from this position one forward
// insert x at pos which is now empty


int main()
{
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

  // element to be inserted
  x = 50;

  // position to be inserted at
  pos = 5;

  // increase size by 1
  n++;

  // shift elements forward
  for (i = n; i >= pos; i--)
  {
    arr[i] = arr[i - 1];
  }

  // insert at pos
  arr[pos - 1] = x;

  printf("new array with insert is: ");
  for ( i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
