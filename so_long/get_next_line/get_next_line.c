/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:59:37 by lharwood          #+#    #+#             */
/*   Updated: 2021/12/26 08:04:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check(char **buffer, char **line)
{
	char	*now;
	char	*later;

	if (*buffer != NULL)
	{
		now = ft_strchr(*buffer, '\n');
		if (now)
		{
			later = ft_strdup(now + 1);
			*(now + 1) = '\0';
			*line = ft_strdup(*buffer);
			free(*buffer);
			*buffer = later;
			return (1);
		}
		else
		{
			if (**buffer != 0)
				*line = *buffer;
			else
				free (*buffer);
		}
		*buffer = NULL;
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

void	fill_line(char **buffer, char **line, int fd)
{
	char	temp[BUFFER_SIZE + 1];
	char	*p_n;
	int		bwr;

	bwr = 1;
	while (!(ft_strchr(*line, '\n')) && bwr != 0)
	{
		bwr = read(fd, temp, BUFFER_SIZE);
		if (bwr <= 0)
			return ;
		temp[bwr] = '\0';
		p_n = ft_strchr(temp, '\n');
		if (p_n && bwr > 0)
		{
			if (*(p_n + 1) == '\0')
				*buffer = NULL;
			else
				*buffer = ft_strdup(p_n + 1);
			*(p_n + 1) = '\0';
		}
		check_line(line, temp);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	line = NULL;
	if (read(fd, line, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (check(&buffer, &line))
		return (line);
	fill_line(&buffer, &line, fd);
	return (line);
}
