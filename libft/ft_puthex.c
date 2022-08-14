/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:50:26 by gmaldona          #+#    #+#             */
/*   Updated: 2022/08/14 16:54:11 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_puthex(unsigned long nbr, char *xX);

void	ft_putptr(unsigned long nbr)
{
	ft_putstr_fd("0x10", 1);
	ft_puthex(nbr, HEX_L);
}

void	ft_puthex_l(unsigned long nbr)
{
	ft_puthex(nbr, HEX_L);
}

void	ft_puthex_u(unsigned long nbr)
{
	ft_puthex(nbr, HEX_U);
}

static void ft_puthex(unsigned long nbr, char *xX)
{
	if (nbr / HEX_SIZE != 0)
		ft_puthex(nbr / HEX_SIZE, xX);
	write(1, &(xX[nbr % HEX_SIZE]), 1);
}

