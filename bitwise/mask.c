#include <stdio.h>
#include <stdlib.h>

int main()
{
	// binaries can be predicated with "0b"
	// or they can be left out
	int bin = 0b10010011;
	int mask = 0b00000011;
	
	int n = bin & mask;

	printf("%d\n", n);

	bin = 0b01101011;
	mask = 0b00011000;

	n = bin & mask;
	// using & here wil produce the binary: 00001000
	// and shifting the bits over 3 spots produces:
	// 000000001 which is just 1 in decimal
	n = n >> 3;

	printf("%d\n", n);

	// a blnk binary -> 0 in decimal
	bin = 00000000;
	// we we set the ***000** bits in 'bin'
	int y = 5; // which is 101 in binary
	
	/** shift the bits over 2 to create our mask
	* or get the bits in the right spot to set
	* here the mask is abstract
	*
	* but it would look like this after the bits are shifted
	* mask = 00010100
	* pre shift it was simply 101, or 5
	*
	* ORing the mask over the 00000000 binary
	* is actually the same as just shifting the 101 over 2 bits...
	* which we needed to do to get the mask
	* this is situational though
	* */
	bin |= (y << 2);

	printf("%d\n", bin);

	/*********************
	 * CLEARING A BIT
	 * *******************/

	// clearing a bit
	// for this we use OR and ~
	bin = 0b10111011;

	mask = 0b00100000;
	// basically, we want to switch 'on' or 'off'
	// that third bit in from the left
	// we 'fip' the mask
	//mask = ~mask;
	n = bin & ~(mask);
	// now our bin is 10011011
	// we've gone from 187 to 155
	// the abstract way to do this is this
	
	y = 1;  // y is 1 because we're only dealing with one bit 
	bin &= ~(y << 5); // we move that one bit to the right spot in the binary
	// then we flip it with '~' the we AND it. same as above with the mask

	printf("%d\n", n);
	printf("%d\n", bin);


	/***********************************
	 * TOGGLING BITS
	 * ********************************/

	// for this we are going to use XOR or '^'
	bin = 0b10111011;  // 187
	mask = 0b00100000;

	//we have the same binary and mask as previous
	n = bin ^ mask;
	printf("%d\n", n);

	// now the abstract way
	// y is still 1, which we want
	bin ^= (y << 5);

	printf("%d\n", bin);

	// then we can flip it back again
	bin ^= (y << 5);  // should it's back to 187

	printf("%d\n", bin);



	return 0;
}
