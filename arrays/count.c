#include <stdio.h>

int main()
{
  int i;
  int count = 0;
  int check = 5;

  int arr[] = { 1, 2, 5, 3, 5, 1, 2, 5 };

  int len = sizeof(arr)/sizeof(arr[0]);

  for (i = 0; i < len; i++)
  {
    if (check == arr[i])
    {
      count++;
    }
  }

  printf("%d\n", count);
}
