/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:08:04 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/27 14:33:38 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

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
	printf("exiting open_n_parse\n");
}

void	initialise(int argc, char **argv, char **envp, t_captains *log)
{
	int	i;

	printf("entering initialise\n");
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	log->paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (log->paths[i] != NULL)
	{
		log->paths[i] = pipex_strjoin(log->paths[i], "/", 1);
		i++;
	}
	i = 0;
	log->arg_c = argc - 1;
	log->cmmndswflgs = (char **)malloc(sizeof(char *) * (argc - 2));
	if (!log->cmmndswflgs)
		perror_exit("pipex: malloc", -1, log, 1);	
	i = 0;
	while (i + 2 < log->arg_c)
	{
		log->cmmndswflgs[i] = ft_strdup(argv[i + 2]);
		printf("commands with flags is %s\n", log->cmmndswflgs[i]);
		i++;
	}
	log->cmmndswflgs[i] = NULL;
	printf("exiting initialise\n");
}

int	main(int argc, char **argv, char **envp)
{
	// int			check;
	t_captains	log;

	if (argc == 5) //for bonus >= 5
	{
		// log = (t_captains){0}; //look up compound literals
		initialise(argc, argv, envp, &log);
		open_n_parse(argv + 1, &log);
		// if (check == -1)
		// {
		// 	free_everything(&log);
		// 	return (1);
		// }
		ft_pipex(envp, &log);
		free_to_cleanup(&log);
	}
	else
		return (invalid_argument());
}
