/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:03:46 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 03:07:09 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philosophers(t_params *params)
{
	int	i;

	i = 0;
	params->start_time = get_time();
	params->eat_time = params->start_time;
	while (i < params->philo_num)
	{
		params->philo_pid[i] = fork();
		if (params->philo_pid[i] == -1)
			return (1);
		params->id = i + 1;
		if (params->philo_pid[i] == 0)
			philo_process(params);
		i++;
	}
	return (0);
}

int	start_processes(t_params *params)
{
	if (params->eat_num)
	{
		params->eat_num_check_pid = fork();
		if (params->eat_num_check_pid == -1)
			return (8);
		if (params->eat_num_check_pid == 0)
			check_philo_eat_num(params);
	}
	if (start_philosophers(params))
		return (9);
	waitpid(-1, NULL, 0);
	killer(params);
	return (0);
}

void	try_eat(t_params *params)
{
	sem_wait(params->forks_sem);
	philo_print(params, "has taken a fork");
	sem_wait(params->forks_sem);
	philo_print(params, "has taken a fork");
	philo_print(params, "is eating");
	sem_wait(params->end_check_sem);
	params->eat_time = get_time();
	sem_post(params->end_check_sem);
	mysleep (params->time_to_eat);
	sem_post(params->forks_sem);
	sem_post(params->forks_sem);
	params->eat_num--;
}

void	philo_cycle(t_params *params)
{	
	while (1)
	{
		try_eat(params);
		if (!params->eat_num)
			sem_post(params->eat_num_sem);
		philo_print(params, "is sleeping");
		mysleep (params->time_to_sleep);
		philo_print(params, "is thinking");
	}
}

int	philo_process(t_params *params)
{
	if (pthread_create(&(params->life_check_thread),
			NULL, life_watcher, params))
	{
		printf("error life_check_thread_creating\n");
		return (10);
	}
	philo_print(params, "is thinking");
	if (params->id % 2 == 0 && params->philo_num != 1)
		mysleep(params->time_to_eat - 5);
	if (params->philo_num == 1)
		philo_print(params, "has taken a fork");
	else
		philo_cycle(params);
	pthread_join(params->life_check_thread, NULL);
	exit(0);
}
