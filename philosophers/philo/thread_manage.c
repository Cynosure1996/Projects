/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:38:25 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 03:19:06 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	try_eat(t_philo *philo, int eat_t)
{
	pthread_mutex_lock(philo->left);
	philo_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right);
	philo_print(philo, "has taken a fork");
	philo_print(philo, "is eating");
	pthread_mutex_lock(&philo->params->eat_time_mutex);
	philo->eat_time = get_time();
	pthread_mutex_unlock(&philo->params->eat_time_mutex);
	mysleep (eat_t);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	philo->eat_num--;
}

void	philo_cycle(t_philo *philo, int eat_t, int sleep_t)
{	
	while (1)
	{
		pthread_mutex_lock(&philo->params->end_check_mutex);
		if (philo->params->is_end <= 0)
		{
			pthread_mutex_unlock(&philo->params->end_check_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->params->end_check_mutex);
		try_eat(philo, eat_t);
		pthread_mutex_lock(&philo->params->end_check_mutex);
		if (philo->eat_num == 0)
			philo->eat_over = 1;
		pthread_mutex_unlock(&philo->params->end_check_mutex);
		philo_print(philo, "is sleeping");
		mysleep (sleep_t);
		philo_print(philo, "is thinking");
	}
}

void	*philo_thread(void *v_philo)
{
	t_philo	*philo;
	int		time_to_eat;
	int		time_to_sleep;

	philo = (t_philo *)v_philo;
	time_to_eat = philo->params->time_to_eat;
	time_to_sleep = philo->params->time_to_sleep;
	philo_print(philo, "is thinking");
	if (philo->id % 2 == 0 && philo->params->num_phil != 1)
		mysleep(time_to_eat - 5);
	if (philo->params->num_phil == 1)
	{
		philo_print(philo, "has taken a fork");
		mysleep(philo->params->time_to_die + 5);
	}
	else
		philo_cycle(philo, time_to_eat, time_to_sleep);
	return (0);
}

int	thread_manager(t_params *params, int command)
{
	int	i;

	i = 0;
	if (command == 0)
	{
		while (i < params->num_phil)
		{
			pthread_join(params->philo_thread[i], NULL);
			i++;
		}
	}
	if (command == 1)
	{
		params->start_time = get_time();
		while (i < params->num_phil)
		{
			params->philo[i].eat_time = params->start_time;
			if (pthread_create(&(params->philo_thread[i]),
					NULL, philo_thread, &(params->philo[i])))
				return (1);
			i++;
		}
	}
	return (0);
}
