/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:34:59 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:43:26 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_ad;

	if (!str)
		return (NULL);
	str_ad = malloc(sizeof(char) * ft_strlen((char *)str) + 1);
	if (str_ad == NULL)
		return (NULL);
	ft_memcpy(str_ad, str, ft_strlen((char *)str) + 1);
	return (str_ad);
}
