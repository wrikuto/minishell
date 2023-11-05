/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:23:38 by wrikuto           #+#    #+#             */
/*   Updated: 2023/11/05 14:05:16 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../../inc/minishell.h"

// 環境変数を取得
int get_environ(t_list **env)
{
	extern char **environ;
	size_t	i;
	
	i = 0;
	while (environ[i] != NULL)
	{
		add_listback(env, create_list(strdup(environ[i])));
		i++;
	}
	return (0);
}

size_t	pathname_len(const char *str)
{
	size_t	i;

	i = 0;
	while (s[i] != '=' && s[i] != '\0')
		i++;

	return (i);
}

// パス名に一致したenvのポインタを返す。
char	*get_matchpath(t_list *env, char *findname)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (env)
	{
		len = pathname_len(env->str);
		if (ft_strncmp(env->str, findname, len) == 0)
			return(env->str + len + 1);
		env = env->next;
	}
	ft_printf("No such path name.\n")
	return (NULL);
}


