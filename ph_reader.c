/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:30:33 by gmaldona          #+#    #+#             */
/*   Updated: 2022/10/02 00:10:40 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_placeholder	*save_ph_information(char *current_add);
static short			is_valid_format(char *msg, t_placeholder *ph);
static void				set_default_ph(t_placeholder *ph);

void	read_msg(t_list **ph_list, char *msg)
{
	int				i;
	t_placeholder	*current_ph;

	i = 0;
	while (msg[i])
	{
		if (PH_SYMBOL == msg[i])
		{
			current_ph = save_ph_information(msg + i);
			if (current_ph != NULL)
			{
				ft_lstadd_back(ph_list, ft_lstnew(current_ph));
				i += current_ph->size;
			}
		}
		i++;
	}
}

static t_placeholder	*save_ph_information(char *current_add)
{
	int				i;
	t_placeholder	*ph;

	i = 0;
	ph = malloc(sizeof(t_placeholder));
	if (ph)
	{
		ph->start = NULL;
		if (is_valid_format(current_add + 1, ph))
			ph->start = current_add;
		else
		{
			free(ph);
			ph = NULL;
		}		
	}
	return (ph);
}

static short	is_valid_format(char *msg, t_placeholder *ph)
{
	short	result;
	int		i;

	result = 0;
	i = 0;
	set_default_ph(ph);
	while (msg[i] && result == 0)
	{
		ph->size++;
		if (msg[i] == '#')
			ph->numeral_flag = 1;
		else if (msg[i] == ' ')
			ph->space_flag = 1;
		else if (msg[i] == '+')
			ph->sign_flag = 1;
		else if (ft_strchr(FORMATS, msg[i]) || msg[i] == PH_SYMBOL)
		{
			result = 1;
			ph->type = msg[i];
		}
		else if (!ft_isalpha(msg[i]))
			return (result);
		i++;
	}
	return (result);
}

static void	set_default_ph(t_placeholder *ph)
{
	ph->numeral_flag = 0;
	ph->sign_flag = 0;
	ph->space_flag = 0;
	ph->size = 0;
}
