/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:30:33 by gmaldona          #+#    #+#             */
/*   Updated: 2022/06/05 16:48:08 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#define	FORMATS "cspdiuxX"
#define PH_SYMBOL '%'

short int is_valid_format(char c);
int	count_ph(char *str)
{
	int i;
	int	count;

	i = 0;
	while (str[i])
	{
		if ('%' == str[i] && '\0' != str[i + 1] && is_valid_format(str[i + 1]))
			count++;
		i++;
	}
	return count;
}

short int is_valid_format(char c)
{
	return (c == 'c');
}
