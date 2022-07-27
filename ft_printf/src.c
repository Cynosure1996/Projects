/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:02:46 by lharwood          #+#    #+#             */
/*   Updated: 2021/12/26 16:24:04 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ito2(unsigned int num)
{
	int				n;
	unsigned int	i;

	n = 0;
	i = num % 10 + '0';
	if (num >= 10)
		n += ito2(num / 10);
	n += write (1, &i, 1);
	return (n);
}

int	ito(int num, int n)
{
	int	i;

	i = num % 10 + '0';
	if (num >= 10)
		n += ito(num / 10, n);
	n += write (1, &i, 1);
	return (n);
}

int	ft_putchar(char n)
{
	write(1, &n, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	long int	num;
	int			s;

	s = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	num = n;
	if (num < 0)
	{
		num *= -1;
		s += write (1, "-", 1);
	}
	if (num >= 0)
		s += ito(num, 0);
	return (s);
}

int	ft_putstr(char *s)
{
	int	n;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	n = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		n++;
	}
	return (n);
}
