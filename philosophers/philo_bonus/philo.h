/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:08:12 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 03:11:29 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <pthread.h>

typedef struct s_params
{
	int				id;
	unsigned long	eat_time;
	unsigned long	start_time;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_num;
	pid_t			*philo_pid;
	pid_t			eat_num_check_pid;
	sem_t			*print_sem;
	sem_t			*forks_sem;
	sem_t			*end_check_sem;
	sem_t			*eat_num_sem;
	pthread_t		life_check_thread;
}					t_params;

int				parse_args(int argc, char **argv, t_params *params);
unsigned long	get_time(void);
void			mysleep(int slp);
int				initiate_variables(t_params *params);
void			ft_exit(t_params *params);
int				philo_process(t_params *params);
void			philo_print(t_params *params, char *message);
int				start_processes(t_params *params);
void			*life_watcher(void *params);
int				killer(t_params *params);
int				ft_strlen(const char *s);
int				ft_atoi(const char *str);
int				check_philo_eat_num(t_params *params);
#endif
