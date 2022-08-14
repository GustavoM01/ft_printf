/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:37:24 by gmaldona          #+#    #+#             */
/*   Updated: 2022/08/14 13:50:13 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	ft_recursive_put_u(unsigned long n, int fd);

void	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned long	nlong;

	nlong = n;
	ft_recursive_put_u(nlong, fd);
}

void static	ft_recursive_put_u(unsigned long n, int fd)
{
	char	c;

	if (n / 10 != 0)
		ft_recursive_put_u(n / 10, fd);
	c = (n % 10) + '0';
	ft_putchar_fd(c, fd);
}
