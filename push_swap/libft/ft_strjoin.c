/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:37:58 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:43:32 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s12;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s12 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s12 == NULL)
		return (NULL);
	if (s1)
	{
		while (*s1 != '\0')
			s12[i++] = *s1++;
	}
	while (*s2 != '\0')
		s12[i++] = *s2++;
	s12[i] = '\0';
	return (s12);
}
