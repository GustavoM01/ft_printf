/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:59:58 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/22 18:05:01 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long static	ft_positions(long n);

void static	ft_assign(char *s, long nlong);

char	*ft_itoa(int n)
{
	long	nlong;
	int		is_neg;
	char	*ptr;
	long	pos;

	nlong = n;
	is_neg = 0;
	pos = 0;
	if (nlong < 0)
	{
		nlong *= -1;
		is_neg = 1;
		pos = 1;
	}
	pos += ft_positions(nlong);
	ptr = malloc(sizeof(char) * (pos + 1));
	if (!ptr)
		return (NULL);
	if (is_neg)
		ptr[0] = '-';
	ft_assign(ptr + pos - 1, nlong);
	ptr[pos] = '\0';
	return (ptr);
}

long static	ft_positions(long n)
{
	long	i;

	i = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void static	ft_assign(char *s, long nlong)
{
	int	i;

	i = 0;
	if (nlong / 10 != 0)
		ft_assign(s - 1, nlong / 10);
	*s = (nlong % 10) + '0';
}
