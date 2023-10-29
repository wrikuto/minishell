/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:54:34 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/29 11:45:15 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GLOBAL_H
# define GLOBAL_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/stat.h>
# include <signal.h>

#define HASH_SIZE 29999


								# include <stdio.h>


typedef struct stat			t_stat;

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct s_shell
{
	
}				t_shell;





int		ft_pwd(void);
int 	ft_exec(char *line);
void	syntax_analyze(char	*str);
char	**input_spliter(char const *s);
void	free_dbl(char **p);
char	*search_path(const char *filename);


// struct s_shell
// {
// 	t_list	*var[HASH_SIZE];
// 	t_dlist	*hist_lst;
// 	char	*histfile_path;
// 	char	*clipboard_path;
// 	int		exit_status;
// 	char	*pwd;
// }	t_shell;

#endif
