/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassand <fcassand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:41:56 by fcassand          #+#    #+#             */
/*   Updated: 2021/10/23 02:03:46 by fcassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *f, size_t len)
{
	char	*ret;
	int		flag;

	ret = (char *)0;
	flag = 0;
	if (ft_strlen(f) == 0)
		return ((char *)str);
	if (len != 0)
	{
		while (*str && ft_strlen(f) <= len)
		{
			flag = ft_strncmp((char *)str, (char *)f, ft_strlen(f));
			if (*str == *f && flag == 0)
				ret = (char *)str;
			str++;
			len--;
			if (ret)
				break ;
		}
	}
	return (ret);
}
