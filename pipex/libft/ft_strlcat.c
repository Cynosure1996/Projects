/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:37:26 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t	size)
{
	size_t	n;
	size_t	i;
	char	*m;

	m = NULL;
	if (!dst)
		*m = 1;
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (dst[i] && i < size)
		i++;
	n = i;
	while (src[i - n] && i < size - 1)
	{
		dst[i] = src[i - n];
		i++;
	}
	if (n < size)
		dst[i] = 0;
	return (n + ft_strlen(src));
}
