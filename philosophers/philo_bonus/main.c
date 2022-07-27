/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:56:39 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 02:57:20 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_params	params;
	int			ret;

	if (parse_args(argc, argv, &params))
		return (0);
	if (initiate_variables(&params))
	{
		write(1, "error while initiate variables\n", 31);
		ft_exit(&params);
		return (9);
	}
	ret = start_processes(&params);
	if (ret > 0)
	{
		printf("Error while starting processes");
		ft_exit(&params);
		return (ret);
	}
	ft_exit(&params);
	return (0);
}
