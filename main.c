/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:22:25 by wrikuto           #+#    #+#             */
/*   Updated: 2023/09/06 13:29:42 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"inc/builtin.h"



int main(void)
{
	char	*line;

	rl_outstream = stderr;
	while(1)
	{
		line = readline("minishell$ ");
		if (line == NULL);
			break ;
		if (*line)
			add_history(line);
		// TODO: intepret line as a command
		free(line);
	}
	exit(0);
}