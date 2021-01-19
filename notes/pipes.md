# pipes
### pipe table of contents
1. [`pipe`](#pipe)
2. [`dup2`](#dup2)

## `pipe`
This is a simple example of setting up a pipe between a parent and child process. First we create the `pipe` and then `fork` the process. by using the `read` and `write` system calls, we are able to communicate between the two processes.  

After opening the pipe with `pipe(fd)` we access the processes in a conditional statement through the integer returned by `fork`. An error returns an integer of less than 0. The parent, or main, process is greater than 0. The new child process returns 0.  

In the parent process we read from `stdin`, store what we get in `buffer`, then write it into the write end of the pipe. In the child process we read from the pipe, store what we read in `out` and do that in the `n` variable because `n` will give us the size of the string. Then we use `write` to write to `stdout`.  

```C
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int main()
{
	int n;

    	// the pipe is used with an array of two elements
    	// one element represents to write end and the other, the read end
	int fd[2];
    	pid_t pid;

    	// buffers
    	// we can use one variable and overwrite it
    	// but i have two here to prevent potential confusion
	char buffer[MAXLINE];
    	char out[MAXLINE];

    	// create the pipe with pipe() and error check
	if (pipe(fd) < 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

    	// create child process with fork() and error check
	if ((pid = fork()) < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid > 0)	{ // parent process
        	// close read end of pipe
		close(fd[0]);
        	// read from stdin into line
		read(STDIN_FILENO, buffer, MAXLINE);
        	// write buffer into the write end of pipe
		write(fd[1], buffer, strlen(buffer));
	} else {  // child process
        	// close write end of pipe
		close(fd[1]);
        	// read from pipe into out and store size in n
		n = read(fd[0], out, MAXLINE);
        	// write contents of out to stdout (print it)
		write(STDOUT_FILENO, out, n);
	}
	return 0;
}
```

## `dup2`
`dup2` changes the where the output or input of an entire process goes or comes from. Below we create two child processes, `pid1` and `pid2`, and set the `stdout` of `pid1` to go into a `pipe` then call `exec` which runs the command `ls -l -h`. Normally the output would go right to `stdout` and print to the terminal but instead we've set the `stdout` of that process to go into the `pipe` so we get no results in the terminal when the process runs.  

In `pid2` we use `dup2` to set the `stdin` in that process to come form the `pipe` that we wrote into in the `pid1` process. The we use `exec` to run the `wc -l` command which requires something from `stdin` to return a result. Our process has its `stdin` coming from the `pipe` so `wc -l` gets the `stdout` from `ls -l -h` and it then prints the results to the terminal.  

To save space there is no error check on `fork` or `pipe`.

```C
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid1, pid2;
	int pipefd[2];

	// the two commands we'll execute
	// we will peipe the output of 'ls' into 'wc'
	// and count the number of lines present
	char *argv1[] = {"ls", "-l", "-h", NULL};
	char *argv2[] = {"wc", "-l", NULL};

	// create a pipe
	pipe(pipefd);

	// create our first process
	pid1 = fork();
	if (pid1 == 0) {
		// hook stdout up to the write end of the pipe
		// and close the read end of the pipe which
		// is no longer needed by this process
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);

		/*
		 * exec `ls -l -h`. if the exec fails, notify the user
		 * and exit. Note that the execvp variant first
		 * seaches the $PATH before calling execve.
		 * */
		execvp(argv1[0], argv1);
		perror("exec");
		return 1;
	}

	// create our second process
	pid2 = fork();
	if (pid2 == 0) {
		/* hook stdin up to the read end of the pipe nd close
		 * the write end of the pipe which is no longer needed
		 * by this process
		 * */
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);

		// similarly we exec `wc -l`
		execvp(argv2[0], argv2);
		perror("exec");
		return 1;
	}

	/**
	 * close both ends of the pipe. the respective
	 * read/write ends of the pipe persist in the two
	 * processes created above (and happened to be tying
	 * stdout of the first processes to stdin of the second)
	 * */
	close(pipefd[0]);
	close(pipefd[1]);
	
	int status;
	// wait for everything to finish and exit
	waitpid(pid1, &status, WUNTRACED);
	waitpid(pid2, &status, WUNTRACED);
	return 0;
}
```