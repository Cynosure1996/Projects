/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:46:55 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:46:57 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_all *all, int flag)
{
	if (all->size_a > 2)
	{
		all->stack_a->next = all->stack_a->next->next;
		all->stack_a->prev->next = all->stack_a->next->prev;
		all->stack_a->next->prev = all->stack_a;
		all->stack_a->prev->next->prev = all->stack_a->prev;
		all->stack_a->prev->next->next = all->stack_a;
		all->stack_a->prev = all->stack_a->prev->next;
		all->stack_a = all->stack_a->prev;
	}
	else
		all->stack_a = all->stack_a->next;
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_all *all, int flag)
{
	if (all->size_b > 2)
	{
		all->stack_b->next = all->stack_b->next->next;
		all->stack_b->prev->next = all->stack_b->next->prev;
		all->stack_b->next->prev = all->stack_b;
		all->stack_b->prev->next->prev = all->stack_b->prev;
		all->stack_b->prev->next->next = all->stack_b;
		all->stack_b->prev = all->stack_b->prev->next;
		all->stack_b = all->stack_b->prev;
	}
	else
		all->stack_b = all->stack_b->next;
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_all *all, int flag)
{
	if (all->size_a > 1 && all->size_b > 1)
	{
		sa(all, 1);
		sb(all, 1);
	}
	if (flag)
		write(1, "ss\n", 3);
}
