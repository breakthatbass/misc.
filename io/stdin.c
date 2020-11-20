// this program is for a reference for when i forget how
// to correctly use read() and write()...which is often
//
// it write to stdout, a question
// reads the user's answer from stdin
// then writes a repsonse to stdout using user's input
//
// write takes 3 arguments:
//	1. what you are writing to (e.g., a var, file, pipe, or stdout)
//	2. what your are getting the data from (probably a buffer var)
//	3. how many bytes in the 'from'(arg 2)
//
// read takes 3 arguments:
//	1. what you are reading from (e.g., stdin, a pipe, var, file )
//	2. where you are storing that data (e.g., probably a buffer var);
//	3. amount of bytes in the 'from' (arg 1)	
//
//	note: you always need a buffer
//	you can't write directly from one thing to another


#include <unistd.h>
#include <string.h>

#define MAXLEN 100

int main(){
	char buf;
	char name[MAXLEN];
	char *question = "what is your name?\n";
	char *greet = "Hello, how are you, ";

	write(STDOUT_FILENO, question, strlen(question));
	write(STDOUT_FILENO, "\n", 1);

	read(STDIN_FILENO, name, MAXLEN);
	write(STDOUT_FILENO, greet, strlen(greet));
	write(STDOUT_FILENO, name, strlen(name));

	return 0;
}
