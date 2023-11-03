/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:10:17 by wrikuto           #+#    #+#             */
/*   Updated: 2023/11/03 21:53:51 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../../inc/minishell.h"

// list utils


void	free_list(t_list **list)
{
	t_list	*temp;

	if (list == NULL)
		return ;
	while (*list != NULL)
	{
		temp = (*list)->next;
		free((*list)->token);
		free(*list);
		*list = temp;
	}
}

size_t	get_listsize(t_list *list)
{
	size_t	lstsize;

	lstsize = 0;
	while (list != NULL)
	{
		lstsize++;
		list = list->next;
	}
	return (lstsize);
}

t_list	*find_listlast(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

// ----------
// create list

void	add_listback(t_list **list, t_list *new)
{
	if (list == NULL || new == NULL)
		return ;
	if (*list == NULL)
		*list = new;
	else
		find_listlast(*list)->next = new;
}


t_list	*create_list(char *pointer)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->token = pointer;
	new_node->next = NULL;
	return (new_node);
}


// int main()
// {
// 	size_t	i = 0;
// 	t_list	*list = NULL;
// 	char	*str = "hello";


// 	while (i < 3)
// 	{
// 		ft_lstadd_back(&list, ft_lstnew(str));
// 		i++;
// 	}

// 	while (list != NULL)
// 	{
// 		printf("%s\n", (char *)list->data);
// 		list = list->next;
// 	}

	
// 	// printf("%s\n", (char *)list->data);
// 	free(list);
// 	return (0);
// }