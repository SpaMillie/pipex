/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:49:22 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/16 17:58:26 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	if_valid_file(char *file1, char *file2, t_captains *log)
{
	printf("entering if_valid_file\n");
	log->fd_in = open(file1, O_RDONLY);
	if (log->fd_in == -1)
	{
		perror(file1);
		return (-1);
	}
	log->fd_out = open(file2, O_WRONLY);
	if (log->fd_out != -1)
	{
		printf("exiting if_valid_file\n");
		return (0);
	}
	perror(file2);
	close(log->fd_in);
	return (-1);
}

int	if_valid_command(char *command, t_captains *log, int com_num)
{
	int	i;
	printf("entering if_valid_command\n");
	i = 0;
	while (log->paths[i] != NULL)
	{
		if (i != 0)
			free(log->cmnds[com_num]);
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
