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

int	hex3(unsigned long long int nbr, int n)
{
	char	*c;
	int		o;
	int		i;

	c = "0123456789abcdef";
	o = 0;
	if (nbr == 0)
	{
		o += write(1, "0", 1);
		return (o);
	}
	i = c[nbr % 16];
	nbr = nbr / 16;
	if (nbr)
		o += hex3(nbr, n);
	o += write(1, &i, 1);
	return (o);
}

int	hex2(unsigned int nbr, int n)
{
	unsigned int	i;

	if (nbr < 0)
	{
		i = (unsigned int)nbr;
		return (hex(i, n));
	}
	return (hex(nbr, n));
}

int	hex(unsigned int nbr, int n)
{
	int		o;
	char	*c;
	char	i;

	o = 0;
	if (nbr == 0)
	{
		o += write(1, "0", 1);
		return (o);
	}
	if (n == 1)
		c = "0123456789abcdef";
	else
		c = "0123456789ABCDEF";
	i = c[nbr % 16];
	nbr = nbr / 16;
	if (nbr)
		o += hex(nbr, n);
	o += write(1, &i, 1);
	return (o);
}

int	parse(const char *s, va_list ap)
{
	int	count;

	count = 0;
	if ((*s == 'd') || (*s == 'i'))
		count += ft_putnbr(va_arg(ap, int));
	if (*s == 's')
		count += ft_putstr(va_arg(ap, char *));
	if (*s == 'c')
		count += ft_putchar(va_arg(ap, int));
	if (*s == 'p')
	{
		count += write(1, "0x", 2);
		count += hex3(va_arg(ap, unsigned long long), 3);
	}
	if (*s == 'u')
		count += ito2 (va_arg(ap, unsigned int));
	if (*s == 'x')
		count += hex2(va_arg(ap, int), 1);
	if (*s == 'X')
		count += hex2(va_arg(ap, int), 0);
	if (*s == '%')
		count += write(1, "%", 1);
	if (*s == '\n')
		write (1, "\n", 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
			count += write(1, s, 1);
		else
		{
			s++;
			count += parse(s, ap);
			if (*(s + 1) == 0)
				return (count);
		}
		s++;
	}
	va_end (ap);
	return (count);
}
