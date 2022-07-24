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

static short int is_valid_format(char *placeholder);

int	count_place_holders(char *str)
{
	// Receive a char *
	// Declare index and count vars
	// Loop through char *
		// Ask if char is '%'
		// Ask if next char is included in FORMATS
		// If yes to both, then count++ (check out what's printf's behavior if '%' is followed by an invalid format value)
	int i;
	int	count;

	i = 0;
	while (str[i])
	{
		if ('%' == str[i] && is_valid_format(&str[i + 1]))
			count++;
		i++;
	}
	return count;
}

static short int is_valid_format(char *placeholder)
{
	// Ask if value in passed address is a flag
	// Continue until format is found (What if is not well formatted)
	// LATEST: Only checking next char right now

	return NULL != ft_strchr(FORMATS, *placeholder);
}
