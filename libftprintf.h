/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:38:06 by gmaldona          #+#    #+#             */
/*   Updated: 2022/07/24 18:42:21 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

#include "libft/libft.h"
#include <stdio.h>

int	count_place_holders(char *str);
int ft_printf(char const *msg, ...);

#endif
