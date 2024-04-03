#include <unistd.h>

int	main(void)
{
	int	result;

	result = unlink("example.txt");
	if (result == 0)
		write(1, "file deleted\n", 14);
	else
		write(1, "fie not deleted\n", 17);
}