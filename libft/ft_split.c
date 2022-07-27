/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:37:20 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:13 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static char	**ft_pul(int n)
{
	char	**p;

	p = (char **)malloc(sizeof(char *) * (n + 1));
	if (!p)
		return (NULL);
	p[n] = NULL;
	return (p);
}

static void	ft_dungeon_master(char	**p, const char *s, char c, int m)
{
	int	n;
	int	i;
	int	j;

	i = 0;
	n = m;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == 0)
			{
				p[n - m] = ft_substr(s, i - j, j + 1);
				m--;
			}
			j++;
			i++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		n;
	int		m;

	if (!s)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			n++;
		i++;
	}
	m = n;
	p = ft_pul(n);
	if (!p)
		return (NULL);
	if (!n)
		return (p);
	ft_dungeon_master(p, s, c, m);
	return (p);
}
