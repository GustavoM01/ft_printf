/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:38:06 by gmaldona          #+#    #+#             */
/*   Updated: 2022/09/01 21:04:24 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

typedef struct s_placeholder
{
    char            *start;
    unsigned int    size;
    char            type;

} t_placeholder;

int 	create_ph_list(t_list **list, char *str);
int     ft_printf(char const *msg, ...);
short   is_ph_address(const char *msg, t_list **current);
void    print_ph(t_list **list, va_list args);

#endif
