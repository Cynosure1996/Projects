/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:08:27 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:43:06 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*ad;

	ad = (unsigned char *)dest;
	while (n > 0)
	{
		*ad = (unsigned char)c;
		ad++;
		n--;
	}
	return (dest);
}
