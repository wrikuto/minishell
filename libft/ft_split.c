/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:51:31 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/28 20:34:44 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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

static size_t	ft_sublen(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static size_t	count_sub(char const *str, char c)
{
	size_t	i;
	size_t	count;
	int		flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		if (str[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	return (count);
}

static char	**set_sub(char const *str, char c, char **ret, size_t sub_n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < sub_n)
	{
		j = 0;
		while (*str == c)
			str++;
		ret[i] = malloc(sizeof(char) * (ft_sublen(str, c) + 1));
		if (ret[i] == NULL)
		{
			free_sub(ret, i);
			return (NULL);
		}
		while (*str != c && *str != '\0')
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

char	**ft_split(char const *s, char c)
{
	size_t	sub_n;
	char	**ret;

	if (!s)
		return (NULL);
	sub_n = count_sub(s, c);
	ret = malloc(sizeof(char *) * (sub_n + 1));
	if (ret == NULL)
		return (NULL);
	if (s[0] == '\0')
		return (ret);
	ret[sub_n] = NULL;
	ret = set_sub(s, c, ret, sub_n);
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