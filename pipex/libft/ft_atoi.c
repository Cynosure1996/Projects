/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:36:22 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *b)
{
	long int	n;
	long int	i;

	i = 1;
	n = 0;
	while ((*b >= 9 && *b <= 13) || *b == 32)
		b++;
	if (*b == '-' || *b == '+')
	{
		if (*b == '-')
			i = i * (-1);
		b++;
	}
	while (*b == '0')
		b++;
	while (*b >= '0' && *b <= '9')
	{
		n = n * 10 + *b - 48;
		b++;
	}
	return (n * i);
}
