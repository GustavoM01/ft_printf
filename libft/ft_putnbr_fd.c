/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:37:24 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/10 18:56:55 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	ft_recursive_put(long n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	nlong;

	nlong = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nlong *= -1;
	}
	ft_recursive_put(nlong, fd);
}

void static	ft_recursive_put(long n, int fd)
{
	char	c;

	if (n / 10 != 0)
		ft_recursive_put(n / 10, fd);
	c = (n % 10) + '0';
	ft_putchar_fd(c, fd);
}
