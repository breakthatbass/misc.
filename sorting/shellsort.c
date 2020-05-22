/*
  "The basic idea of this sorting algorithm, which was invented in 1959 by
  D.L. Shell, is that in early stages, far apart elements are compared, rather
  than adjacent ones as in simpler interchange sorts [like insertion sort].
  This tends to eliminate large amounts of disorder quickly, so later stages
  have less work to do. The interval between compared elements is gradually
  decreased to one, at which point the sort effectively becomes an adjacent
  interchange method."

  Taken from page 62 of 'The C Programming Language' by Brian Kernighan and
  Dennis Ritchie.'
*/

#include <stdio.h>

void shellsort(int v[], int n)
{
  int gap, i, j, tmp;

  // break array in half upon each iteration
  for (gap = n/2; gap > 0; gap /= 2)
  {
    for (i = gap; i < n; i++) // the half taken is always at the end of array
    {
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
      {
        tmp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = tmp;
      }
    }
  }
}

void print_list(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// tests
int main()
{
  int unsorted_nums[] = {1003,12,45,1345,33,56354,43,221,0,12,98,87,89,908};
  int len = sizeof(unsorted_nums)/sizeof(unsorted_nums[0]);

  printf("Original array:\n");
  print_list(unsorted_nums, len);

  shellsort(unsorted_nums, len);

  printf("Sorted array:\n");
  print_list(unsorted_nums, len);

  return 0;
}
