/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:46:23 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:43:14 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	num = (unsigned int)n;
	if (num >= 10)
		ft_putnbr_fd((num / 10), fd);
	ft_putchar_fd((char)(num % 10 + 48), fd);
}
