#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getLine(void);		// reads a line of text
int str_compare(const void *, const void *); // for qsort

#define NLINES_MAX 1000
char *linePtr[NLINES_MAX];

int main()
{

	// read lines
	int n = 0;		// number of lines read
	for ( ; n < NLINES_MAX && (linePtr[n] = getLine()) != NULL; ++n)
		;

	if (!feof(stdin))	// handle errors
	{
		if (n == NLINES_MAX)
			fputs("sorttext: too many lines\n", stderr);
		else
			fputs("sorttext: error reading from stdin\n", stderr);
	}
	else	// sort and print
	{
		qsort(linePtr, n, sizeof(char*), str_compare);
		for (char **p = linePtr; p < linePtr+n; ++p)
			puts(*p);
	}
	return 0;
}


// reads a line of text from stdin, drops the terminating
// newline character
// return value: a pointer to the string read, or 
// NULL at EOF or it an error occurred
#define LEN_MAX 512

char *getLine()
{
	char buffer[LEN_MAX], *linePtr = NULL;
	if (fgets(buffer, LEN_MAX, stdin) != NULL)
	{
		size_t len = strlen(buffer);

		if (buffer[len-1] == '\n')	// trim the newline character
			buffer[len-1] = '\0';
		else
			++len;

		if ((linePtr = malloc(len)) != NULL)  // get memory for the line
			strcpy(linePtr, buffer);	// copy line to allocated block
	}
	return linePtr;
}


// comparison function for use by qsort()
// arguments: pointers to two elements in the array being sorted:
// here, two pointers to pointers to char (char **)
int str_compare(const void *p1, const void *p2)
{
	return strcmp(*(char **)p1, *(char **)p2);
}

