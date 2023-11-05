/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:23:41 by wrikuto           #+#    #+#             */
/*   Updated: 2023/11/05 14:03:58 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../../inc/minishell.h"

char	*search_path(const char *filename, t_list *env)
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

int main()
{
	t_list	*env;

	get_environ(&env);
	
}

// char	*search_path(const char *filename)
// {
// 	char	path[PATH_MAX];
// 	char	**split;
// 	char	*dup;
// 	size_t	i;

// 	i = 0;
// 	split = ft_split(getenv("PATH"), ':');	
// 	if (split == NULL)
// 		return (NULL);
// 	while(split[i] != NULL)
// 	{
// 		ft_strlcpy(path, split[i], PATH_MAX);
// 		ft_strlcat(path, "/", PATH_MAX);
// 		ft_strlcat(path, filename, PATH_MAX);
// 		if (access(path, X_OK) == 0)
// 		{
// 			dup = ft_strdup(path);
// 			free_dbl(split);
// 			return (dup);
// 		}
// 		i++;
// 	}
// 	free_dbl(split);
// 	ft_printf("no such path.\n");
// 	return (NULL);
// }