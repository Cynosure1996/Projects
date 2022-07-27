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
static void	helo( char *s, const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		s[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		s[j] = s2[i];
		i++;
		j++;
	}
	s[j] = 0;
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;

	if (!s1)
		return (NULL);
	s = (char *)malloc(sizeof(*s1) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!s)
		return (NULL);
	helo(s, s1, s2);
	return (s);
}
