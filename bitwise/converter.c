#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

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


char *btoh(char *bin) {
	// all the symbols we'll need
	static const char *h = "123456789ABCDEF";

	int i, n;
	char *hex;	// string to return

	char *nbin = pad_bin(bin);
	int len = strlen(nbin);
	int hexlen = len/4; // need one hex for every 4 bins
	hexlen++;

	hex = malloc(sizeof(char)*hexlen);

	int p = 0;
	char buf[5];
	for (i = 0; i < len; i+=4) {
		// copy over 4 bins from binary str
		memcpy(buf, nbin, 4);
		// make it a proper str
		buf[4] = '\0';
		// convert to decimal
		n = btod(buf) - 1;
		// add to hex str
		*hex++ = *(h+n);
		// move ahead four spots for the next conversion
		nbin += 4;
	}
	*hex = '\0';
	// move pointer back to start
	hex -= hexlen-1;
	return hex;
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
	
	// tests for pad_bin function (helper function for btoh)
	assert(strcmp(pad_bin("101"), "0101") == 0);
	assert(strcmp(pad_bin("1001"), "1001") == 0);
	assert(strcmp(pad_bin("111111"), "00111111") == 0);
	assert(strcmp(pad_bin("11111111111111"), "0011111111111111") == 0);
	assert(strcmp(pad_bin("11111111111111111111111"), "011111111111111111111111") == 0);

	// tests for binary to hex
	assert(strcmp(btoh("101"), "5") == 0);
	assert(strcmp(btoh("1001"), "9") == 0);
	assert(strcmp(btoh("111111"), "3F") == 0);
	assert(strcmp(btoh("11111111111111111111"), "FFFFF") == 0);
	assert(strcmp(btoh("10101011110011011110"), "ABCDE") == 0);

	return 0;
}
