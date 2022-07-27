/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:16:16 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:42:50 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ad;

	if (!arr && !c && !n)
		return (NULL);
	ad = (unsigned char *)arr;
	while (n > 0)
	{
		if (*ad == (unsigned char)c)
			return ((void *)ad);
		n--;
		ad++;
	}
	return (0);
}
