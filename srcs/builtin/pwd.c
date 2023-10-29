/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:15:50 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/24 17:55:37 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL) {
		if (errno == ERANGE) {
			// バッファサイズが不足している場合の処理
			ft_printf("Error: Buffer size is too small.\n");
		} else {
			// その他のエラーの場合の処理
			perror("getcwd error.\n");
		}
		// エラー処理を行った後、必要に応じてプログラムを終了する
		return (-1);
	}
	ft_printf("%s\n", cwd);
	free (cwd);
	return (0);
}

