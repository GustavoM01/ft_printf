/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:02:11 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/12 16:46:26 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char static			*ft_return_empty(void);

unsigned int static	ft_new_size(const char *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	size;

	if (!s)
		return (NULL);
	if (!(start < ft_strlen(s)))
		return (ft_return_empty());
	size = ft_new_size(s, start, len);
	s2 = (char *) malloc(sizeof(*s) * size);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s + start, size);
	return (s2);
}

char static	*ft_return_empty(void)
{
	char	*empty;

	empty = malloc(sizeof(char) * 1);
	if (empty)
	{
		*empty = '\0';
		return (empty);
	}
	return (NULL);
}

unsigned int static	ft_new_size(const char *s, unsigned int start, size_t len)
{
	if ((ft_strlen(s) - start) <= len)
		return (ft_strlen(s) - start + 1);
	else
		return (len + 1);
}
