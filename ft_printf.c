/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:34:19 by gmaldona          #+#    #+#             */
/*   Updated: 2022/09/01 23:39:13 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	write_list(char *msg, va_list args, t_list **list);

int	ft_printf(char const *msg, ...)
{
	int		count;
	t_list	**list;
	va_list	args;

	count = 0;
	list = malloc(sizeof(t_list *));
	*list = NULL;
	if (list)
	{
		va_start(args, msg);
		count = create_ph_list(list, (char *) msg);
		write_list((char *) msg, args, list);
	}
	ft_lstclear(list, (void *) free);
	free(list);
	return (count);
}

static void	write_list(char *msg, va_list args, t_list **list)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		if (is_ph_address(&msg[i], list))
		{
			print_ph(list, args);
			if ((*list)->next)
				*list = (*list)->next;
			i++;
		}
		else
			ft_putchar_fd(msg[i], 1);
	i++;
	}
}
