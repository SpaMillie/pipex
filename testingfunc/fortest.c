#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	spawning(t_captains *log, int fd_n1, int fd_n2)
{
	int	pid;

	if (pipe(log->fd[fd_n1]) == -1)
	{
		perror("pipex: pipe");
		//free everything?
		exit(EXIT_FAILURE); //skontaj konacno
	}
	pid = fork();
	if (pid == -1)
	{
		perror("pipex: fork");
		//free everything?
		exit(EXIT_FAILURE);
	}	
	else if ()
}

int	main(int argc, char **argv)
{
	int		fd[2][2]; //can this be const for norm?
	pid_t	pid;
	int		i;
	int		j;
	// int		process_n; (add to the h)

	if (pipe(fd[0]) == -1)
	{
		perror("pipex: pipe");
		//free everything?
		exit(EXIT_FAILURE); //skontaj konacno
	}
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
		if (dup2(fd[0][0], STDOUT_FILENO) == -1)
		{
			perror("pipex: dup2");
			exit(EXIT_FAILURE);
		}
		execve(log->path, log->execve_args[0], env);
		perror("pipex: execve");
		//free everything? no
		exit(EXIT_FAILURE);
	}
	while (log->process_n < argc - 4)
	{
		log->process_n++;
		if (log->process_n % 2 != 0)
		{
			i = 1;
			j = 0;
		}
		else
		{
			i = 0;
			j = 1;
		}
		if (pipe(fd[i]) == -1)
		{
			perror("pipex: pipe");
			//free everything?
			exit(EXIT_FAILURE); //skontaj konacno
		}
		if (dup2(fd[i][0], fd[j][0]) == -1)
		{
			perror("pipex: dup2");
			exit(EXIT_FAILURE);
		}
		close(fd[i][0]);
		pid = fork();



		}
		else
		{
			if (pipe(fd[0]) == -1)
			{
				perror("pipex: pipe");
				//free everything?
				exit(EXIT_FAILURE); //skontaj konacno
			}
		}
	}
}
