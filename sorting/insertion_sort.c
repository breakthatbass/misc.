#include <stdio.h>

void insertion_sort(int array[], int n)
{
  int i, key_item, j;
  for (i = 0; i < n; i++) {
    key_item = array[i];

    j = i - 1;

    while (j >= 0 && array[j] > key_item) {
      array[j+1] = array[j];
      j--;
    }
    array[j + 1] = key_item;
  }
}

void print_list(int arr[], int n)
{
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


int main()
{
  int unsorted_nums[] = {1003,12,45,1345,33,56354,43,221,0,12,98,87,89,908};
  int len = sizeof(unsorted_nums)/sizeof(unsorted_nums[0]);

  printf("Original array:\n");
  print_list(unsorted_nums, len);

  insertion_sort(unsorted_nums, len);

  printf("Sorted array:\n");
  print_list(unsorted_nums, len);

  return 0;
}
