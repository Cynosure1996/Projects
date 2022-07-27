/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharwood <lharwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:38:05 by lharwood          #+#    #+#             */
/*   Updated: 2021/10/27 00:39:16 by lharwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_path(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + 5, ':');
			if (!path)
				path_error();
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*get_full_path(char **paths, char *command)
{
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/", command);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	command_error(command);
	return (NULL);
}

void	child_process1(int *fd, char **argv, char **env)
{
	int		in_file;
	char	**paths;
	char	*full_path;
	char	**command;
	int		i;

	i = 0;
	in_file = open(argv[1], O_RDONLY);
	if (in_file < 0)
		file_error(argv[1]);
	dup2(fd[1], 1);
	dup2(in_file, 0);
	close(fd[0]);
	paths = parse_path(env);
	command = ft_split(argv[2], ' ');
	full_path = get_full_path(paths, command[0]);
	while (paths[i++])
		free(paths[i]);
	free(paths);
	execve(full_path, command, env);
}

void	child_process2(int *fd, char **argv, char **env)
{
	int		out_file;
	char	**paths;
	char	*full_path;
	char	**command;
	int		i;

	i = 0;
	out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out_file < 0)
		file_error(argv[5]);
	dup2(out_file, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	paths = parse_path(env);
	command = ft_split(argv[3], ' ');
	full_path = get_full_path(paths, command[0]);
	while (paths[i++])
		free(paths[i]);
	free(paths);
	execve(full_path, command, env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return (-1);
		pid = fork();
		if (pid == -1)
			p_error();
		else if (pid == 0)
			child_process1(fd, argv, env);
		pid = fork();
		if (pid == -1)
			p_error();
		if (pid == 0)
			child_process2(fd, argv, env);
		return (0);
	}
	arg_error();
	return (0);
}
