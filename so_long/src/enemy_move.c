/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:26:36 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/30 15:38:30 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_move_back(t_map *map, int x, int y, int j)
{
	if (map -> map[y + 1][x] == '0')
	{
		map -> map[y + 1][x] = 'X';
		map -> map[y][x] = '0';
		map -> y[j] = y + 1;
	}
	if (map -> map[y + 1][x] == 'P')
		tij();
}

void	enemy_move_forward(t_map *map, int x, int y, int j)
{
	if (map -> map[y - 1][x] == '0')
	{
		map -> map[y - 1][x] = 'X';
		map -> map[y][x] = '0';
		map -> y[j] = y - 1;
	}
	if (map -> map[y - 1][x] == 'P')
		tij();
}

void	enemy_move_left(t_map *map, int x, int y, int j)
{
	if (map -> map[y][x - 1] == '0')
	{
		map -> map[y][x - 1] = 'X';
		map -> map[y][x] = '0';
		map -> x[j] = x - 1;
	}
	if (map -> map[y][x - 1] == 'P')
		tij();
}

void	enemy_move_right(t_map *map, int x, int y, int j)
{
	if (map -> map[y][x + 1] == '0')
	{
		map -> map[y][x + 1] = 'X';
		map -> map[y][x] = '0';
		map -> x[j] = x + 1;
	}
	if (map -> map[y][x + 1] == 'P')
		tij();
}

void	enemy_move(t_map *map)
{
	int	i;
	int	j;

	j = 1;
	i = rand() % 4;
	while (j <= map -> count_xx)
	{
		if (i == 0)
			enemy_move_forward(map, map -> x[j], map -> y[j], j);
		if (i == 1)
			enemy_move_back(map, map -> x[j], map -> y[j], j);
		if (i == 2)
			enemy_move_right(map, map -> x[j], map -> y[j], j);
		if (i == 3)
			enemy_move_left(map, map -> x[j], map -> y[j], j);
		j++;
	}
}
