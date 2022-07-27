/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:53:53 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:43:21 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (const char)n)
			return ((char *)str);
		str++;
	}
	if (*str == (const char)n)
		return ((char *)str);
	return (NULL);
}
