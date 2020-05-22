/*
  reverse a string
*/
#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
  int c, i, j;
  int len = strlen(s) - 1;

  // this weird loop has two indices
  // basically starts at the beginning and end and both work towards the middle
  for (i = 0, j = len; i < j; i++, j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

// tests
int main()
{
  char one[] = "hello world";
  char two[] = "It's a beautiful day today";

  printf("orignal string: %s\n", one);
  reverse(one);
  printf("reversed string: %s\n", one);
  printf("orignal string: %s\n", two);
  reverse(two);
  printf("reversed string: %s\n", two);

  return 0;
}
