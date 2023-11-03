/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:00:58 by wrikuto           #+#    #+#             */
/*   Updated: 2023/11/03 23:15:42 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_cd(char **path)
{
	char	*pwd;
	char	*newpwd;
	char	path[PATH_MAX];

	if (path == NULL)
	{
		home = getenv("HOME");
		if (home == NULL)
		{
			errno_error("No value in $HOME.")
			return (-1);
		}
			
	}

	
}