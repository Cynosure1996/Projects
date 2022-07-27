/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:45:11 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:45:14 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_stack_b(t_all *all)
{
	ra(all, 1);
	while (all->stack_a->order != all->max)
	{
		if (all->stack_a->order < all->index)
			pb(all, 1);
		else
		{
			if (all->stack_a->order > all->index + 10)
				pb(all, 1);
			else
			{
				all->index = all->stack_a->order;
				ra(all, 1);
			}
		}
	}
}

void	cleaning_1(t_all *all)
{
	until_max(all);
	pb(all, 1);
	rb(all, 1);
	until_min(all);
	rrb(all, 1);
	pa(all, 1);
	ra(all, 1);
	until_max(all);
	ra(all, 1);
}

void	cleaning(t_all *all)
{
	until_min(all);
	pb(all, 1);
	rb(all, 1);
	until_max(all);
	ra(all, 1);
	rrb(all, 1);
	pa(all, 1);
	ra(all, 1);
	until_max(all);
	ra(all, 1);
}

void	search_min(t_all *all)
{
	t_node	*tmp;
	int		size;

	size = all->size_a;
	tmp = all->stack_a;
	while (size--)
	{
		if (tmp->order == all->max)
			all->max_a = size;
		else if (tmp->order == all->min)
			all->min_a = size;
		tmp = tmp->next;
	}
}

void	full_sort(t_all *all)
{
	max(all, all->stack_a, all->size_a);
	min(all, all->stack_a, all->size_a);
	search_min(all);
	if (all->max_a > all->min_a)
		cleaning_1(all);
	else
		cleaning(all);
	to_stack_b(all);
	while (all->size_b)
	{
		get_score(all, all->size_b);
		make_descision(all);
		put_a(all);
	}
	while (all->stack_a->order != 1)
	{
		if (all->stack_a->order < all->size_a / 3)
			rra(all, 1);
		else
			ra(all, 1);
	}
}
