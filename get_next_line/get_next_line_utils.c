/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 08:00:15 by lharwood          #+#    #+#             */
/*   Updated: 2021/12/26 08:05:09 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *c)
{
	int	n;

	n = 0;
	if (c == NULL)
		return (0);
	while (*c)
	{
		n++;
		c++;
	}
	return (n);
}

char	*ft_strdup(char *str)
{
	char	*p;
	size_t	n;
	char	*m;

	m = NULL;
	if (!str)
		*m = 1;
	p = (char *)malloc (sizeof (*str) * (ft_strlen(str) + 1));
	n = 0;
	if (!p)
		return (NULL);
	while (str[n])
	{
		p[n] = str[n];
		n++;
	}
	p[n] = 0;
	return (p);
}

char	*ft_strchr(const char *c, int ch)
{
	if (!c)
		return (NULL);
	while (*c)
	{
		if (*c == (char)ch)
			return ((char *)c);
		c++;
	}
	if (*c == (char)ch)
	{
		return ((char *)c);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
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
