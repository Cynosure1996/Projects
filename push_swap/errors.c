/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:45:00 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:45:03 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	elem_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	dup_error(int *arr)
{
	ft_putstr_fd("Error\n", 2);
	free(arr);
	exit(1);
}

void	value_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	arg_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	is_sort(t_all *all, int size)
{
	t_node	*tmp;

	tmp = all->stack_a;
	while (size)
	{
		if (tmp->order > tmp->next->order)
			return (0);
		tmp = tmp->next;
		size--;
	}
	return (1);
}
