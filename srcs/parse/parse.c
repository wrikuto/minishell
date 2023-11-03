/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:29:53 by wrikuto           #+#    #+#             */
/*   Updated: 2023/11/03 22:26:39 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

size_t	size_of_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

static char	*get_token(char *str, size_t count)
{
	size_t	i;
	char	*token;
	
	i = 0;
	token = malloc(sizeof(char) * (count + 1));
	if(token == NULL)
		return (NULL);
	token[count] = '\0';
	while (i < count)
	{
		token[i] = str[i];
		i++;
	}
	return (token);
}

static void	set_token(char *token, t_list **head)
{
	t_list	*new;

	new = create_list(token);
	add_listback(head, new);

}

void	parse(char *line, t_list **list)
{
	size_t	count;

	count = 0;
	line += size_of_space(line);
	while(*line != '\0')
	{
		count = 0;
		while (line[count] != ' ' && line[count] != '\t' && line[count] != '\0')
			count++;
		set_token(get_token(line, count), list);
		line += count;
		if (*line == '\0')
			return ;
		line += size_of_space(line);
	}
}


// static t_list	*tokenize(char *line)
// {
// 	size_t	count;
// 	t_list	*head;

// 	count = 0;
// 	head = NULL;
// 	line += size_of_space(line);
// 	while(*line != '\0')
// 	{
// 		count = 0;
// 		while (line[count] != ' ' && line[count] != '\t')
// 			count++;
// 		set_token(get_token(line, count), &head);
// 		line += count;
// 		line += size_of_space(line);
// 	}
// 	return (head);
// }

// t_list	*parse(char	*line)
// {
// 	size_t	i;
// 	t_list	*head;
	
// 	i = 0;
// 	head = NULL;
// 	head = tokenize(line);
	
// 	return (head);	
// }

// int main()
// {
// 	// char	*str = "ls -f"; 
// 	t_list	*list = NULL;
// 	t_list	*head;
	
// 	parse("ls -f", &list);
// 	head = list;
// 	while (list != NULL)
// 	{
// 		printf("%s\n", list->token);
// 		list = list->next;
// 	}
// 	free_list(&head);

// 	return (0);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
