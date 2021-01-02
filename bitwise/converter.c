#include <stdio.h>
#include <string.h>
#include <assert.h>


// binary to decimal converter
int btod(char *bin)
{
	int n = 0;		// the decimal number we will return
	
	/**
	 * raise represent each decimal at each binary place
	 * start with 1 and double it with each loop
	 * 1, 2, 4, 8, 16, 32, 64, 255...
	 * */
	int raise = 1;

	int len = strlen(bin)-1;
	// we work back because we don't know how many bits
	// might be in our binary number
	for (int i = len; i >= 0; i--) {
		// if there's a 1, add our current raise value to n
		if (bin[i] == '1') n += raise;
		raise *= 2;
	}
	return n;
}


int main()
{
	// tests
	assert(btod("01000001") == 65);
	assert(btod("11111111") == 255);
	assert(btod("11000000111001") == 12345);
	assert(btod("00000000") == 0);

	return 0;
}
