/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_spliter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:51:31 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/29 17:23:38 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// this is a func when malloc failed.
static void	free_sub(char **ret, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(ret[j]);
		j++;
	}
	free(ret);
}

// Get the number of characters in a word.
static size_t	ft_sublen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

// Get the number of words.
static size_t	count_sub(char const *str)
{
	size_t	i;
	size_t	count;
	int		flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && flag == 0)
		{
			count++;
			flag = 1;
		}
		if ((str[i] == ' ' || str[i] == '\t') && flag == 1)
			flag = 0;
		i++;
	}
	return (count);
}

static char	**set_sub(char const *str, char **ret, size_t sub_n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < sub_n)
	{
		j = 0;
		while (*str == ' ' || *str == '\t')
			str++;
		ret[i] = malloc(sizeof(char) * (ft_sublen(str) + 1));
		if (ret[i] == NULL)
		{
			free_sub(ret, i);
			return (NULL);
		}
		while (*str != ' ' && *str != '\t' && *str != '\0')
		{
			ret[i][j] = *str;
			j++;
			str++;
		}
		ret[i][j] = '\0';
	i++;
	}
	return (ret);
}

// primary function
char	**input_spliter(char const *s)
{
	size_t	sub_n;
	char	**ret;

	if (!s)
		return (NULL);
	sub_n = count_sub(s);
	ret = malloc(sizeof(char *) * (sub_n + 1));
	if (ret == NULL)
		return (NULL);
	if (s[0] == '\0')
		return (ret);
	ret[sub_n] = NULL;
	ret = set_sub(s, ret, sub_n);
	return (ret);
}

// #include <stdio.h>

// int main(int argc, char **argv)
// {
// 	char	**str;
// 	char	*moji = "\0aa\0bbb";
// 	int i = 0;

// 	str = ft_split(moji, '\0');

// 	if (str == NULL)
// 	{
// 		printf("ERROR!\n");
// 		return (1);
// 	}
// 	while (str[i] != NULL)
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}

// 	i = 0;
// 	while (str[i] != NULL)
// 	{
// 		free (str[i]);
// 		i++;
// 	}
// 	free(str);

// 	return (0);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }