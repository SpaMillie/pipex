/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:08:04 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/12 20:46:03 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	if_valid_file(char *file1, char *file2, t_captains *log)
{
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
	close(log->fd_in);
	return (-1);
}
int	if_valid_command(char *command, t_captains *log, int com_num)
{
	int	i;

	i = 0;
	while (log->cmmndswflgs[i] != NULL)
		//do you even need to malloc all this or can you just point at the right parts?
	while (log->paths[i] != NULL)
	{
		if (i != 0)
			free(log->cmnds[com_num]);
		log->cmnds[com_num] = pipex_strjoin(log->paths[i], "/", 0);
		log->cmnds[com_num] = pipex_strjoin(log->cmnds[com_num], command, 1);
		if (access(log->cmnds[com_num], X_OK) != -1)
			return (0);
		i++; 
	}
	free(log->cmnds[com_num]);
	return (-1);
}

int	parsing_commands(t_captains *log, int count)
{
	int	check;

	while (log->cmmndswflgs[count] != NULL)
		count++;
	log->cmnds = malloc((sizeof(char *) * count + 1));
	if (log->cmnds == NULL)
		return (-1);
	log->flags = malloc((sizeof(char *) * count + 1));
	if (log->flags == NULL)
		return (-1);
	count = 0;
	while (log->cmmndswflgs[count] != NULL)
	{
		check = pipex_split(log->cmmndswflgs[count], ' ', log, 1);
		if (check == -1)
			return (-1);
		check = pipex_split(log->cmmndswflgs[count], ' ', log, 2);
		if (check == -1)
			return (-1);
		count++;
	}
	log->cmnds[count] = NULL;
	log->flags[count] = NULL;
	return (0);
}

int	check_if_valid(char **argv,  t_captains *log)
{
	int	i;

	if (if_valid_file(argv[0], argv[log->arg_c], log) == -1)
		return (-1);
	i = parsing_commands(log, 0);
	if (i == -1)
		return (-1);
	i = 0;
	while (i + 1 < log->arg_c)
	{
		if (if_valid_command(log->cmmndswflgs[i], log, i) == -1)
		{
			perror(argv[i + 1]);
			return (-1);
		}
		i++;
	}
	return (0);
}
void	initialise(int argc, char **argv, char **envp, t_captains *log)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 4) != 0)
			i++;
	log->paths = ft_split(envp[i] + 5, ':');
	log->arg_c = argc - 1;
	i = 0;
	while (i + 2 < log->arg_c)
	{
		log->cmmndswflgs[i] = argv[i + 2];
		i++; 
	}
}

int	main(int argc, char **argv, char **envp)
{
	int			check;
	t_captains	log;

	if (argc == 5) //for bonus >= 5
	{
		intialise(argc, argv, envp, &log);
		check = check_if_valid(argv + 1, &log);
		if (check == -1)
			return (1);
	}
	else
		return(invalid_argument());
}
