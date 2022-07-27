/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:27:54 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:44:12 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len_s1;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 != '\0')
	{
		if (check(*s1, set) == 0)
			break ;
		s1++;
		start++;
	}
	len_s1 = ft_strlen(s1);
	if (len_s1 == 0)
		return (ft_calloc(1, 1));
	while (len_s1 > 0)
	{
		if (check(s1[len_s1 - 1], set) == 0)
			break ;
		len_s1--;
	}
	return (ft_substr(s1, 0, len_s1));
}
