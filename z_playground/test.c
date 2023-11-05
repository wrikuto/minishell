/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:47:21 by wrikuto           #+#    #+#             */
/*   Updated: 2023/11/04 18:13:30 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "check.h"

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/stat.h>
# include <signal.h>


void	free_list(t_list **list)
{
	t_list	*temp;

	if (list == NULL)
		return ;
	while (*list != NULL)
	{
		temp = (*list)->next;
		free((*list)->str);
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
	new_node->str = pointer;
	new_node->next = NULL;
	return (new_node);
}


int get_env(t_list **env)
{
	extern char **environ;
	size_t	i;
	

	i = 0;
	while (environ[i] != NULL)
	{
		
		add_listback(env, create_list(strdup(environ[i])));
		// printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}

void	srch_path(t_list	*env)
{
	size_t	i;
	t_list	*tmp

	i = 0;
	while (env)
	{
		if (strncmp(env->str, "PATH", 4) == 0)
		{
			
			printf("%s\n", env->str);
			return ;
		}
		env = env->next;
	}
}

int main(void)
{
	t_list	*env;
	t_list	*head;

	env = NULL;
	
	get_env(&env);
	head = env;
	srch_path(env);

	// while (env != NULL)
	// {
	// 	printf("%s\n", env->str);
	// 	env = env->next;
	// }
	free_list(&head);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}