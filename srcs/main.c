/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:22:25 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/31 17:59:22 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../inc/minishell.h"

int	analysis_line(char *line)
{
	extern char **environ;	
	int	i = 0;
	int	rtn = 0;
	char	*res;

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
		res = search_path(line);
		if (res)
		{
			ft_printf("find path: %s\n", res);
			ft_exec(res);
			free(res);
		}
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