/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:37:36 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
char	*ft_strrchr(char	*c, int	ch)
{
	int				i;

	i = 0;
	while (*c)
	{
		c++;
		i++;
	}
	while (i >= 0)
	{
		if (*c == (char)ch)
			return ((char *)c);
		c--;
		i--;
	}
	return (NULL);
}
