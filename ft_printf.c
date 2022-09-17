/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:34:19 by gmaldona          #+#    #+#             */
/*   Updated: 2022/09/17 14:43:34 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	write_ph_list(char *msg, va_list args, t_list **list);

int	ft_printf(char const *msg, ...)
{
	int		count;
	t_list	**ph_list;
	va_list	args;

	count = 0;
	ph_list = malloc(sizeof(t_list *));
	*ph_list = NULL;
	if (ph_list)
	{
		va_start(args, msg);
		count = create_ph_list(ph_list, (char *) msg);
		write_ph_list((char *) msg, args, ph_list);
	}	
	va_end(args);
	ft_lstclear(ph_list, (void *) free);
	free(ph_list);
	return (count);
}

static void	write_ph_list(char *msg, va_list args, t_list **list)
{
	int	i;
	t_list *firstItemAdd;

	i = 0;
	firstItemAdd = *list;
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
	*list = firstItemAdd;
}
