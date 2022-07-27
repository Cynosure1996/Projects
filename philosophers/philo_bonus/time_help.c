/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:07:31 by lharwood          #+#    #+#             */
/*   Updated: 2022/07/03 03:07:35 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

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
