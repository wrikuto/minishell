/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:55:02 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/28 20:55:09 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void    print_table(char **table)
{
        size_t  i = 0;

        while (table[i] != NULL)
        {

                printf("%s\n", table[i]);
                i++;
        }
}