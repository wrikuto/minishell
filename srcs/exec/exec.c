/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:52:28 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/28 21:57:34 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void fatal_error(const char *msg) __attribute__((noreturn));

void fatal_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Fatal Error: %s\n", msg);
	exit(1);
}

int ft_exec(char *cmd)
{
	// char		*cmd = "ls";
	extern char **environ;
	char		*argv[] = {cmd, NULL};
	pid_t		pid;
	int			wstatus;

	pid = fork();
	if (pid < 0)
		fatal_error("fork");
	else if (pid == 0)
	{
		// 息子
		execve(cmd, argv, environ);
		fatal_error("execve");
	}
	else
	{
		// 親父
		wait(&wstatus);
		return (WEXITSTATUS(wstatus));
	}
}