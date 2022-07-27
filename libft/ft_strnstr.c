/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:37:34 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
char	*ft_strnstr(const char	*a, const char *b, size_t	n)
{
	int		j;
	size_t	i;

	if (ft_strlen((char *)b) == 0)
		return ((char *)a);
	j = 0;
	if (!*a)
		return (NULL);
	i = 0;
	while (n > i && a[i + j] && b[j])
	{
		j = 0;
		while ((a[i + j] == b[j]) && (i + j < n) && a[i + j] && b[j])
		{
			j++;
			if (b[j] == '\0')
				return ((char *)(a + i));
		}
		i++;
	}
	return (NULL);
}
