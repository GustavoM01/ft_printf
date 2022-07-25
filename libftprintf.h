/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:38:06 by gmaldona          #+#    #+#             */
/*   Updated: 2022/07/25 18:06:30 by gmaldona         ###   ########.fr       */
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

t_list	    **count_place_holders(char *str);
int     ft_printf(char const *msg, ...);
void    print_to_sys_out(void *str);

#endif
