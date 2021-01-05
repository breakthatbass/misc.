#ifndef __HELPERS_H_
#define __HELPERS_H_

// reverse string s in place
void reverse(char *s);
 
 // convert an int to a string
void itoa(int n, char *s);

// pad a binary with zeros until it is a multiple of four
// for use with converting binary to hex
char *pad_bin(char *bin);

#endif
