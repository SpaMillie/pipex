/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:43:46 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/30 18:53:55 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pathfinder(t_captains *log, int com_num, char *command)
{
	int	i;
	//printf("ENTERING PATHFINDER\n");
	i = 0;
	//printf("%s and %d\n", log->paths[i], i);
	if (ft_strchr(command, '/') != NULL && access(command, X_OK) != -1)
		return ;
	if (ft_strchr(command, '/') == NULL)
	{
		while (log->paths[i] != NULL)
		{
			if (i != 0)
				free(log->cmnd_path[com_num]);
			//printf("the path is %s and %d\n", log->paths[i], i);
			//printf("com_num is %d\n", com_num);
			log->cmnd_path[com_num] = pipex_strjoin(log->paths[i], command, 0);
			if (!log->cmnd_path[com_num])
				perror_exit("pipex: malloc", -1, log, 1);
			if (access(log->cmnd_path[com_num], X_OK) != -1)
			{
				log->execve_args[com_num][0] = log->cmnd_path[com_num];
				//printf("command with path is %s\n", log->cmnd_path[com_num]);
				//printf("exiting pathfinder\n");
				return ;
			}
			i++;
		}
	}
	perror_exit(command, 1, log, 3);
}

void	opening_files(char *file1, char *file2, t_captains *log)
{
	//printf("entering OPENING_FILES\n");
	log->fd_in = open(file1, O_RDONLY);
	if (log->fd_in == -1)
		perror_exit(file1, 1, log, 2);
	log->fd_out = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (log->fd_out == -1 && (EEXIST == errno))
		log->fd_out = open(file2, O_WRONLY);
	if (log->fd_out != -1)
		return ;
	perror_exit(file2, 1, log, 2);
}

void	open_n_parse(char **argv, t_captains *log)
{
	int	i;
	//printf("entering open_n_parse\n");
	opening_files(argv[0], argv[log->arg_c - 1], log);
	i = 0;
	while (log->cmmndswflgs[i] != NULL)
	{
		//printf("commands with flags is %s\n", log->cmmndswflgs[i]);
		pipex_split(log->cmmndswflgs[i], ' ', log, i);
		//printf("i is %d\n", i);
		i++;
	}
	i = 0;
	while (i < log->arg_c - 2)
	{
		pathfinder(log, i, log->execve_args[i][0]);
		i++;
	}
	//printf("exiting open_n_parse\n");
}
