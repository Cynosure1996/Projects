/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:38:03 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/30 15:40:31 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game(t_map	*map, int x)
{
	map -> programm.mlx_pointer = mlx_init();
	map -> programm.window = mlx_new_window(map -> programm.mlx_pointer, \
	(map -> width - 1) * 64, map -> height * 64, "so_long");
	map -> img.wall = mlx_xpm_file_to_image(map -> programm.mlx_pointer, \
	"sprites/wall..xpm", &x, &x);
	map -> img.floor = mlx_xpm_file_to_image(map -> programm.mlx_pointer, \
	"sprites/floor.xpm", &x, &x);
	map -> img.exit = mlx_xpm_file_to_image(map -> programm.mlx_pointer, \
	"sprites/Exit2.xpm", &x, &x);
	map -> img.fire = mlx_xpm_file_to_image(map -> programm.mlx_pointer, \
	"sprites/Enemy.xpm", &x, &x);
	map -> img.player = mlx_xpm_file_to_image(map -> programm.mlx_pointer, \
	"sprites/player1.xpm", &x, &x);
	map -> img.beer1 = mlx_xpm_file_to_image(map -> programm.mlx_pointer, \
	"sprites/beer.xpm", &x, &x);
	map -> img.beer2 = mlx_xpm_file_to_image(map -> programm.mlx_pointer, \
	"sprites/beer1.xpm", &x, &x);
	map -> img.beer = map -> img.beer1;
	draw(map);
	mlx_hook(map -> programm.window, 2, 0, controls, map);
	mlx_hook(map ->programm.window, 17, 0, close_game, map);
	mlx_loop_hook(map -> programm.mlx_pointer, draw, map);
	mlx_loop(map -> programm.mlx_pointer);
}

int	controls(int control, t_map *map)
{
	int	x;

	x = 64;
	if (control == 13 || control == 126)
		up_button(map);
	else if (control == 1 || control == 125)
		down_button(map);
	else if (control == 0 || control == 123)
		left_button(map);
	else if (control == 2 || control == 124)
		right_button(map);
	else if (control == 53)
		close_game();
	if (map -> beer_count == 0)
		map -> img.exit = mlx_xpm_file_to_image(map -> programm.mlx_pointer, \
	"sprites/Exit.xpm", &x, &x);
	draw(map);
	return (0);
}

int	end_game(void)
{
	ft_printf ("You win this game, pear.\n");
	exit (0);
	return (0);
}

int	tij(void)
{
	ft_printf("You've been TIJed loser\n");
	exit (0);
	return (0);
}

int	close_game(void)
{
	ft_printf("The game was closed, PUSSY\n");
	exit (0);
	return (0);
}
