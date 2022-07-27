/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:38:05 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/errno.h>

char	**parse_path(char **env);
char	*get_full_path(char **paths, char *command);
void	child_process1(int *fd, char **argv, char **env);
void	child_process2(int *fd, char **argv, char **env);
int		main(int argc, char **argv, char **env);
void	path_error(void);
void	command_error(char *command);
void	file_error(char *file);
void	p_error(void);
void	arg_error(void);

#endif
