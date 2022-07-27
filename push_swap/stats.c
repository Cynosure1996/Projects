/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:46:47 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:46:49 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max(t_all *all, t_node *node, int stack_size)
{
	t_node	*tmp;
	int		max;
	int		i;

	tmp = node;
	max = node->order;
	i = 0;
	while (i < stack_size)
	{
		if (max < tmp->order)
			max = tmp->order;
		tmp = tmp->next;
		i++;
	}
	all->max = max;
}

void	min(t_all *all, t_node *node, int stack_size)
{
	t_node	*tmp;
	int		min;
	int		i;

	tmp = node;
	min = node->order;
	i = 0;
	while (i < stack_size)
	{
		if (min > tmp->order)
			min = tmp->order;
		tmp = tmp->next;
		i++;
	}
	all->min = min;
}

void	med(t_all *all, t_node *node, int stack_size)
{
	max(all, node, stack_size);
	min(all, node, stack_size);
	all->med = (all->max - all->min) / 2 + all->min;
}

void	until_max(t_all *all)
{
	while (all->stack_a->order != all->max)
	{
		med(all, all->stack_a, all->size_a);
		if (all->stack_a->order > all->med / 2)
			pb(all, 1);
		else
			ra(all, 1);
	}
}

void	until_min(t_all *all)
{
	while (all->stack_a->order != all->min)
	{
		med(all, all->stack_a, all->size_a);
		if (all->stack_a->order > all->med / 2)
			pb(all, 1);
		else
			ra(all, 1);
	}
}
