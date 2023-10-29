/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:10:17 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/29 17:18:06 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../../inc/minishell.h"

// list utils

void	clear_list(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

int	get_listsize(t_list *lst)
{
	size_t	lstsize;

	lstsize = 0;
	while (lst)
	{
		lstsize++;
		lst = lst->next;
	}
	return (lstsize);
}


t_list	*find_listlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// ----------
// create list

void	add_listback(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}


t_list	*create_list(void *data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}


int main()
{
	size_t	i = 0;
	t_list	*list = NULL;
	char	*str = "hello";


	while (i < 3)
	{
		ft_lstadd_back(&list, ft_lstnew(str));
		i++;
	}

	while (list != NULL)
	{
		printf("%s\n", (char *)list->data);
		list = list->next;
	}

	
	// printf("%s\n", (char *)list->data);
	free(list);
	return (0);
}