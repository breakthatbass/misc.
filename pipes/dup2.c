#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
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
