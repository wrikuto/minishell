/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:22:25 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/18 18:10:40 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../inc/minishell.h"

int	analysis_line(char *line, char **environ)
{
	int	i = 0;

	if (ft_strncmp(line, "envi", SIZE_MAX) == 0)
	{
		while (environ[i++] != NULL)
			printf("%s\n", environ[i]);
	}
	else if (ft_strncmp(line, "exit", SIZE_MAX) == 0)
	{
		free(line);
		return (-1);
	}
	return (0);
}

int main(void)
{
	char	*line;
	extern char **environ;	
	int i;

	rl_outstream = stderr;
	while(1)
	{
		i = 0;
		line = readline("minishell$ ");
		if (line == NULL)
			return (0) ;
		if (line)
			add_history(line);
		if (analysis_line(line, environ) == -1)
			exit(0);
		// if (line == NULL)
		// 	break ;
		// if (ft_strncmp(line, "env", SIZE_MAX) == 0)
		// {
		// 	while (environ[i++] != NULL)
		// 		printf("%s\n", environ[i]);
		// }
		// else if (ft_strncmp(line, "exit", SIZE_MAX) == 0)
		// {
		// 	free(line);
		// 	exit(0);
		// }
			
		// if (*line)
		// 	add_history(line);
		// // TODO: intepret line as a command
		free(line);
	}
	exit(0);
}
