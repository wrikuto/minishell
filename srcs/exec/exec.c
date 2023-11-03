/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:52:28 by wrikuto           #+#    #+#             */
/*   Updated: 2023/11/03 22:25:55 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void fatal_error(const char *msg) __attribute__((noreturn));

void fatal_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Fatal Error: %s\n", msg);
	exit(1);
}


char	**set_argv(t_list	*list)
{
	char	**argv;
	size_t	count;
	size_t	i;
	t_list	*temp = list;

	i = 0;
	count = get_listsize(list);
	argv = malloc(sizeof(char *) * (count + 1));
	argv[count] = NULL;
	while (list && i < count)
	{
		argv[i] = list->token;
		list = list->next;
		i++;
	}
	return (argv);
}


int ft_exec(t_list *list)
{
	// char		*cmd = "ls";
	extern char **environ;
	char		**argv;
	pid_t		pid;
	int			wstatus;



	argv = set_argv(list);
	pid = fork();
	if (pid < 0)
		fatal_error("fork");
	else if (pid == 0)
	{
		// 息子
		execve(list->token, argv, environ);
		free(argv);
		fatal_error("execve");
	}
	else
	{
		// 親父
		wait(&wstatus);
		free(argv);
		return (WEXITSTATUS(wstatus));
	}
}

// int ft_exec(char *cmd)
// {
// 	// char		*cmd = "ls";
// 	extern char **environ;
// 	char		*argv[] = {cmd, NULL};
// 	pid_t		pid;
// 	int			wstatus;

// 	pid = fork();
// 	if (pid < 0)
// 		fatal_error("fork");
// 	else if (pid == 0)
// 	{
// 		// 息子
// 		execve(cmd, argv, environ);
// 		fatal_error("execve");
// 	}
// 	else
// 	{
// 		// 親父
// 		wait(&wstatus);
// 		return (WEXITSTATUS(wstatus));
// 	}
// }