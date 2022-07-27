/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:36:22 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:44:35 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	cmd(t_all *all, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
		pa(all, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(all, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(all, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(all, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(all, 0);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(all, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(all, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(all, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(all, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(all, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(all, 0);
	else
		error();
}

static void	checker(t_all *all)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		cmd(all, line);
	}
	if (is_sort(all, all->size_a - 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	int		*arr;
	int		size;

	if (argc < 2)
		arg_error();
	size = check_and_make(argv, argc, &arr);
	if (is_sorted(arr, size))
	{
		free(arr);
		write(1, "OK\n", 3);
		return (0);
	}
	all = init(arr, size);
	checker(all);
	free(arr);
	clear(all);
	return (0);
}
