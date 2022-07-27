/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:00:46 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 03:00:59 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	killer(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->philo_num)
	{
		kill(params->philo_pid[i], SIGKILL);
		i++;
	}
	kill(params->eat_num_check_pid, SIGKILL);
	return (0);
}

void	ft_exit(t_params *params)
{
	sem_unlink("print_sem");
	sem_unlink("forks_sem");
	sem_unlink("end_check_sem");
	sem_unlink("eat_num_sem");
	sem_close(params->print_sem);
	sem_close(params->forks_sem);
	sem_close(params->end_check_sem);
	sem_close(params->eat_num_sem);
	if (params->philo_pid)
		free(params->philo_pid);
}
