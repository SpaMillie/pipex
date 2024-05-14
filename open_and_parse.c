/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:43:46 by mspasic           #+#    #+#             */
/*   Updated: 2024/05/14 14:12:42 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pathfinder(t_captains *log, int com_num, char *command)
{
	int	i;

	i = 0;
	if (ft_strchr(command, '/') == NULL)
	{
		while (log->paths != NULL && log->paths[i] != NULL)
		{
			if (i != 0)
				free(log->cmnd_path);
			log->cmnd_path = pipex_strjoin(log->paths[i], command, 0);
			if (!log->cmnd_path)
				perror_exit("pipex: malloc", -1, log, 1);
			if (access(log->cmnd_path, X_OK) != -1)
			{
				free (command);
				log->execve_args[com_num][0] = log->cmnd_path;
				return ;
			}
			i++;
		}
	}
	free(log->cmnd_path);
	set_errno(log, com_num);
	perror_exit(command, 1, log, 3);
	log->execve_args[com_num][0][0] = 9;
}

int	opening_files(char *file, t_captains *log, int option)
{
	int	fd;

	if (option == 1)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		file_permission(log, file);
	return (fd);
}

void	open_n_parse(char **argv, t_captains *log)
{
	int	i;

	log->fd_in = opening_files(argv[0], log, 1);
	i = 0;
	while (log->cmmndswflgs[i] != NULL)
	{
		pipex_split(log->cmmndswflgs[i], log, i);
		i++;
	}
	i = 0;
	while (i < log->arg_c - 2)
	{
		if (i == log->arg_c - 3)
			log->fd_out = opening_files(argv[log->arg_c - 1], log, 2);
		if (ft_strchr(log->execve_args[i][0], '/') == NULL && \
			access(log->execve_args[i][0], X_OK) == -1)
		{
			if (w_count(log->execve_args[i][0], 32, log) != 0 || \
			w_count(log->execve_args[i][0], 7, log) != 0)
				pathfinder(log, i, log->execve_args[i][0]);
		}
		i++;
	}
}
