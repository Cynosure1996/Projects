/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:45:20 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:45:21 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstnew(int num, int order)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->next = NULL;
	new->prev = NULL;
	new->num = num;
	new->order = order;
	new->score = 0;
	return (new);
}

void	clear(t_all *all)
{
	t_node	*temp;

	if (!all->stack_a)
		return ;
	all->stack_a->prev->next = NULL;
	while (all->stack_a)
	{
		temp = all->stack_a->next;
		free(all->stack_a);
		all->stack_a = NULL;
		all->stack_a = temp;
	}
	while (all->size_b--)
	{
		temp = all->stack_b->next;
		free(all->stack_b);
		all->stack_b = NULL;
		all->stack_b = temp;
	}
	free(all);
}

void	add_to_stack_a(t_all **all, t_node *elem)
{
	t_node	*last_a;

	if (!elem)
		clear(*all);
	last_a = (*all)->stack_a;
	if (last_a)
	{
		if (last_a->prev)
		{
			last_a->prev->next = elem;
			elem->prev = last_a->prev;
			last_a->prev = elem;
			elem->next = last_a;
		}
		else
		{
			last_a->next = elem;
			last_a->prev = elem;
			elem->next = last_a;
			elem->prev = last_a;
		}
	}
	else
		(*all)->stack_a = elem;
}

void	create_struct(t_all *all, int size)
{
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->size_a = size;
	all->size_b = 0;
	all->min = 0;
	all->max = 0;
	all->med = 0;
	all->rev_a = 0;
	all->rev_b = 0;
	all->to_push = 0;
	all->min_score = 0;
	all->order_a = 0;
	all->index = 1;
}

t_all	*init(int *arr, int size)
{
	t_all	*all;
	int		k;
	int		i;
	int		order;

	all = malloc(sizeof(t_all));
	if (!all)
		exit(1);
	create_struct(all, size);
	i = 0;
	while (i < size)
	{
		k = 0;
		order = 1;
		while (k < size)
		{
			if (arr[i] > arr[k++])
				order++;
		}
		add_to_stack_a(&all, lstnew(arr[i], order));
		i++;
	}
	return (all);
}
