#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		sleep(1);
		write(1, "\nA child.\n", 11);
		sleep(1);
	}
	else
	{
		write(1, "There's only 1 thing worse than a rapist: ", 43);
		wait(NULL);
		write(1, "NO!", 4);
	}
	exit(EXIT_SUCCESS);	
}
