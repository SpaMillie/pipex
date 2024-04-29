#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char *str[] = {"outfile", NULL};
	execve(str[0], str, NULL);
	perror("execve");
}

/* 
execve is a system call
 - it takes three args
 - the first argument is the path to the command
 - the second (set) of args is the flags and other
 - the last set is the env variable
 */
