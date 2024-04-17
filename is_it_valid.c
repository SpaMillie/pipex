/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:49:22 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/17 15:12:45 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	if_valid_file(char *file1, char *file2, t_captains *log)
{
	printf("entering if_valid_file\n");
	log->file1 = pipex_strjoin("./", file1, 0);
	log->file2 = pipex_strjoin("./", file2, 0);
	if (!log->file1 || !log->file2)
	{
		free_everything(log);
		return (-1);
	}
	log->fd_in = open(file1, O_RDONLY);
	if (log->fd_in == -1)
	{
		perror(file1);
		return (-1);
	}
	log->fd_out = open(file2, O_WRONLY);
	if (log->fd_out != -1)
		return (0);
	perror(file2);
	free(file1);
	free(file2);
	close(log->fd_in);
	return (-1);
}

int	if_valid_command(char *command, t_captains *log, int com_num)
{
	int	i;
	printf("entering if_valid_command\n");
	i = 0;
	printf("%s and %d\n", log->paths[i], i);
	while (log->paths[i] != NULL)
	{
		if (i != 0)
			free(log->cmnds[com_num]);
		printf("%s and %d\n", log->paths[i], i);
		printf("%d\n", com_num);
		printf("%.1s\n", *log->cmnds);
		printf("%s\n", log->cmnds[com_num]);
		log->paths[i] = pipex_strjoin(log->paths[i], "/", 1);
		log->cmnds[com_num] = pipex_strjoin(log->paths[i], command, 1);
		if (access(log->cmnds[com_num], X_OK) != -1)
		{
			printf("exiting if_valid_command\n");
			return (0);
		}
		i++; 
	}
	free(log->cmnds[com_num]);
	return (-1);
}
