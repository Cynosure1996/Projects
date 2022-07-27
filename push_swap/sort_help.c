/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:36:22 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:46:35 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_element_a(t_all *all, int size_a, int order)
{
	t_node	*tmp_a;

	tmp_a = all->stack_a;
	while (size_a)
	{
		if (order < tmp_a->order && order > tmp_a->prev->order)
		{
			all->order_a = tmp_a->order;
			if (size_a < all->size_a / 2)
				all->rev_a = 1;
			break ;
		}
		tmp_a = tmp_a->next;
		size_a--;
	}
}

void	make_descision(t_all *all)
{
	t_node	*tmp_b;
	int		size;

	tmp_b = all->stack_b;
	size = all->size_b;
	all->min_score = tmp_b->score;
	all->to_push = tmp_b->order;
	while (size--)
	{
		if (tmp_b->score < all->min_score)
		{
			all->min_score = tmp_b->score;
			all->to_push = tmp_b->order;
			if (size < all->size_b / 2)
				all->rev_b = 1;
		}
		tmp_b = tmp_b->next;
	}
	choose_element_a(all, all->size_a, all->to_push);
}

int	compare(t_all *all, int order, int size)
{
	int		j;
	t_node	*tmp_a;

	j = 0;
	tmp_a = all->stack_a;
	while (size)
	{
		if (order < tmp_a->order && order > tmp_a->prev->order)
			return (j);
		tmp_a = tmp_a->next;
		if (size > all->size_a / 2 - 1)
			j++;
		else
			j--;
		size--;
	}
	return (j);
}

void	get_score(t_all *all, int size)
{
	int		i;
	int		j;
	t_node	*tmp_b;

	i = 0;
	tmp_b = all->stack_b;
	all->rev_b = 0;
	all->rev_a = 0;
	while (size)
	{
		j = compare(all, tmp_b->order, all->size_a);
		tmp_b->score = j + i;
		tmp_b = tmp_b->next;
		if (size > all->size_b / 2)
			i++;
		else
			i--;
		size--;
	}
}
