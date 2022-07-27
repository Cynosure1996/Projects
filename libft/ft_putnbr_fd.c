/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:37:18 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
static void	ito(num, fd)
{
	int	i;

	i = num % 10 + '0';
	if (num >= 10)
		ito(num / 10, fd);
	write (fd, &i, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	num = n;
	if (num < 0)
	{
		num *= -1;
		write (fd, "-", 1);
	}
	if (num >= 0)
		ito(num, fd);
	return ;
}
