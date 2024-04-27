/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:43:46 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/27 18:09:23 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pathfinder(t_captains *log, int com_num, char *command)
{
	int	i;
	printf("entering pathfinder\n");
	i = 0;
	printf("%s and %d\n", log->paths[i], i);
	//check if it it's with a path and if it is save handle it for split
	while (log->paths[i] != NULL)
	{
		if (i != 0)
			free(log->cmnd_path[com_num]);
		printf("%s and %d\n", log->paths[i], i);
		printf("%d\n", com_num);
		log->paths[i] = pipex_strjoin(log->paths[i], "/", 1);
		log->cmnd_path[com_num] = pipex_strjoin(log->paths[i], command, 1);
		log->cmnd_path[com_num] = pipex_strjoin(log->paths[i], command, 0);
		if (access(log->cmnd_path[com_num], X_OK) != -1)
		{
			printf("command with path is %s\n", log->cmnd_path[com_num]);
			printf("exiting pathfinder\n");
			return ;
		}
		i++; 
	}
	free(log->cmnd_path[com_num]);
	log->cmnd_path[com_num] = command;
	printf("erroring in pathfinder\n");
	return ;
}

void	opening_files(char *file1, char *file2, t_captains *log)
{
	printf("entering if_valid_file\n");
	log->file1 = pipex_strjoin("./", file1, 0);
	log->file2 = pipex_strjoin("./", file2, 0);
	if (!log->file1 || !log->file2)
		perror_exit("pipex: malloc", -1, log, 1);
	log->fd_in = open(file1, O_RDONLY);
	if (log->fd_in == -1)
		perror_exit(file1, 1, log, 2);
	log->fd_out = open(file2, O_WRONLY);
	if (log->fd_out != -1)
		return ;
	perror_exit(file2, 1, log, 2);
}

void	allocate(t_captains *log)
{
	int	i;

	printf("entering allocate\n");
	i = 0;
	log->execve_args = (char ***)malloc((sizeof(char **) * (log->arg_c - 1)));
	if (!log->execve_args)
		perror_exit("pipex: malloc", -1, log, 1);
	while (i < log->arg_c - 1)
	{
		log->execve_args[i] = (char **)malloc(sizeof(char *) * 3);
		if (!log->execve_args[i])
			perror_exit("pipex: malloc", -1, log, 1);
		i++;
	}
	printf("exiting allocate\n");
}

void	open_n_parse(char **argv, t_captains *log)
{
	int	i;
	printf("entering open_n_parse\n");
	opening_files(argv[0], argv[log->arg_c - 1], log);
	allocate(log);
	i = 0;
	while (log->cmmndswflgs[i] != NULL)
	{
		printf("commands with flags is %s\n", log->cmmndswflgs[i]);
		pipex_split(log->cmmndswflgs[i], ' ', log, i);
		printf("i is %d\n", i);
		i++;
	}
	i = 0;
	while (i < log->arg_c - 2)
	{
		pathfinder(log, i, log->execve_args[i][0]);
		i++;
	}
	printf("exiting open_n_parse\n");
}
