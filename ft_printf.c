/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:34:19 by gmaldona          #+#    #+#             */
/*   Updated: 2022/08/13 21:53:04 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(char const *msg, ...)
{
    int count;
    t_list **list;

    count = 0;
    list = malloc(sizeof(t_list *));
    *list = NULL;
    if (list)
    {
        int i;

        i = 0;
        count = create_ph_list(list, (char *) msg);
        va_list args;
        va_start(args, msg);
        while (msg[i])
        {
            if (is_ph_address(&msg[i], list))
            {
                print_ph(list, args);
                if ((*list)->next)
                    *list = (*list)->next;
                i++;
            } else {
                ft_putchar_fd(msg[i], 1);
            }   
            i++; 
        }
    }
    // // ft_lstiter(*list, (void *) print_to_sys_out);
    ft_lstclear(list, (void *) free);
    free(list);
    return count;
}