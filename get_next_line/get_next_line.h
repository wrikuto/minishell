/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:28:55 by wrikuto           #+#    #+#             */
/*   Updated: 2023/09/11 16:58:46 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include<stddef.h>
# include<fcntl.h>
# include<limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

size_t	ft_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif