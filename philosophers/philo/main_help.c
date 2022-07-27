/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:40:22 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 03:15:27 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mysleep(int slp)
{
	struct timeval	time;
	unsigned long	begin;

	gettimeofday(&time, NULL);
	begin = time.tv_sec * 1000 + time.tv_usec / 1000;
	while (((time.tv_sec * 1000 + time.tv_usec / 1000) - begin)
		< (unsigned long)slp)
	{
		usleep(95);
		gettimeofday(&time, NULL);
	}
}

unsigned long	get_time(void)
{
	struct timeval	time;
	unsigned long	now;

	gettimeofday(&time, NULL);
	now = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (now);
}

int	ft_strlen(const char *s)
{	
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || \
		*str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = (num * 10) + (*str - 48);
		str++;
	}
	if (num > 2147483647 || (*str && (*str < '0' || *str > '9')))
		return (0);
	return (num * sign);
}

void	ft_exit(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->num_phil)
	{
		if (pthread_mutex_destroy(&params->fork[i]))
			printf("unable to destroy fork %d mutex\n", i);
		i++;
	}
	if (pthread_mutex_destroy(&params->print_mutex))
		printf("unable to destroy print mutex\n");
	if (pthread_mutex_destroy(&params->end_check_mutex))
		printf("unable to destroy end check mutex\n");
	if (pthread_mutex_destroy(&params->eat_time_mutex))
		printf("unable to destroy end time mutex\n");
	if (params->philo)
		free(params->philo);
	if (params->philo_thread)
		free(params->philo_thread);
	if (params->fork)
		free(params->fork);
}
