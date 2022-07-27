/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:36:22 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:46:12 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_all *all, int flag)
{
	if (all->size_a > 1)
		all->stack_a = all->stack_a->prev;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_all *all, int flag)
{
	if (all->size_b > 1)
		all->stack_b = all->stack_b->prev;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_all *all, int flag)
{
	if (all->size_b > 1 && all->size_a > 1)
	{
		all->stack_b = all->stack_b->prev;
		all->stack_a = all->stack_a->prev;
	}
	if (flag)
		write(1, "rrr\n", 4);
}
