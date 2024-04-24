#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd[2][2];
	pid_t	pid;
	int		n;

	if (pipe(fd[0]) == -1)
	{
		perror("pipex: pipe");
		//free everything?
		exit(EXIT_FAILURE); //skontaj konacno
	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror("pipex: fork");
			//free everything?
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			n = 0;
			
		}
		else
		{

		}
	}
}
