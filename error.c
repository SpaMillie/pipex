/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:48:44 by mspasic           #+#    #+#             */
/*   Updated: 2024/05/13 12:34:23 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	file_permission(t_captains *log, char *file)
{
	log->err_no = -2;
	perror_exit(file, 1, log, 2);
	return (-1);
}

int	invalid_argument(int option, t_captains *log, char *str, int com_num)
{
	if (option == 1)
	{
		log->execve_args[com_num][0] = str;
		perror_exit(str, 1, log, 3);
	}
	write(1, "pipex: invalid arguments\n", 26);
	return (0);
}
char	**free_all(char **res);

void	free_to_cleanup(t_captains *log)
{
	// free(log->file1);
	// free(log->file2);
	free(log->pids);
	free(log->cmnd_path);
	free_all(log->cmmndswflgs);
	free_all(log->paths);
	free_triple(log);
}

void	free_triple(t_captains *log)
{
	int	i;

	i = 0;
	while (log->execve_args[i] != NULL)
		free_all(log->execve_args[i++]);
	free(log->execve_args);
	}

void	perror_exit(char *str, int to_free, t_captains *log, int option)
{
	if (to_free == -1)
		log->err_no = -2;
	if (log->err_no != -1)
	{
		if (option == 1)
			perror(str);
		else if (option == 3)
		{
			write(2, "pipex: ", 8);
			write(2, str, (ft_strlen(str) + 1));
			write(2, ": command not found\n", 21);
		}
		else
		{
			write(2, "pipex: ", 8);
			perror(str);
		}
		log->err_no = -1;
	}
	if (to_free == -1)
	{
		free_to_cleanup(log);
		exit(EXIT_FAILURE);
	}
}
