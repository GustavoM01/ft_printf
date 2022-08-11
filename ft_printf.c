/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:34:19 by gmaldona          #+#    #+#             */
/*   Updated: 2022/08/11 18:02:24 by gmaldona         ###   ########.fr       */
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
    list = (t_list **) malloc(sizeof(t_list) * 1);
    *list = NULL;
    // printf("\nft_printf line 24 - size of list: %d\n", ft_lstsize(*list));
    while (temp_msg[i])
    {
        if ('%' != temp_msg[i])
        {
            ft_putchar_fd(temp_msg[i], 1);
        }
        i++;    
    }
    // printf("ft_printf line 32");
    count = count_place_holders(list, temp_msg);

    // ft_lstiter(*list, (void *) print_to_sys_out);

    ft_lstclear(list, (void *) free);

    free(list);

    return count;
}