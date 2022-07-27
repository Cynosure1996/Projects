/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:36:22 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:45:47 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

# define MAXINT 2147483647
# define MININT -2147483648

typedef struct s_node
{
	int				num;
	int				order;
	int				score;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_all
{
	t_node			*stack_a;
	t_node			*stack_b;
	int				size_a;
	int				size_b;
	int				min;
	int				max;
	int				med;
	int				min_a;
	int				max_a;
	int				rev_a;
	int				rev_b;
	int				to_push;
	int				min_score;
	int				order_a;
	int				index;
}					t_all;

int		main(int argc, char **argv);
int		check_and_make(char **av, int ac, int **arr);
int		check_elem(char *elem);
int		*get_arr(char **av, int size, int ac);
void	free_char(char	**str);
void	elem_error(void);
int		check_dup(int *arr, int size);
void	dup_error(int *arr);
void	value_error(void);
int		is_sorted(int *arr, int size);
void	arg_error(void);
t_all	*init(int *arr, int size);
void	create_struct(t_all *all, int size);
void	add_to_stack_a(t_all **all, t_node *elem);
t_node	*lstnew(int num, int order);
void	clear(t_all *all);
void	ra(t_all *all, int flag);
void	rb(t_all *all, int flag);
void	rr(t_all *all, int flag);
void	rra(t_all *all, int flag);
void	rrb(t_all *all, int flag);
void	rrr(t_all *all, int flag);
void	sa(t_all *all, int flag);
void	sb(t_all *all, int flag);
void	ss(t_all *all, int flag);
void	push_a(t_all *all);
void	push_b(t_all *all);
void	pa(t_all *all, int flag);
void	pb(t_all *all, int flag);
void	sort_3(t_all *all);
void	sorting(t_all *all);
void	sort_5(t_all *all);
void	full_sort(t_all *all);
void	get_score(t_all *all, int size);
int		compare(t_all *all, int order, int size);
void	max(t_all *all, t_node *node, int stack_size);
void	min(t_all *all, t_node *node, int stack_size);
void	med(t_all *all, t_node *node, int stack_size);
void	make_descision(t_all *all);
void	choose_element_a(t_all *all, int size_a, int order);
void	put_a(t_all *all);
void	rot_a_b(t_all *all);
void	rot_a(t_all *all);
void	rot_b(t_all *all);
void	to_stack_b(t_all *all);
void	cleaning_1(t_all *all);
void	cleaning(t_all *all);
void	until_max(t_all *all);
void	until_min(t_all *all);
int		check_null(char *numbers);
int		is_sort(t_all *all, int size);
#endif
