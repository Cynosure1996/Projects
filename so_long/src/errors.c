/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:45:35 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/30 15:53:37 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map -> height)
	{
		free (map -> map[i]);
		i++;
	}
	free (map -> map);
	free (map);
	exit (0);
}

void	error(t_map *map, int flag)
{
	if (flag == 2)
	{
		free_map(map);
		ft_printf("\nThe map must contain 1 exit, 1 \
		starting position and at least 1 collectible.");
		exit (0);
	}
	if (flag == 3)
	{
		free_map(map);
		ft_printf("\nCan't open the img file");
		exit (0);
	}
	if (flag == 4)
	{
		free_map(map);
		ft_printf("\nThe map can be composed of only 0,1,C,E,P");
		exit(0);
	}
}

void	error2(t_map *map, int flag)
{
	if (flag == 5)
	{
		free_map(map);
		ft_printf("\nThe map must be closed/surrounded by walls.");
		exit (0);
	}
}

void	error3(t_map *map, char *line)
{
	free(line);
	free(map);
	ft_printf("\nThe map is not rectangular");
	exit(0);
}
