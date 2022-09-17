/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_writer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:18:47 by gmaldona          #+#    #+#             */
/*   Updated: 2022/09/17 20:45:48 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static short	is_ph_address(const char *msg, t_list **current);
static int	print_ph(t_list **list, va_list args);
static char	get_format(t_list **list);
static int print_flags(char format, t_list **list, va_list args_cpy);

int	write_msg(char *msg, va_list args, t_list **ph_list)
{
	int count;
	int	i;
	t_list *firstItemAdd;

	i = 0;
	count = 0;
	firstItemAdd = *ph_list;
	while (msg[i])
	{
		if (*ph_list != NULL && is_ph_address(&msg[i], ph_list))
		{
			i += print_ph(ph_list, args);
			if ((*ph_list)->next)
				*ph_list = (*ph_list)->next;
			i++;
		}
		else
		{
			ft_putchar_fd(msg[i], 1);
			count++;
		}
	i++;
	}
	*ph_list = firstItemAdd;
	return (count);
}

static short	is_ph_address(const char *msg, t_list **current)
{
	if (msg == ((t_placeholder *)((*current)->content))->start)
		return (1);
	else
		return (0);
}

static int	print_ph(t_list **list, va_list args)
{
	char	format;
	va_list args_cpy;
	int	result;

	va_copy(args_cpy, args);
	format = get_format(list);
	result = 0;
	result += print_flags(format, list, args_cpy);
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
	return (result);
}

static char	get_format(t_list **list)
{
	char	format;

	format = ((t_placeholder *)((*list)->content))->type;
	return (format);
}

static int print_flags(char format, t_list **list, va_list args_cpy)
{
	t_placeholder *current_ph;
	int	result;

	result = 0;
	current_ph = (*list)->content;
	if (current_ph->sign_flag)
	{
		if ((format == 'd' || format == 'i'))
		{
					if (va_arg(args_cpy, int) >= 0)
			ft_putchar_fd('+', 1);
		else
			ft_putchar_fd('-', 1);
		}
		result++;
	}
	return (result);
}