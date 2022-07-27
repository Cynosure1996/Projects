/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:37:40 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	mem(size_t start, size_t len, size_t lenstr)
{
	if (lenstr > (start + len))
		return (len);
	else if (start > lenstr)
		return (0);
	return (lenstr - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	st;
	char	*r;

	if (!s)
		return (NULL);
	st = start;
	len = mem (start, len, ft_strlen(s));
	r = (char *)malloc(sizeof (char) * (len + 1));
	if (!r)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (j < len && i >= st)
		{
			r[j] = s[i];
			j++;
		}
		i++;
	}
	r[j] = 0;
	return (r);
}
