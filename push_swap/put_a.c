/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:46:07 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:46:08 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_b(t_all *all)
{
	if (all->rev_b)
		rrb(all, 1);
	else
		rb(all, 1);
}

void	rot_a(t_all *all)
{
	if (all->rev_a)
		rra(all, 1);
	else
		ra(all, 1);
}

void	rot_a_b(t_all *all)
{
	if (all->rev_a && all->rev_b)
		rrr(all, 1);
	else if (!(all->rev_a) && !(all->rev_b))
		rr(all, 1);
	else
	{
		rot_a(all);
		rot_b(all);
	}
}

void	put_a(t_all *all)
{
	while (all->stack_a->order != all->order_a \
			|| all->stack_b->order != all->to_push)
	{
		if (all->stack_a->order == all->order_a)
			rot_b(all);
		else if (all->stack_b->order == all->to_push)
			rot_a(all);
		else
			rot_a_b(all);
	}
	pa(all, 1);
}
