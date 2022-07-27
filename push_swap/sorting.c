/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:46:41 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:46:42 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_all *all)
{
	if (all->stack_a->num > all->stack_a->next->num)
	{
		if (all->stack_a->num < all->stack_a->prev->num)
		{
			sa(all, 1);
			return ;
		}
		ra(all, 1);
		if (all->stack_a->num > all->stack_a->next->num)
			sa(all, 1);
	}
	else
	{
		if (all->stack_a->num < all->stack_a->prev->num)
		{
			rra(all, 1);
			sa(all, 1);
		}
		else
			rra(all, 1);
	}
}

void	sort_5(t_all *all)
{
	int	tmp;

	tmp = all->size_a;
	while (all->size_a != 3)
	{
		if (all->stack_a->order <= tmp - 3)
			pb(all, 1);
		else
			ra(all, 1);
	}
	if (!is_sort(all, 2))
		sort_3(all);
	while (all->size_b)
	{
		if (all->stack_b->order >= all->stack_b->next->order)
			pa(all, 1);
		else
			sb(all, 1);
	}
}

void	sorting(t_all *all)
{
	if (all->size_a == 2)
		sa(all, 1);
	else if (all->size_a == 3)
		sort_3(all);
	else if (all->size_a <= 5)
		sort_5(all);
	else
		full_sort(all);
}
