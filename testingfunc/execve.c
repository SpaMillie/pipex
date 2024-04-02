#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (execve("./dup22", argv + 1, NULL) == -1)
		{	
			perror("execve");
			return 1;
		}
		write(1, "no can do\n", 11);
	}
}