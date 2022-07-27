/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:48:15 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:43:34 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	int		i;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	if (len_d >= size)
		return (size + len_s);
	i = 0;
	while (i + len_d < size - 1 && *src != '\0')
	{
		dst[i + len_d] = *src;
		src++;
		i++;
	}
	dst[i + len_d] = '\0';
	return (len_d + len_s);
}
