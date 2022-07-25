/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:34:19 by gmaldona          #+#    #+#             */
/*   Updated: 2022/07/25 18:14:44 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(char const *msg, ...)
{
    t_list **list;
    char *temp_msg = (char *) msg;
    
    while ('\0' != *msg)
    {
        ft_putchar_fd(*msg, 1);
        msg++;
    }
    ft_putchar_fd('\n', 1);
    
    list = count_place_holders(temp_msg);

    // ft_lstiter(*list, &print_to_sys_out);

    return 5;
}