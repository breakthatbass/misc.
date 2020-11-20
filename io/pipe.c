//
// a reference for using pipe() 
//
// here there is a parent and child process
// the parent takes from stdin and sends that
// data through a pipe to the chld who reads from it
// and writes it to stdou
//
// with reading from stdin in to sending it through a pipe,
// it must be first read and stored in a buffer var
// you cannot write to a pipe directly from stdin
// ...something easy for me to look over

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int main()
{
	int n;
	int fd[2];	// pipe
	pid_t pid;
	char line[MAXLINE];

	if (pipe(fd) < 0) 
	{
		fprintf(stderr, "pipe failed\n");
		exit(1);
	}

	if ((pid = fork()) < 0) 
	{
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (pid > 0)	// parent process
	{
		close(fd[0]);
		read(STDIN_FILENO, line, MAXLINE);
		write(fd[1], line, strlen(line));
	} 
	else	// child process 
	{  
		close(fd[1]);
		n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line, n);
	}
	return 0;
}

