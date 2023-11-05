/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:22:25 by wrikuto           #+#    #+#             */
/*   Updated: 2023/11/04 18:01:38 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../inc/minishell.h"

int get_env(t_list **env)
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



int	analysis_line(char *line, t_list *env_list)
{
	extern char **environ;
	t_list	*token_list;
	int	rtn = 0;
	char	*res;
	t_list	*temp;

	token_list = NULL;
	temp = env_list;
	
	if (ft_strncmp(line, "env", SIZE_MAX) == 0)
	{
		while (temp != NULL)
		{
			printf("%s\n", temp->str);
			temp = temp->next;
		}
	}
	else if (ft_strncmp(line, "exit", SIZE_MAX) == 0)
	{
		free(line);
		exit(0);
	}
	else if (ft_strncmp(line, "pwd", SIZE_MAX) == 0)
		rtn = ft_pwd();
	else if (*line)
	{
		parse(line, &token_list);
		res = search_path(token_list->str, env_list->str);
		if (res)
		{
			free(token_list->str);
			token_list->str = res;
			// ft_printf("find path: %s\n", token_list->token);  // TST
			ft_exec(token_list);
		}
		free_list(&token_list);
	}
	return (0);
}

int main(void)
{
	t_list	*env;
	char	*line;
	int i;

	env = NULL;
	get_env(&env);
	rl_outstream = stderr;
	
	while(1)
	{
		i = 0;
		line = readline("minishell$ ");
		if (*line != '\0')
		{
			if (line == NULL)
				return (0) ;
			// if (line)
			// 	add_history(line);
			if (analysis_line(line, env) == -1)
				exit(0);
			free(line);
		}
	}
	free_list(&env);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q minishell");
}


// int	analysis_line(char *line)
// {
// 	extern char **environ;
// 	t_list	*list;
// 	int	i = 0;
// 	int	rtn = 0;
// 	char	*res;
// 	t_list	*temp;

// 	list = NULL;
// 	if (ft_strncmp(line, "env", SIZE_MAX) == 0)
// 	{
// 		while (environ[i++] != NULL)
// 		{
// 			if (environ[i] == NULL)
// 				break ;
// 			ft_printf("%s\n", environ[i]);
// 		}
// 	}
// 	else if (ft_strncmp(line, "exit", SIZE_MAX) == 0)
// 	{
// 		free(line);
// 		exit(0);
// 	}
// 	else if (ft_strncmp(line, "pwd", SIZE_MAX) == 0)
// 		rtn = ft_pwd();
// 	else
// 	{
// 		parse(line, &list);
// 		res = search_path(list->str);
// 		if (res)
// 		{
// 			free(list->str);
// 			list->str = res;
// 			// ft_printf("find path: %s\n", list->token);  // TST
// 			ft_exec(list);
// 		}
// 		free_list(&list);
// 	}
// 	return (0);
// }



// int main(void)
// {
// 	// t_list	*env;
// 	char	*line;
// 	int i;

// 	// env = NULL;
// 	rl_outstream = stderr;
	
// 	while(1)
// 	{
// 		i = 0;
// 		line = readline("minishell$ ");
// 		if (line == NULL)
// 			return (0) ;
// 		// if (line)
// 		// 	add_history(line);
// 		if (analysis_line(line) == -1)
// 			exit(0);
// 		free(line);
// 	}
// 	return (0);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q minishell");
// }