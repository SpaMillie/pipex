#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
		int fd = open ("outfile", O_WRONLY);
		int pid = fork();
		if (pid == 0)
		{
			dup2(fd, STDOUT_FILENO);
			execve(argv[1], argv + 1, envp);
			perror("execve");
		}
	}
}

/* 
execve is a system call
 - it takes three args
 - the first argument is the path to the command
 - the second (set) of args is the flags and other
 - the last set is the env variable
 */
