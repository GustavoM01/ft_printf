/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:34:19 by gmaldona          #+#    #+#             */
/*   Updated: 2022/08/08 20:06:19 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(char const *msg, ...)
{
    int i = 0;
    t_list **list;
    char *temp_msg;
    
    temp_msg = (char *) msg;
    list = NULL;
    while (temp_msg[i])
    {
        if ('%' != temp_msg[i])
        {
            ft_putchar_fd(temp_msg[i], 1);
        }
        i++;    
    }

    list = count_place_holders(temp_msg); 

    // ft_lstiter(*list, &print_to_sys_out);
    printf("\n%pn", list);

    printf("\nto delete\n");
    ft_lstclear(list, (void *) ft_lstdelone);

    

    return 5;
}