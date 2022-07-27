/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:15:48 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 03:15:49 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	unsigned long		eat_time;
	int					id;
	int					eat_num;
	int					eat_over;
	struct s_params		*params;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
}				t_philo;

typedef struct s_params
{
	unsigned long	start_time;
	int				num_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_num;
	int				is_end;
	t_philo			*philo;
	pthread_t		*philo_thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_time_mutex;
	pthread_mutex_t	end_check_mutex;
}				t_params;

int				parse_args(int argc, char **argv, t_params *params);
unsigned long	get_time(void);
void			mysleep(int slp);
int				initiate_variables(t_params *params);
void			ft_exit(t_params *params);
void			*philo_thread(void *v_philo);
void			philo_print(t_philo *philo, char *message);
int				thread_manager(t_params *params, int command);
int				ft_atoi(const char *str);
void			thread_watcher(t_params *params);
int				ft_strlen(const char *s);

#endif