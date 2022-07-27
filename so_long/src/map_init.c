/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:38:01 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/30 15:30:33 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_symb(t_map *map, int i, int j)
{
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width - 2)
		{
			if (map -> map[i][j] != '1' && map -> map[i][j] != '0' \
			&& map -> map[i][j] != 'C')
				if (map -> map[i][j] != 'E' && map -> map[i][j] != 'P' \
				&& map -> map[i][j] != 'X')
					error(map, 4);
			if (map -> map[i][j] == 'C')
				map -> beer_count++;
			if (map -> map[i][j] == 'E')
				map -> count_e++;
			if (map -> map[i][j] == 'P')
				map -> count_p++;
			if (map -> map[i][j] == 'X')
				map -> count_x += 1;
			j++;
		}
		i++;
	}
	map -> count_xx = map -> count_x;
	if (map -> count_e == 0 || map -> count_p != 1 || map -> beer_count == 0)
		error(map, 2);
}

void	make_fill(t_map	*map, int fd, int j)
{
	map -> map = (char **)malloc(sizeof(char *) * (map -> height + 1));
	while (j < map -> height)
	{
		map -> map[j] = (char *)malloc(sizeof(char) * (map -> width));
		map -> map[j] = get_next_line(fd);
		map -> map[j][map -> width] = 0;
		j++;
	}
	map -> map[j] = NULL;
	j = 0;
	while (j < map -> width - 1)
	{
		if (map -> map[0][j] != '1' || map -> map[map -> height - 1][j] != '1')
			error2(map, 5);
		j++;
	}
	j = 0;
	while (j < map -> height)
	{
		if (map -> map[j][0] != '1' || map -> map[j][map -> width - 2] != '1')
			error2(map, 5);
		j++;
	}
}

int	checkn(char *line)
{
	while (*line)
		line++;
	if (*(line--) != '\n')
		return (1);
	return (0);
}

void	checklen(int fd, t_map *map)
{
	int		len1;
	char	*line;

	while (map -> width)
	{
		line = get_next_line(fd);
		map -> width = ft_strlen(line);
		if (!map -> width)
			break ;
		if (!map -> height)
			len1 = map -> width;
		else if (len1 - 1 == map -> width)
		{
			if (checkn(line) == 0)
				error3(map, line);
			else
				map -> width = len1;
		}
		else if (map -> width != len1)
			error3(map, line);
		free(line);
		map -> height += 1;
	}
	map -> width = len1;
}
