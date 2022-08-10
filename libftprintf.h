/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:38:06 by gmaldona          #+#    #+#             */
/*   Updated: 2022/08/10 21:15:34 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

#include "libft/libft.h"
#include <stdio.h>

typedef struct s_placeholder
{
    char            *start;
    unsigned int    size;
    char            type;

} t_placeholder;

int 	count_place_holders(t_list **list, char *str);
int     ft_printf(char const *msg, ...);
void    print_to_sys_out(t_placeholder *ph);

#endif
