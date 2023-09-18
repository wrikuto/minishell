#include <unistd.h> // fork(), execve()
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int	pid;
	int status;
	char	*str;

	pid = fork();
	if (pid == -1)
		return (0);
	
	if (pid == 0)
	{
		printf("hello\n");
		exit (42);
	}

	wait(&status);

	if (WIFEXITED(status))
		printf("Child process has been finished correctly. (status = %d)\n", WEXITSTATUS(status));
	else
		printf("oof!\n");
	printf("finish\n");
	return (0);
}