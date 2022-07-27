/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:31:03 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:43:43 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	int				dif;
	unsigned char	*ad1;
	unsigned char	*ad2;

	ad1 = (unsigned char *)s1;
	ad2 = (unsigned char *)s2;
	i = 1;
	if (n == 0)
		return (0);
	while (*ad1 != '\0' && *ad2 != '\0' && i != n)
	{
		if (*ad1 != *ad2)
			return (*ad1 - *ad2);
		ad1++;
		ad2++;
		i++;
	}
	dif = *ad1 - *ad2;
	return (dif);
}
