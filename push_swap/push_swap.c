/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 05:45:39 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/03 05:45:40 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (0);
	}
	all = init(arr, size);
	sorting(all);
	free(arr);
	clear(all);
	return (0);
}
