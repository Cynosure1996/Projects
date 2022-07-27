/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:30:48 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 03:15:20 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_params			params;

	if (parse_args(argc, argv, &params))
		return (0);
	if (initiate_variables(&params))
	{
		write(1, "error while initiate variables\n", 31);
		ft_exit(&params);
		return (0);
	}
	if (thread_manager(&params, 1))
	{
		write(1, "error while start threads\n", 26);
		ft_exit(&params);
		return (0);
	}
	thread_watcher(&params);
	thread_manager(&params, 0);
	ft_exit(&params);
	return (0);
}
