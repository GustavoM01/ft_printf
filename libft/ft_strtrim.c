/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:40:54 by gmaldona          #+#    #+#             */
/*   Updated: 2022/03/12 16:46:31 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	ft_trimstart(const char *str, const char *set);

int static	ft_trimend(const char *str, const char *set);

char static	*ft_return_empty(void);

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		len;

	if (!s1)
		return (NULL);
	start = ft_trimstart(s1, set);
	end = ft_trimend(s1, set);
	len = (int) ft_strlen(s1) - end - start;
	if (len < 0)
		return (ft_return_empty());
	trimmed = (char *) malloc(sizeof(*s1) * (len + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, (len + 1));
	return (trimmed);
}

int	static	ft_trimstart(const char *str, const char *set)
{
	int	trim_len;
	int	found;
	int	i;
	int	j;

	trim_len = 0;
	i = 0;
	found = 1;
	while (str[i] && found)
	{
		found = 0;
		j = 0;
		while (!found && set[j])
		{
			if (str[i] == set[j])
			{
				trim_len++;
				found = 1;
			}
			j++;
		}
		i++;
	}
	return (trim_len);
}

int	static	ft_trimend(const char *str, const char *set)
{
	int	trim_len;
	int	found;
	int	i;
	int	j;

	trim_len = 0;
	i = ft_strlen(str) - 1;
	j = 0;
	found = 1;
	while (found && i >= 0)
	{
		found = 0;
		j = 0;
		while (!found && set[j])
		{
			if (str[i] == set[j])
			{
				trim_len++;
				found = 1;
			}
			j++;
		}
		i--;
	}
	return (trim_len);
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
