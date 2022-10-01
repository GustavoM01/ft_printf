/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_writer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:18:47 by gmaldona          #+#    #+#             */
/*   Updated: 2022/10/01 21:25:22 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		writer_cataloger(char *msg, va_list args, t_list **ph_list);
static int		print_ph(t_list **list, va_list args);
static short	is_ph_address(const char *msg, t_list *current);
static int		print_flags(char format, t_list **list, va_list args_cpy);

int	write_msg(char *msg, va_list args, t_list **ph_list)
{
	int		count;
	t_list	*first_item;

	count = 0;
	first_item = *ph_list;
	count = writer_cataloger(msg, args, ph_list);
	*ph_list = first_item;
	return (count);
}

static int	writer_cataloger(char *msg, va_list args, t_list **ph_list)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (msg[i])
	{
		if (*ph_list != NULL && is_ph_address(msg + i, *ph_list))
		{
			i += ((t_placeholder *)(*ph_list)->content)->size;
			count += print_ph(ph_list, args);
			*ph_list = (*ph_list)->next;
		}
		else if (msg[i] == PH_SYMBOL)
			while (ft_strrchr(FLAGS, msg[i + 1]))
				i++;
		else
		{
			ft_putchar_fd(msg[i], 1);
			count++;
		}
	i++;
	}
	return (count);
}

static short	is_ph_address(const char *msg, t_list *current)
{
	if (msg == ((t_placeholder *)(current->content))->start)
		return (1);
	else
		return (0);
}

static int	print_ph(t_list **list, va_list args)
{
	char	format;
	va_list	args_cpy;
	int		size;

	va_copy(args_cpy, args);
	format = ((t_placeholder *)((*list)->content))->type;
	size = print_flags(format, list, args_cpy);
	if (format == 'c')
		size += ft_putchar_fd((char) va_arg(args, int), 1);
	else if (format == 's')
		size += ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'p')
		size += ft_putptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		size += ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'u')
		size += ft_putunbr_fd(va_arg(args, unsigned int), 1);
	else if (format == 'x')
		size += ft_puthex_l(va_arg(args, unsigned int));
	else if (format == 'X')
		size += ft_puthex_u(va_arg(args, unsigned int));
	else if (format == PH_SYMBOL)
		size += ft_putchar_fd(PH_SYMBOL, 1);
	return (size);
}

static	int	print_flags(char format, t_list **list, va_list args_cpy)
{
	t_placeholder	*current_ph;
	int				result;

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
			result++;
		}
	}
	return (result);
}
