#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
		//printf("The parent: %d\n", getpid());
	else
		//printf("The child: %d\n", getpid());
}