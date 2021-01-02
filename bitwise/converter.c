#include <stdio.h>
#include <string.h>
#include <assert.h>


// binary to decimal converter
int btod(char *bin)
{
	int n = 0;
	int count = 0;
	int raise = 1;
	int len = strlen(bin)-1;
	for (int i = len; i >= 0; i--) {
		if (bin[i] == '1') n += raise;
		raise *= 2;
	}
	return n;
}


int main()
{
	char *b = "01000001";
	int x = btod(b);
	assert(x == 65);	
}
