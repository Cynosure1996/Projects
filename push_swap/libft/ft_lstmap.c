/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:51:34 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:42:35 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*ad;

	if (!f && !del)
		return (NULL);
	ret = (t_list *)0;
	while (lst)
	{
		ad = ft_lstnew((*f)(lst->content));
		if (!ad)
		{
			ft_lstclear(&ret, del);
			break ;
		}
		ft_lstadd_back(&ret, ad);
		lst = lst->next;
	}
	return (ret);
}
