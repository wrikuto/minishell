/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:29:53 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/24 17:04:15 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_dblpointer(char **split)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (split[i++] != NULL)
		free(split[i]);
	free(split);
}

void	print_split(char **split)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (split[i++] != NULL)
		ft_printf("%s\n", split[i]);
}

void	syntax_analyze(char	*str)
{
	char	**split;
	size_t	i;
	
	i = 0;
	split = input_spliter(str);
	print_split(split);
	free_dblpointer(split);
	
}

// int main()
// {
// 	char	*str = "ps aux | grep apache";
// 	syntax_analyze("ps aux | grep apache");


// 	return (0);
// }