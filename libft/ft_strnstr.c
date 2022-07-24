/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:31:37 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/11 19:37:38 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t static	ft_find(const char *h, const char *n, size_t nl);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	h_len;
	size_t	lim;
	size_t	i;
	size_t	c_len;

	n_len = ft_strlen(needle);
	if (!n_len)
		return ((char *) haystack);
	h_len = ft_strlen(haystack);
	if (n_len > h_len)
		return (NULL);
	lim = h_len - n_len;
	i = 0;
	c_len = len;
	while (len && i <= lim && i <= c_len - n_len)
	{
		if (ft_find(haystack + i, needle, n_len))
			return ((char *)(haystack + i));
		i++;
		len--;
	}
	return (NULL);
}

size_t static	ft_find(const char *h, const char *n, size_t nl)
{
	size_t	i;

	i = 0;
	while (h[i] && n[i] && h[i] == n[i])
		i++;
	if (i == nl)
		return (1);
	return (0);
}
