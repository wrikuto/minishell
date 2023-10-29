/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:23:41 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/28 21:05:31 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../../inc/minishell.h"

void    print_table(char **table)
{
        size_t  i = 0;

        while (table[i] != NULL)
        {

                printf("%s\n", table[i]);
                i++;
        }
}

// char	**get_splited_path(const char *path)
// {
// 	char	**split;

// 	split = ft_split(path);
// 	if (split == NULL)
// 	{
// 		ft_printf("split fail!\n");
// 		return (NULL);
// 	}
// 	return (split)
// }

char	*search_path(const char *filename)
{
	char	path[PATH_MAX];
	char	**split;
	char	*dup;
	size_t	i;

	i = 0;
	split = ft_split(getenv("PATH"), ':');	
	if (split == NULL)
		return (NULL);
	while(split[i] != NULL)
	{
		ft_strlcpy(path, split[i], PATH_MAX);
		ft_strlcat(path, "/", PATH_MAX);
		ft_strlcat(path, filename, PATH_MAX);
		if (access(path, X_OK) == 0)
		{
			dup = ft_strdup(path);
			free_dbl(split);
			return (dup);
		}
		i++;
	}
	free_dbl(split);
	ft_printf("no such path.\n");
	return (NULL);
}