/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:14:28 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:44:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		mem;

	if (!s)
		return (NULL);
	else if (ft_strlen(s) > len + (size_t)start)
		mem = len;
	else if (ft_strlen(s) < (size_t)start)
	{
		res = (char *)malloc(sizeof(char));
		if (res == NULL)
			return (NULL);
		*res = '\0';
		return (res);
	}
	else
		mem = ft_strlen(s) - (size_t)start;
	res = (char *)ft_calloc(mem + 1, sizeof(char));
	if (res)
	{
		ft_memcpy(res, &s[start], mem);
	}
	return (res);
}
