#include <unistd.h>

int	main(void)
{
	if (access("~/getnextlline/greet.txt", W_OK) != -1)
		write(1, "access granted\n", 16);
	else
		write(1, "access denied\n", 15);
}