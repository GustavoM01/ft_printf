/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:30:33 by gmaldona          #+#    #+#             */
/*   Updated: 2022/08/08 20:12:23 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define	FORMATS "cspdiuxX"
#define PH_SYMBOL '%'

static short int is_valid_ph_format(char *placeholder);
static t_placeholder *save_ph_information(char *placeholder);

t_list	**count_place_holders(char *str)
{
	printf("\nfirst\n");
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
	ph_list = malloc(sizeof(t_list) * 6);
	while (str[i])
	{
		if (str[i] && str[i + 1] && PH_SYMBOL == str[i] && ft_strchr(FORMATS, str[i + 1]))
		{
			printf("\nEs %%\n");	
			ft_lstadd_front(ph_list, ft_lstnew(save_ph_information(&str[i])));
			count++;	
		}
		printf("\nAddress: %p", ph_list);
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

	// printf("\n%p\n%d\n%c\n", ph->start, ph->size, ph->type);

	return ph;
}
