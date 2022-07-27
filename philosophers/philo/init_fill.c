/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:32:16 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 03:15:08 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initiate_each_philo(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->num_phil)
	{
		params->philo[i].eat_over = 0;
		params->philo[i].eat_time = 0;
		params->philo[i].id = i + 1;
		params->philo[i].eat_num = params->eat_num;
		params->philo[i].params = params;
		params->philo[i].right = &(params->fork[i]);
		params->philo[i].left = &(params->fork[(i + 1) % params->num_phil]);
		i++;
	}
}

int	initiate_variables(t_params *params)
{
	int	err;
	int	i;

	i = 0;
	params->philo = NULL;
	params->fork = NULL;
	params->philo_thread = NULL;
	err = pthread_mutex_init(&params->end_check_mutex, NULL);
	err += pthread_mutex_init(&params->print_mutex, NULL);
	err += pthread_mutex_init(&params->eat_time_mutex, NULL);
	params->philo = malloc (sizeof(t_philo) * params->num_phil);
	params->fork = malloc (sizeof(pthread_mutex_t) * params->num_phil);
	params->philo_thread = malloc (sizeof(t_philo) * params->num_phil);
	params->is_end = params->num_phil;
	if (!params->philo || !params->fork || !params->philo_thread)
		return (1);
	while (i < params->num_phil)
	{
		err += pthread_mutex_init(&(params->fork[i]), NULL);
		i++;
	}
	initiate_each_philo(params);
	return (err);
}

int	check_values(t_params *params, int argc, char **argv)
{
	if (params->num_phil < 1 || params->time_to_die < 1
		|| params->time_to_eat < 1
		|| params->time_to_sleep < 1 || (argc == 6 && params->eat_num < 1)
		|| ft_strlen(argv[1]) > 10 || ft_strlen(argv[2]) > 10
		|| ft_strlen(argv[3]) > 10 || ft_strlen(argv[4]) > 10
		|| (argc == 6 && ft_strlen(argv[5]) > 10))
	{
		write(1, "incorrect argument type, positive int expected\n", 47);
		return (1);
	}
	if (params->num_phil > 250)
	{
		write (1, "maximum 250 philosophers\n", 25);
		return (1);
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_params *params)
{
	if (argc < 5 || argc > 6)
	{
		write(1, "incorrect arguments number\n", 27);
		return (1);
	}
	params->num_phil = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	params->eat_num = -1;
	if (argc == 6)
		params->eat_num = ft_atoi(argv[5]);
	if (check_values(params, argc, argv))
		return (1);
	return (0);
}
