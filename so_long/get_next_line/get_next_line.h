/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 08:00:21 by lharwood          #+#    #+#             */
/*   Updated: 2022/04/19 11:22:01 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
int			ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *str);
char		*ft_strchr(const char *str, int n);
int			check(char **line, char **buffer);
void		check_line(char **line, char *tmp);
void		fill_line(char **line, char **buffer, int fd);

#endif
