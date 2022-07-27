/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:52:12 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:42:22 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ad;

	if (!lst && !del)
		return ;
	while (lst && *lst)
	{
		ad = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ad;
	}
}
