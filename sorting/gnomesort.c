#include <stdio.h>

void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void gnome_sort(int *arr, int len)
{
    int pos = 0;
    while (pos < len) {
        if (pos == 0 || arr[pos] >= arr[pos - 1]) {
            pos++;
        }
        else {
            swap(&arr[pos], &arr[pos - 1]);
            pos--;
        }
    }

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

 gnome_sort(unsorted_nums, len);

  printf("Sorted array:\n");
  print_list(unsorted_nums, len);

  return 0;
}