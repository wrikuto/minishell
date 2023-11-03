/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:22:25 by wrikuto           #+#    #+#             */
/*   Updated: 2023/11/03 23:00:36 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../inc/minishell.h"

int	analysis_line(char *line)
{
	extern char **environ;
	t_list	*list;
	int	i = 0;
	int	rtn = 0;
	char	*res;
	t_list	*temp;

	list = NULL;
	if (ft_strncmp(line, "env", SIZE_MAX) == 0)
	{
		while (environ[i++] != NULL)
		{
			if (environ[i] == NULL)
				break ;
			ft_printf("%s\n", environ[i]);
		}
	}
	else if (ft_strncmp(line, "exit", SIZE_MAX) == 0)
	{
		free(line);
		exit(0);
	}
	else if (ft_strncmp(line, "pwd", SIZE_MAX) == 0)
		rtn = ft_pwd();
	else
	{
		parse(line, &list);
		res = search_path(list->token);
		if (res)
		{
			free(list->token);
			list->token = res;
			// ft_printf("find path: %s\n", list->token);  // TST
			ft_exec(list);
		}
		free_list(&list);
	}
	return (0);
}

int main(void)
{
	char	*line;
	int i;

	rl_outstream = stderr;
	while(1)
	{
		i = 0;
		line = readline("minishell$ ");
		if (line == NULL)
			return (0) ;
		// if (line)
		// 	add_history(line);
		if (analysis_line(line) == -1)
			exit(0);
		free(line);
	}
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q minishell");
}