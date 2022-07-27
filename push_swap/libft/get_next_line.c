/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:14:37 by fcassand          #+#    #+#             */
/*   Updated: 2022/04/03 05:44:23 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_buff(char **buff, char **line)
{
	char	*rem;
	char	*help;

	if (*buff != NULL)
	{
		rem = ft_strchr(*buff, '\n');
		if (rem)
		{
			help = ft_strdup(rem + 1);
			*(rem + 1) = '\0';
			*line = ft_strdup(*buff);
			free(*buff);
			*buff = help;
			return (1);
		}
		else
		{
			if (**buff != '\0')
				*line = *buff;
			else
				free(*buff);
		}
		*buff = NULL;
	}
	return (0);
}

void	check_line(char **line, char *tmp)
{
	char	*tmp1;

	tmp1 = *line;
	if (*line)
		*line = ft_strjoin(*line, tmp);
	else
		*line = ft_strdup(tmp);
	free(tmp1);
}

void	ret_line(char **buff, char **line, int fd)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*p_n;
	int		bwr;

	bwr = 1;
	while (!(ft_strchr(*line, '\n')) && bwr != 0)
	{
		bwr = read(fd, tmp, BUFFER_SIZE);
		if (bwr <= 0)
			return ;
		tmp[bwr] = '\0';
		p_n = ft_strchr(tmp, '\n');
		if (p_n && bwr > 0)
		{
			if (*(p_n + 1) == '\0')
				*buff = NULL;
			else
				*buff = ft_strdup(p_n + 1);
			*(p_n + 1) = '\0';
		}
		check_line(line, tmp);
	}
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	line = NULL;
	if (read(fd, line, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (check_buff(&buff, &line))
		return (line);
	ret_line(&buff, &line, fd);
	return (line);
}
