/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:34:19 by gmaldona          #+#    #+#             */
/*   Updated: 2022/09/17 20:38:25 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *msg, ...)
{
	int		char_count;
	int		ph_count;
	t_list	**ph_list;
	va_list	args;

	char_count = 0;
	ph_count = 0;
	ph_list = malloc(sizeof(t_list *));
	*ph_list = NULL;
	if (ph_list)
	{
		va_start(args, msg);
		ph_count = read_msg(ph_list, (char *) msg);
		char_count = write_msg((char *) msg, args, ph_list);
	}	
	va_end(args);
	ft_lstclear(ph_list, (void *) free);
	free(ph_list);
	return (char_count + ph_count);
}
