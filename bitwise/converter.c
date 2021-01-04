#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "helpers.h"

#define MAXBIN 64

// binary to decimal converter
uint64_t btod(char *bin)
{
	uint64_t n = 0;		// the decimal number we will return
	/**
	 * x represents each decimal at each binary place.
	 * start with 1 and double it with each loop
	 * 1, 2, 4, 8, 16, 32, 64...
	 * */
	uint64_t x = 1; // base

	int len = strlen(bin)-1;
	// we work backwards because we don't know how many bits
	// might be in our binary number
	int i;
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
char *dtob(uint64_t n)
{
	static char b[MAXBIN];
	int i;

	for (i = 0; n > 0; i++) {
		// convert to string and plug into b array
		itoa((n % 2), &b[i]);
		/** shift bits on place to the right
		* aka divide each decimal by two
		* same as 'n /= 2';
		**/
		n = n >> 1;
	}
	reverse(b);
	return b;
}


int main()
{
	//binary to decimal  tests
	assert(btod("01000001") == 65);
	assert(btod("11111111") == 255);
	assert(btod("11000000111001") == 12345);
	assert(btod("00000000") == 0);
	assert(btod("1011101001000011101101110011111111111") == 99999999999);
	assert(btod("111010011011100000010111100011110111") == 62738495735); 

	// decimal to binary tests
	assert(strcmp(dtob(65), "1000001") == 0);
	assert(strcmp(dtob(255), "11111111") == 0);
	assert(strcmp(dtob(12345), "11000000111001") == 0);
	assert(strcmp(dtob(99999999999), "1011101001000011101101110011111111111") == 0);
	assert(strcmp(dtob(62738495735), "111010011011100000010111100011110111") == 0);

	return 0;
}
