/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:30:33 by gmaldona          #+#    #+#             */
/*   Updated: 2022/08/10 21:37:05 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define	FORMATS "cspdiuxX"
#define PH_SYMBOL '%'

static t_placeholder *save_ph_information(char *placeholder);

int 	count_place_holders(t_list **list, char *str)
{
	int i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] && str[i + 1] && PH_SYMBOL == str[i] && ft_strchr(FORMATS, str[i + 1]))
		{	
			ft_lstadd_back(list, ft_lstnew(save_ph_information(&str[i])));
			counter++;	
		}
		i++;
	}
	return counter;
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


// t_list	**count_place_holders(char *str)
	// Receive a char *
	// Declare index and count vars
	// Loop through char *
		// Ask if char is '%'
		// Ask if next char is included in FORMATS
		// If yes to both, then count++ (check out what's printf's behavior if '%' is followed by an invalid format value)

// is_valid_ph_format
	// Ask if value in passed address is a flag
	// Continue until format is found (What if is not well formatted)
	// LATEST: Only checking next char right now

// save_ph_information
