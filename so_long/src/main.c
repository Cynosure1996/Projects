/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:37:57 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/30 15:53:26 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_coord_enemy(t_map *map)
{
	int	i;
	int	j;

	map -> x = (int *)malloc(sizeof(int) * map -> count_x + 1);
	map -> y = (int *)malloc(sizeof(int) * map -> count_x + 1);
	if (!map -> x || !map -> y)
		free_map(map);
	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width - 2)
		{
			if (map -> map[i][j] == 'X')
			{
				map -> y[map -> count_x] = i;
				map -> x[map -> count_x] = j;
				map -> count_x -= 1;
			}
			j++;
		}
		i++;
	}
}

void	anim(t_map *map)
{
	enemy_move(map);
	if (map -> img.beer == map -> img.beer1)
		map -> img.beer = map -> img.beer2;
	else if (map -> img.beer == map -> img.beer2)
		map -> img.beer = map -> img.beer1;
}

t_map	*init_map(void)
{
	t_map	*map;
	int		x;

	x = 64;
	map = malloc(sizeof(t_map));
	if (!map)
		exit (0);
	map -> img.beer = map -> img.beer1;
	map -> width = 1;
	map -> height = 0;
	map -> steps = 0;
	map -> count_e = 0;
	map -> count_p = 0;
	map -> count_c = 0;
	map -> count_x = 0;
	return (map);
}

int	draw(t_map *map)
{
	static int	k;
	int			i;
	int			j;

	k++;
	if (k > 30)
	{
		anim(map);
		k = 0;
	}
	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map->width)
		{
			draw_map(map, i, j);
			j++;
		}
		i++;
	}
	mlx_string_put(map -> programm.mlx_pointer, map -> programm.window, \
	(map -> width - 1) / 2, 21, 15921152, steps(map -> steps));
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
	{
		ft_printf("Wrong input");
		exit (0);
	}
	map = init_map();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Can't find/open file");
		exit(0);
	}
	checklen(fd, map);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	make_fill(map, fd, 0);
	check_symb(map, 0, 0);
	init_coord_enemy(map);
	game(map, 64);
	free_map(map);
	return (0);
}
