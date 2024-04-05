#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	void *buff = NULL;
	int	fd = open("test", O_RDONLY);
	if (fd == -1)
		perror("test");
	if (read (fd, buff, 6) == -1)
		perror("test");
	close(fd);

	// int i = 0;

	// while (i < 107)
	// 	printf("%s\n", strerror(i++));
}