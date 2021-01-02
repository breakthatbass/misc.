 /**
* these functions comes from page 62 and 64 of the second
* edition of K&R. it's a bit of my own variant
* but it's the same logic which I copied
* */

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
	reverse(s);	
}
