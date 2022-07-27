/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:39:22 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 03:16:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philo_eat_num(t_params *params, int i)
{
	pthread_mutex_lock(&params->end_check_mutex);
	while (i < params->num_phil)
	{		
		if (params->is_end <= 0)
		{
			pthread_mutex_unlock(&params->end_check_mutex);
			break ;
		}
		if (!params->philo[i].eat_over)
		{
			break ;
		}
		i++;
	}
	if (i == params->num_phil)
	{
		params->is_end = 0;
	}
	pthread_mutex_unlock(&params->end_check_mutex);
}

void	check_philo_time(t_params *params, int i)
{
	while (i < params->num_phil)
	{		
		pthread_mutex_lock(&params->end_check_mutex);
		if (params->is_end <= 0)
		{
			pthread_mutex_unlock(&params->end_check_mutex);
			break ;
		}
		pthread_mutex_unlock(&params->end_check_mutex);
		pthread_mutex_lock(&params->eat_time_mutex);
		if (get_time() - params->philo[i].eat_time
			>= (unsigned long)params->time_to_die)
		{
			pthread_mutex_lock(&params->end_check_mutex);
			params->is_end = 0;
			pthread_mutex_unlock(&params->end_check_mutex);
			printf("%lu %d died\n",
				get_time() - params->start_time, i + 1);
		}
		i++;
		pthread_mutex_unlock(&params->eat_time_mutex);
	}
}

void	thread_watcher(t_params *params)
{
	while (1)
	{
		pthread_mutex_lock(&params->end_check_mutex);
		if (params->is_end <= 0)
		{
			pthread_mutex_unlock(&params->end_check_mutex);
			break ;
		}
		pthread_mutex_unlock(&params->end_check_mutex);
		check_philo_time(params, 0);
		check_philo_eat_num(params, 0);
		pthread_mutex_unlock(&params->end_check_mutex);
		usleep(5000);
	}
}

void	philo_print(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->params->print_mutex);
	pthread_mutex_lock(&philo->params->end_check_mutex);
	if (philo->params->is_end <= 0)
	{
		pthread_mutex_unlock(&philo->params->print_mutex);
		pthread_mutex_unlock(&philo->params->end_check_mutex);
		return ;
	}
	printf("%lu %d %s\n",
		get_time() - philo->params->start_time, philo->id, message);
	pthread_mutex_unlock(&philo->params->print_mutex);
	pthread_mutex_unlock(&philo->params->end_check_mutex);
}
