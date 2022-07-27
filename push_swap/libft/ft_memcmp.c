/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:05:14 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:42:58 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char		*ad_1;
	const unsigned char	*ad_2;
	size_t				i;

	ad_1 = (unsigned char *)arr1;
	ad_2 = (unsigned char *)arr2;
	i = 0;
	while (i != n && ad_1[i] == ad_2[i])
		i++;
	if (i == n)
		return (0);
	return (ad_1[i] - ad_2[i]);
}
