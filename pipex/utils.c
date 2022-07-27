/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:38:05 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_error(void)
{
	ft_putstr_fd("\033[31mError:\e[0m PATH= not found ", 2);
	exit(0);
}

void	command_error(char *command)
{
	ft_putstr_fd("\033[31mError:\e[0m command not found: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void	file_error(char *file)
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void	p_error(void)
{
	perror("\033[31mError:\e[0m ");
	exit(0);
}

void	arg_error(void)
{
	ft_putstr_fd("\033[31mError:\e[0m Wrong number of arguments.\n", 2);
	ft_putstr_fd("Example: ./pipex file1 'cmd1' 'cmd2' file2\n", 2);
	exit(0);
}
