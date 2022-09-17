/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:30:33 by gmaldona          #+#    #+#             */
/*   Updated: 2022/09/17 14:17:08 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define FORMATS "cspdiuxX"
#define PH_SYMBOL '%'

static t_placeholder	*save_ph_information(char *placeholder);
static char				get_format(t_list **list);

int	create_ph_list(t_list **ph_list, char *msg)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (msg[i])
	{
		if (PH_SYMBOL == msg[i] && msg[i + 1] && ft_strchr(FORMATS, msg[i + 1]))
		{	
			ft_lstadd_back(ph_list, ft_lstnew(save_ph_information(&msg[i])));
			counter++;
		}
		i++;
	}
	return (counter);
}

short	is_ph_address(const char *msg, t_list **current)
{
	if (msg == ((t_placeholder *)((*current)->content))->start)
		return (1);
	else
		return (0);
}

void	print_ph(t_list **list, va_list args)
{
	char	format;

	format = get_format(list);
	if (format == 'c')
		ft_putchar_fd((char) va_arg(args, int), 1);
	else if (format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'p')
		ft_putptr(va_arg(args, unsigned int));
	else if (format == 'd' || format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'u')
		ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (format == 'x')
		ft_puthex_l(va_arg(args, int));
	else if (format == 'X')
		ft_puthex_u(va_arg(args, int));
}

static t_placeholder	*save_ph_information(char *placeholder)
{
	t_placeholder	*ph;

	ph = malloc(sizeof(t_placeholder));
	ph->start = placeholder;
	ph->size = 2;
	ph->type = *(placeholder + ph->size - 1);
	return (ph);
}

static char	get_format(t_list **list)
{
	char	format;

	format = ((t_placeholder *)((*list)->content))->type;
	return (format);
}
