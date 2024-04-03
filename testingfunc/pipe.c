#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) 
{
    int		fd[2]; // File descriptors for the pipe
    pid_t	pid; // Process ID variable
	char	*args[3];
	char	buffer[1024];
    ssize_t	bytes_read;

	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
    // Creating the pipe
    if (pipe(fd) == -1)
	{
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    // Forking a child process
    pid = fork();
    if (pid == -1)
	{
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) // Child process
	{
        close(fd[0]); // Close the read end of the pipe
        dup2(fd[1], STDOUT_FILENO);  // Redirect stdout to the write end of the pipe
		write(fd[1], "Heyyah\n",8);
		close(fd[1]); // Close the right end oof pipe
		exit(EXIT_SUCCESS);
        // execve("/bin/ls", args, NULL);// Execute the "ls" command
        // perror("execve"); // This line will be reached only if execve fails
        // exit(EXIT_FAILURE);
    }
	else // Parent process
	{
		pid = fork();
		if (pid == -1)
		{
        	perror("fork");
        	exit(EXIT_FAILURE);
		}
		close(fd[1]); // Close the write end of the pipe
		if (pid == 0)
		{
        	// Read from the read end of the pipe
			dup2(fd[0], STDIN_FILENO);
        	while ((bytes_read = read(fd[0], buffer, sizeof(buffer))) > 0)
            	write(STDOUT_FILENO, buffer, bytes_read); // Write to stdout
        	if (bytes_read == -1) 
			{
            	perror("read");
            	exit(EXIT_FAILURE);
        	}
        	// Wait for the child process to finish
        	wait(NULL);
			close (fd[0]);
			exit(EXIT_SUCCESS);
		}
    }
    return 0;
}
