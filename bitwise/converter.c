#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "helpers.h"

#define MAXBIN 64

// binary to decimal converter
int btod(char *bin)
{
	int i;
	int n = 0;		// the decimal number we will return
	
	/**
	 * x represents each decimal at each binary place.
	 * start with 1 and double it with each loop
	 * 1, 2, 4, 8, 16, 32, 64, 255...
	 * */
	int x = 1;

	int len = strlen(bin)-1;
	// we work backwards because we don't know how many bits
	// might be in our binary number
	for (i = len; i >= 0; i--) {
		// if there's a 1, add our current x value to n
		if (bin[i] == '1') n += x;
		/** shift bits 1 place to the left
		 * aka multply each decimal by 2
		 **/
		x = x << 1; 
	}
	return n;
}



// decimal to binary converter
char *dtob(int n)
{
	static char b[MAXBIN];
	int i;

	for (i = 0; n > 0; i++) {
		itoa(n%2, &b[i]);
		n = n >> 2;
	}
	return b;
}


int main()
{
	//binary to decimal  tests
	assert(btod("01000001") == 65);
	assert(btod("11111111") == 255);
	assert(btod("11000000111001") == 12345);
	assert(btod("00000000") == 0);

	// decimal to binary tests
	assert(strcmp(dtob(65), "1000001") == 0);
	assert(strcmp(dtob(255), "11111111") == 0);
	//assert(strcmp(dtob(12345), "11000000111001") == 0); // fails

	// check what it is
	char *t = malloc(sizeof(char)*64);
	t = dtob(12345);
	printf("%s\n", t);
	

	return 0;
}
