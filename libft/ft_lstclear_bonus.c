/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaldona <gmaldona@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:12:34 by gmaldona          #+#    #+#             */
/*   Updated: 2022/08/11 18:03:12 by gmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	printf("\nft_lstclear first line\n");
	t_list	*tmp;

	tmp = NULL;
	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		printf("\nft_lstclear line 23\n");
		lst = NULL;
		return ;
	}
	while (*lst != NULL)
	{
		printf("\npointer to free: %p\n", *lst);
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	if (tmp)
		free(tmp);
	lst = NULL;
}
