/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:37:51 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/19 23:51:06 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	left_button(t_map *map)
{
	int	x;

	x = 64;
	map -> img.player = mlx_xpm_file_to_image(map -> programm.mlx_pointer, \
	"sprites/player2.xpm", &x, &x);
	if (map -> map[map -> player_y][map -> player_x - 1] == '0')
	{
		map -> map[map -> player_y][map -> player_x - 1] = 'P';
		map -> map[map -> player_y][map -> player_x] = '0';
		map->steps++;
	}
	if (map -> map[map -> player_y][map -> player_x - 1] == 'E')
		if (map -> beer_count == 0)
			end_game();
	if (map -> map[map -> player_y][map -> player_x - 1] == 'C')
	{
		map -> map[map -> player_y][map -> player_x - 1] = 'P';
		map -> map[map -> player_y][map -> player_x] = '0';
		map -> beer_count--;
		map->steps++;
	}
	if (map -> map[map -> player_y][map -> player_x - 1] == 'X')
		tij();
}

void	right_button(t_map *map)
{
	int	x;

	x = 64;
	map -> img.player = mlx_xpm_file_to_image(map -> programm.mlx_pointer, \
	"sprites/player1.xpm", &x, &x);
	if (map -> map[map -> player_y][map -> player_x + 1] == '0')
	{
		map -> map[map -> player_y][map -> player_x + 1] = 'P';
		map -> map[map -> player_y][map -> player_x] = '0';
		map->steps++;
	}
	if (map -> map[map -> player_y][map -> player_x + 1] == 'E')
		if (map -> beer_count == 0)
			end_game();
	if (map -> map[map -> player_y][map -> player_x + 1] == 'C')
	{
		map -> map[map -> player_y][map -> player_x + 1] = 'P';
		map -> map[map -> player_y][map -> player_x] = '0';
		map -> beer_count--;
		map->steps++;
	}
	if (map -> map[map -> player_y][map -> player_x + 1] == 'X')
		tij();
}

void	down_button(t_map *map)
{
	if (map -> map[map -> player_y + 1][map -> player_x] == '0')
	{
		map -> map[map -> player_y + 1][map -> player_x] = 'P';
		map -> map[map -> player_y][map -> player_x] = '0';
		map->steps++;
	}
	if (map -> map[map -> player_y + 1][map -> player_x] == 'E')
		if (map -> beer_count == 0)
			end_game();
	if (map -> map[map -> player_y + 1][map -> player_x] == 'C')
	{
		map -> map[map -> player_y + 1][map -> player_x] = 'P';
		map -> map[map -> player_y][map -> player_x] = '0';
		map -> beer_count--;
		map->steps++;
	}
	if (map -> map[map -> player_y + 1][map -> player_x] == 'X')
		tij();
}

void	up_button(t_map *map)
{
	if (map -> map[map -> player_y - 1][map -> player_x] == '0')
	{
		map -> map[map -> player_y - 1][map -> player_x] = 'P';
		map -> map[map -> player_y][map -> player_x] = '0';
		map->steps++;
	}
	if (map -> map[map -> player_y - 1][map -> player_x] == 'E')
		if (map -> beer_count == 0)
			end_game();
	if (map -> map[map -> player_y - 1][map -> player_x] == 'C')
	{
		map -> map[map -> player_y - 1][map -> player_x] = 'P';
		map -> map[map -> player_y][map -> player_x] = '0';
		map -> beer_count--;
		map->steps++;
	}
	if (map -> map[map -> player_y - 1][map -> player_x] == 'X')
		tij();
}
