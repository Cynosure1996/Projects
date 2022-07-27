/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:37:09 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
void	*ft_memmove(void	*dst, const void	*src, size_t	len)
{
	unsigned char	*b;
	unsigned char	*a;

	if (dst == NULL && src == NULL && len != 0)
		return (NULL);
	b = (unsigned char *)dst;
	a = (unsigned char *)src;
	if (b < a)
		while (len--)
			*b++ = *a++;
	else
	{
		b = b + len;
		a = a + len;
		while (len--)
			*--b = *--a;
	}
	return (dst);
}
