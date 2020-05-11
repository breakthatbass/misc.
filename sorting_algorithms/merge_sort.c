#include <stdio.h>

// doesn't work.
// needs to be redone

int merge(int arr[], int start, int mid, int end)
{
  int result[end-start];

  int p = start;
  int q = mid+1;
  int i = 0;

  // populate the results array
  while (p <= mid && q <= end) {
    if (arr[p] < arr[q]) {
      result[i++] = arr[p++];
    } else if (arr[p] >= arr[q]) {
      result[i++] = arr[q++];
    }
  }

  // if there are any leftover elements, push them into the results array
  if (p <= mid) {
    while (p <= mid) {
      result[i++] = arr[p++];
    }
  } else if (q <= end) {
    while (q <= end) {
      result[i++] = arr[q++];
    }
  }

  // transfer the elements of results array to the main array
  for (int j = start; j < end; j++) {
    arr[j] = result[j - start];
  }

}

void merge_sort(int arr[], int start, int end)
{

  // exit when array can't be broken down anymore
  // and prevent infinite recursion
  if (start == end) {
    return;
  }

  int midpoint = (start+end)/2;

  merge_sort(arr, start, midpoint);
  merge_sort(arr, midpoint+1, end);

  merge(arr, start, midpoint, end);
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
  int unsorted_nums[] = {11, 2, 5, 9, 12, 1, 6};
  int len = sizeof(unsorted_nums)/sizeof(unsorted_nums[0]);

  printf("Original array:\n");
  print_list(unsorted_nums, len);

  merge_sort(unsorted_nums, 0, len);

  printf("Sorted array:\n");
  print_list(unsorted_nums, len);

  return 0;
}
