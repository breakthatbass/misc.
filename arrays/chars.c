#include <stdio.h>
#include <stdlib.h>

#define CHARARR 4
#define MAXWORD 15


void print_char_array(char **arr, int len)
{
	int i;
	char **str;		// load arr into here to print from

	// allocate space for each word	
	for (i = 0; i < len; i++) {
		str = malloc(sizeof(char)*MAXWORD);
	}

	// assign word to each spot in new array
	for (i = 0; i < len; i++) {
		str[i] = arr[i];
	}

	while (*str)
		printf("%s ", *str++);
	printf("\n");
}


void print_int_array(int *nums, int len)
{
	
}



int main()
{
	char *greet[] = {"hello", "how", "are", "you"};
	int length = sizeof(greet)/sizeof(greet[0]);
	
	print_char_array(greet, length);

	return 0;
}
