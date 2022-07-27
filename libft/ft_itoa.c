/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:36:47 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
static char	*puska(char *p, long long int n, int i)
{
	if (!n)
	{
		p[0] = '0';
		p[1] = 0;
		return (p);
	}
	p[i] = 0;
	while (i)
	{
		p[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
		if (n == 0 && i == 1)
		{
			p[i - 1] = '-';
			i = 0;
		}
	}
	return (p);
}

char	*ft_itoa(int num)
{
	long long int	n;
	int				i;
	char			*p;

	i = 0;
	n = (long long)num;
	if (num <= 0)
	{
		i++;
		n = n * (-1);
	}
	while (num)
	{
		num = num / 10;
		i++;
	}
	p = (char *)malloc(i + 1);
	if (!p)
		return (NULL);
	return (puska(p, n, i));
}
