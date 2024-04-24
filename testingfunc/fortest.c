#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd[2][2];
	pid_t	pid;
	// int		process_n; (add to the h)

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
			log->process_n = 0;
			close(fd[0][1]);
			dup2(fd[0][0], STDOUT_FILENO);
			execve(log->path, log->execve_args[0], NULL);
			perror("pipex: execve");
			//free everything? no
			exit(EXIT_FAILURE);
		}
		else
		{
			while (log->process_n < argc - 4)
			{
				log->process_n++;
				if (log->process_n % 2 != 0)
				{
					pipe (fd[1]);


				}
			}
		}
	}
}
