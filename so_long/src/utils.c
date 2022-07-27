/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:37:58 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/30 15:26:08 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	size_nbr(int n)
{
	int		len;
	long	i;

	i = (long)n;
	if (n < 0)
		i = (long)n * -1;
	len = 0;
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	if (n > 0)
		return (len);
	else if (n == 0)
		return (1);
	else
		return (len + 1);
}

void	record_str(long n, int len, char	*str)
{
	str[len] = '\0';
	while (len != 0)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	i;

	len = size_nbr(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n >= 0)
		record_str(n, len, str);
	else
	{
		i = (long)n * -1;
		record_str(i, len, str);
		str[0] = '-';
	}
	return (str);
}

char	*steps(int steps)
{
	char	*str;

	str = ft_itoa(steps);
	str = ft_strjoin("Steps ", str);
	return (str);
}

void	draw_map(t_map *map, int i, int j)
{
	if (map -> map[i][j] == '1')
		mlx_put_image_to_window(map -> programm.mlx_pointer, \
		map -> programm.window, map -> img.wall, 64 * j, 64 * i);
	if (map -> map[i][j] == '0')
		mlx_put_image_to_window(map -> programm.mlx_pointer, \
		map -> programm.window, map -> img.floor, 64 * j, 64 * i);
	if (map -> map[i][j] == 'E')
		mlx_put_image_to_window(map -> programm.mlx_pointer, \
		map -> programm.window, map -> img.exit, 64 * j, 64 * i);
	if (map -> map[i][j] == 'C')
		mlx_put_image_to_window(map -> programm.mlx_pointer, \
		map -> programm.window, map -> img.beer, 64 * j, 64 * i);
	if (map -> map[i][j] == 'P')
	{
		mlx_put_image_to_window(map -> programm.mlx_pointer, \
		map -> programm.window, map -> img.player, 64 * j, 64 * i);
		map -> player_x = j;
		map -> player_y = i;
	}
	if (map -> map[i][j] == 'X')
	{
		mlx_put_image_to_window(map -> programm.mlx_pointer, \
		map -> programm.window, map -> img.fire, 64 * j, 64 * i);
	}
}
