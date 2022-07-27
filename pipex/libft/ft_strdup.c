/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:37:23 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *str)
{
	char	*p;
	size_t	n;
	char	*m;

	m = NULL;
	if (!str)
		*m = 1;
	p = (char *)malloc (sizeof (*str) * (ft_strlen(str) + 1));
	n = 0;
	if (!p)
		return (NULL);
	while (str[n])
	{
		p[n] = str[n];
		n++;
	}
	p[n] = 0;
	return (p);
}
