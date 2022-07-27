/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:38:30 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/30 15:55:19 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*beer;
	void	*fire;
	void	*beer1;
	void	*beer2;
}			t_img;

typedef struct s_programm
{
	void	*mlx_pointer;
	void	*window;
}				t_programm;

typedef struct s_map{
	int			width;
	char		**map;
	int			height;
	t_programm	programm;
	t_img		img;
	int			player_y;
	int			player_x;
	int			beer_count;
	int			steps;
	int			count_c;
	int			count_e;
	int			count_p;
	int			count_x;
	int			count_xx;
	int			*x;
	int			*y;
}				t_map;

void	game(t_map	*map, int x);
char	*ft_itoa(int n);
void	left_button(t_map *map);
int		controls(int control, t_map *map);
void	down_button(t_map *map);
void	up_button(t_map *map);
void	right_button(t_map *map);
t_map	*init_map(void);
int		draw(t_map *map);
void	check_symb(t_map *map, int i, int j);
void	make_fill(t_map	*map, int fd, int j);
int		checkn(char *line);
void	checklen(int fd, t_map *map);
int		end_game(void);
char	*steps(int steps);
t_map	*init_map(void);
void	free_map(t_map *map);
void	error(t_map *map, int flag);
void	error2(t_map *map, int flag);
void	error3(t_map *map, char *line);
int		tij(void);
void	draw_map(t_map *map, int i, int j);
void	anim(t_map *map);
void	enemy_move_back(t_map *map, int x, int y, int j);
void	enemy_move_forward(t_map *map, int x, int y, int j);
void	enemy_move_left(t_map *map, int x, int y, int j);
void	enemy_move_right(t_map *map, int x, int y, int j);
void	init_coord_enemy(t_map *map);
int		close_game(void);
void	enemy_move(t_map *map);

#endif
