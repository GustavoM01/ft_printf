/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:34:19 by gmaldona          #+#    #+#             */
/*   Updated: 2022/08/10 21:24:51 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(char const *msg, ...)
{
    int i = 0;
    int count = 0;
    t_list **list;
    char *temp_msg;
    
    temp_msg = (char *) msg;
    while (temp_msg[i])
    {
        if ('%' != temp_msg[i])
        {
            ft_putchar_fd(temp_msg[i], 1);
        }
        i++;    
    }

    count = count_place_holders(list, temp_msg);

    // ft_lstiter(*list, (void *) print_to_sys_out);

    ft_lstclear(list, (void *) free);

    return count;
}