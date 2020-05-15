#include <stdio.h>

// last in, last out

// push function -> add to top
void push(int arr[], int len, int num)
{

  int tmp[len];

  for (int i = 0; i < len; i++) {
    tmp[i] = arr[i];
  }
  tmp[len] = num;
  // add int to the end of line
  arr = tmp;
}

// pop function -> delete from top

void print_list(int arr[], int n)
{
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{

  // initialize original array: numbers 1 - 10
  int stack[10] = { 0 };
  int i, x, pos, n = 10;

  // initial array size of 10
  for (i = 0; i < 10; i++)
  {
    stack[i] = i + 1;
  }
  int len = sizeof(stack)/sizeof(stack[0]) + 1;

  print_list(stack, len);
  push(stack, len, 50);
  print_list(stack, len);

  return 0;
}
