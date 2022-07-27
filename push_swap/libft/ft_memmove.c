/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:36:54 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:43:04 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ad_s;
	unsigned char	*ad_d;
	size_t			i;

	ad_s = (unsigned char *)src;
	ad_d = (unsigned char *)dest;
	if (!src && !dest)
		return (NULL);
	if (ad_d <= ad_s)
		ft_memcpy(ad_d, ad_s, n);
	else
	{
		i = 0;
		while (i < n)
		{
			ad_d[n - 1 - i] = ad_s[n - 1 - i];
			i++;
		}
	}
	return (dest);
}
