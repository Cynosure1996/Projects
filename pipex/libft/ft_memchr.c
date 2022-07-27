/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:37:05 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void	*dst, int c, size_t	n)
{
	size_t	i;
	char	*m;

	m = NULL;
	i = 0;
	if (dst == NULL)
		*m = 1;
	while (i < n)
	{
		if (*(unsigned char *)(dst + i) == (unsigned char)c)
			return ((void *)(dst + i));
		i++;
	}
	return (NULL);
}
