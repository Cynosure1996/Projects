/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:46:16 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:46:28 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_all *all, int flag)
{
	if (all->size_a > 1)
		all->stack_a = all->stack_a->next;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_all *all, int flag)
{
	if (all->size_b > 1)
		all->stack_b = all->stack_b->next;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_all *all, int flag)
{
	if (all->size_b > 1 && all->size_a > 1)
	{
		all->stack_b = all->stack_b->next;
		all->stack_a = all->stack_a->next;
	}
	if (flag)
		write(1, "rr\n", 3);
}

int	is_sorted(int *arr, int size)
{
	int	i;
	int	k;
	int	sorted;

	sorted = 1;
	i = 0;
	while (i < size)
	{
		k = i + 1;
		while (k < size)
		{
			if (arr[k++] < arr[i])
				sorted = 0;
		}
		i++;
	}
	return (sorted);
}

int	check_null(char *numbers)
{
	int	j;

	j = -1;
	while (numbers[++j])
	{
		if (j == 0)
		{
			if (numbers[j] != '+' && numbers[j] != '-' && numbers[j] != '0')
				return (1);
		}
		else if (numbers[j] != '0')
			return (1);
	}
	return (0);
}
