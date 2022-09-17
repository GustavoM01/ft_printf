/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:38:06 by gmaldona          #+#    #+#             */
/*   Updated: 2022/09/17 19:23:45 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"
# include <stdio.h>// ** delete
# include <stdarg.h>
# include <limits.h>// ** check and delete

typedef struct s_placeholder
{
	char			*start;
	char			type;
	short			numeral_flag;
	short			space_flag;
	short			sign_flag;

}	t_placeholder;

int		ft_printf(char const *msg, ...);
int		read_msg(t_list **list, char *str);
int		write_msg(char *msg, va_list args, t_list **ph_list);

#endif
