/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:52:28 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/10 16:02:38 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/global.h"

void fatal_error(const char *msg) __attribute__((noreturn));

void fatal_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Fatal Error: %s\n", msg);
	exit(1);
}

int interpret(char *line)
{
	extern char **environ;
	char		*argv[] = {line, NULL};
	pid_t		pid;
	int			wstatus;

	pid = fork();
	if (pid < 0)
		fatal_error("fork");
	else if (pid == 0)
	{
		// 息子
		execve(line, argv, environ);
		fatal_error("exrcve");
	}
	else
	{
		// 親父
		wait(&wstatus);
		return (WEXITSTATUS(wstatus));
	}
}