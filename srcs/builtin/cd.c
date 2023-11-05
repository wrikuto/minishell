/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:00:58 by wrikuto           #+#    #+#             */
/*   Updated: 2023/11/04 14:25:05 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// int set_path()
// {

// 	if (path == NULL)
// 	{
// 		home = getenv("HOME");
// 		if (home == NULL)
// 		{
// 			errno_error("No value in $HOME.")
// 			return (-1);
// 		}
// 	}
// }

int set_oldpwd(char *oldpwd)
{
	if (oldpwd == NULL)
		
}

int set_path(char *path, char *argv)
{
	char	*home;
	
	if (argv == NULL)
	{
		home = getenv("HOME");
		if (home == NULL)
		{
			errno_error("$HOME is NULL. failed getenv.")
			return (-1);
		}
		ft_strlcpy(path, getenv("HOME"), PATH_MAX);
	}
	else
		ft_strlcpy(path, argv, PATH_MAX);
	return (0);
}

int	ft_cd(char **path)
{
	char	*oldpwd;
	char	path[PATH_MAX];

	oldpwd = getenv("PWD");
	if (set_path(path, argv[1]) == -1)
		return (-1);
	if (chdir(path) != 0)
	{
		errno_error("cd failed.");
		return (-1);
	}
	
	
}

