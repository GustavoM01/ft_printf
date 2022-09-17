/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:30:33 by gmaldona          #+#    #+#             */
/*   Updated: 2022/09/17 20:34:46 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define FORMATS "cspdiuxX"
#define PH_SYMBOL '%'
#define FLAGS "# +"

static t_placeholder	*save_ph_information(char *current_add);
static int 				is_valid_format(char *msg, t_placeholder *ph);
static short 			add_flag_count(t_placeholder *current_ph);

int	read_msg(t_list **ph_list, char *msg)
{
	int	i;
	int	counter;
	t_placeholder *current_ph;

	i = 0;
	counter = 0;
	current_ph = NULL;
	while (msg[i])
	{
		if (PH_SYMBOL == msg[i]) 
		{
			current_ph = save_ph_information(msg + i);
			if (current_ph != NULL)
			{
				ft_lstadd_back(ph_list, ft_lstnew(current_ph));
				counter += add_flag_count(current_ph);
				counter++;
			}
		}	
		i++;
	}
	return (counter);
}

static t_placeholder	*save_ph_information(char *current_add)
{
	int	i;
	t_placeholder *ph;

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

static int is_valid_format(char *msg, t_placeholder *ph)
{
	short result;
	int i;

	result = 0;
	i = 0;
	ph->numeral_flag = 0;
	ph->sign_flag = 0;
	ph->space_flag = 0;
	while(msg[i] && result == 0)
	{
		if(msg[i] == '#')
			ph->numeral_flag = 1;
		else if (msg[i] == ' ')
			ph->space_flag = 1;
		else if (msg[i] == '+')
			ph->sign_flag = 1;
		else if (ft_strchr(FORMATS, msg[i]))
		{
			result = 1;
			ph->type = msg[i];
		}
		else
			return (result);
		i++;
	}
	return (result);
}

static short add_flag_count(t_placeholder *current_ph)
{
	int	result;

	result = 0;
	if (current_ph->sign_flag || current_ph->space_flag)
	{
		if (current_ph->type == 'd' || current_ph->type == 'i')
			result++;
	}
	if (current_ph-> numeral_flag)
	{
		if (current_ph->type == 'x' || current_ph->type == 'X')
			result++;
	}
	return (result);	
}