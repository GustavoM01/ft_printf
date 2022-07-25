/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:30:33 by gmaldona          #+#    #+#             */
/*   Updated: 2022/07/25 18:13:45 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define	FORMATS "cspdiuxX"
#define PH_SYMBOL '%'

static short int is_valid_ph_format(char *placeholder);
static t_placeholder *save_ph_information(char *placeholder);

t_list	**count_place_holders(char *str)
{
	// Receive a char *
	// Declare index and count vars
	// Loop through char *
		// Ask if char is '%'
		// Ask if next char is included in FORMATS
		// If yes to both, then count++ (check out what's printf's behavior if '%' is followed by an invalid format value)
	int i;
	int	count;
	t_list **ph_list;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (PH_SYMBOL == str[i] && ft_strchr(FORMATS, str[i + 1]))
		{
			ft_lstadd_back(ph_list, ft_lstnew(save_ph_information(&str[i])));
			count++;
		}
		i++;
	}
	return ph_list;
}

static short int is_valid_ph_format(char *placeholder)
{
	// Ask if value in passed address is a flag
	// Continue until format is found (What if is not well formatted)
	// LATEST: Only checking next char right now

	return NULL != ft_strchr(FORMATS, *placeholder);
}

static t_placeholder *save_ph_information(char *placeholder)
{
	t_placeholder *ph;

	ph = malloc(sizeof(t_placeholder));
	ph->start = placeholder;
	ph->size = 2;
	ph->type = *(placeholder + 1);



	return ph;
}
