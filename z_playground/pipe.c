#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	const char	*str = "hello, world!";
	int	pipe_fd[2];
	int	pid;
	size_t	buf;
	char	br[1024];

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit (1);
	}

	if (pid == 0)
	{
		close(pipe_fd[1]);
		buf = read(pipe_fd[0], br, sizeof(br));
		printf("reseved: %s, %zu\n", br, buf);
		close(pipe_fd[0]);
	}
	else
	{
		close(pipe_fd[0]);
		write(pipe_fd[1], str, 13);
		close(pipe_fd[1]);

	}
	return (0);
}