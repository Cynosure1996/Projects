/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:37:25 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2, char const *s3)
{
	char			*s12;
	unsigned int	i;
	int				size;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	if (s1 == NULL || s2 == NULL || s3 == NULL)
		return (NULL);
	s12 = (char *)malloc(sizeof(char) * (size + 1));
	if (s12 == NULL)
		return (NULL);
	while (*s1 != '\0')
		s12[i++] = *s1++;
	while (*s2 != '\0')
		s12[i++] = *s2++;
	while (*s3 != '\0')
		s12[i++] = *s3++;
	s12[i] = '\0';
	return (s12);
}
