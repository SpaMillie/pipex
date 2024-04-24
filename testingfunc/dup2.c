//dup2 is used to replace/duplicate (open) fd's
//useful when you want to redirect output from stdout
//STDOUT_FILENO is an int with a value of 1 i.e. the terminal's fd

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("testing.txt", O_RDWR | O_CREAT, 0777);
	dup2 (fd, STDOUT_FILENO);
	write(1, "chekc\n", 7);
	close (fd);
	write(1, "This text is new\n", 18); //the order doesnt seem to matter? 1st close and then write or write and then close, same result
	write(1, "This text is newer\n", 20);
	close(STDOUT_FILENO);
	if (write(1, "jjfkrej\n", 9) == -1)
		perror("write");
}
