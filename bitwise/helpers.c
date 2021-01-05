 /**
* these functions comes from page 62 and 64 of the second
* edition of K&R. it's a bit of my own variant
* but it's the same logic which I copied
* 
* in our program we convert each int to a string
* one by one so we don't use the reverse function
* in the itoa function that they do in the book
* we use it in our dtob func at the end
* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "helpers.h"
 
 // reverse string s in place
 void reverse(char *s)
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}

// convert an int to a string
void itoa(int n, char *s)
{
	int i, sign;

	// record sign, make positive
	if ((sign = n) < 0) n = -n;

	i = 0;
	do {	// generate digits in reverse order
		s[i++] = n % 10 + '0'; // get next digit
	} while ((n /= 10) > 0);   // delete it

	if (sign < 0) s[i++] = '-';
	s[i] = '\0';
}


// checks a binary to make sure the length
// is a multiple of 4, if it isn't
// padding the beginning with zeros until it is
//
// note: user will have to free allocated memory
char *pad_bin(char *bin)
{
	int i;
	char *rbin;  // the binary string we will return
	size_t len = strlen(bin);

	// figure out how many zeros to pad
	int p = 4 - len % 4;
	if (p == 4 || p == 0) return bin; // none nedded

	
	int plen = p+len+1;
	rbin = malloc(sizeof(char)*plen);
	if (rbin == NULL) {
		fprintf(stderr, "pad_hex: memory problems\n");
		exit(1);
	}

	for (i = 0; i < p; ++i)
		*rbin++ = '0';  // do the padding
	while (*bin != '\0')
		*rbin++ = *bin++;
	*rbin = '\0';

	// get pointer back to the beginning
	rbin -= plen - 1;

	return rbin;
}

