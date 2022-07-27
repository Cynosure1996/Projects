/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:34:08 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:42:15 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*las;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			las = ft_lstlast(*lst);
			las->next = new;
		}
	}
}
