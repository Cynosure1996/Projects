/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:37:31 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *a, const char *b, size_t num)
{
	unsigned char	*c;
	unsigned char	*d;

	c = (unsigned char *)a;
	d = (unsigned char *)b;
	while ((*c || *d) && num > 0)
	{
		if (*c != *d)
			return (*c - *d);
		c++;
		d++;
		num--;
	}
	return (0);
}
