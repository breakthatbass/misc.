#include <stdio.h>

void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void bubble_sort(int arr[], int n) {
  int i,j;

  for (i = 0; i < n-1; i++)
    for (j = 0; j < n-i-1; j++)
      if (arr[j] > arr[j+1])
        swap(&arr[j], &arr[j+1]);
}

void print_list(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}


int main()
{
  int unsorted_nums[] = {1003,12,45,1345,33,56354,43,221,0,12,98,87,89,908};
  int len = sizeof(unsorted_nums)/sizeof(unsorted_nums[0]);

  printf("Original array:\n");
  print_list(unsorted_nums, len);

  bubble_sort(unsorted_nums, len);

  printf("Sorted array:\n");
  print_list(unsorted_nums, len);

  return 0;
}
