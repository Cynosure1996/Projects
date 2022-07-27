/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:28:37 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:47:51 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == (const char)n)
			return ((char *)&str[i]);
		i--;
	}
	if (str[i] == (const char)n)
		return ((char *)&str[i]);
	return (NULL);
}
