/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_phill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:58:53 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 02:59:25 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initiate_variables(t_params *params)
{
	params->philo_pid = NULL;
	params->id = 0;
	sem_unlink("print_sem");
	sem_unlink("forks_sem");
	sem_unlink("eat_num_sem");
	sem_unlink("end_check_sem");
	params->print_sem = sem_open("print_sem", O_CREAT, 0644, 1);
	params->forks_sem = sem_open("forks_sem", O_CREAT, 0644, params->philo_num);
	params->eat_num_sem = sem_open("eat_num_sem", O_CREAT, 0644, 0);
	params->end_check_sem = sem_open("end_check_sem", O_CREAT, 0644, 1);
	params->philo_pid = malloc(sizeof(pid_t *) * params->philo_num);
	if (params->print_sem == SEM_FAILED || params->forks_sem == SEM_FAILED
		|| !params->philo_pid || params->eat_num_sem == SEM_FAILED
		|| !params->end_check_sem)
		return (1);
	return (0);
}

int	check_values(t_params *params, int argc, char **argv)
{
	if (params->philo_num < 1 || params->time_to_die < 1
		|| params->time_to_eat < 1
		|| params->time_to_sleep < 1 || (argc == 6 && params->eat_num < 1)
		|| ft_strlen(argv[1]) > 10 || ft_strlen(argv[2]) > 10
		|| ft_strlen(argv[3]) > 10 || ft_strlen(argv[4]) > 10
		|| (argc == 6 && ft_strlen(argv[5]) > 10))
	{
		write(1, "incorrect argument type, positive int expected\n", 47);
		return (1);
	}
	if (params->philo_num > 250)
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
	params->philo_num = ft_atoi(argv[1]);
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
