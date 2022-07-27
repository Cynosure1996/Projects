/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_watch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:06:46 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 03:19:58 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_watcher(void *v_params)
{
	t_params	*params;

	params = (t_params *)v_params;
	while (1)
	{
		sem_wait(params->end_check_sem);
		if (get_time() - params->eat_time
			>= (unsigned long)params->time_to_die)
		{
			sem_wait(params->print_sem);
			printf("%lu %d died\n",
				get_time() - params->start_time, params->id);
			exit (0);
		}
		sem_post(params->end_check_sem);
		usleep(1000);
	}
	return (NULL);
}

void	philo_print(t_params *params, char *message)
{
	sem_wait(params->print_sem);
	printf("%lu %d %s\n",
		get_time() - params->start_time, params->id, message);
	sem_post(params->print_sem);
}

int	check_philo_eat_num(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->philo_num)
	{
		sem_wait(params->eat_num_sem);
		i++;
	}
	exit (0);
}
