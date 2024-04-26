/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:49:22 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/26 20:35:06 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	if_valid_file(char *file1, char *file2, t_captains *log)
{
	printf("entering if_valid_file\n");
	log->file1 = pipex_strjoin("./", file1, 0);
	log->file2 = pipex_strjoin("./", file2, 0);
	if (!log->file1 || !log->file2)
		perror_exit("malloc", -1, log);
	log->fd_in = open(file1, O_RDONLY);
	if (log->fd_in == -1)
		perror_exit(file1, 1, log);
	log->fd_out = open(file2, O_WRONLY);
	if (log->fd_out != -1)
		return ;
	perror_exit(file2, 1, log);
	printf("exiting if_valid_file\n");
}

int	if_valid_command(char *command, t_captains *log, int com_num)
{
	int	i;
	printf("entering if_valid_command\n");
	i = 0;
	printf("%s\n", log->paths[i]);
	while (log->paths[i] != NULL)
	{
		if (i != 0)
			free(log->cmnds[com_num]);
		printf("%s and %d\n", log->paths[i], i);
		printf("%d\n", com_num);
		log->cmnds[com_num] = pipex_strjoin(log->paths[i], command, 0);
		if (access(log->cmnds[com_num], X_OK) != -1)
		{
			printf("exiting if_valid_command\n");
			return (0);
		}
		i++; 
	}
	free(log->cmnds[com_num]);
	log->cmnds[com_num] = command;
	return (-1);
}
