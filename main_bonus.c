/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:08:04 by mspasic           #+#    #+#             */
/*   Updated: 2024/05/13 20:58:13 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	init_cmndsflgs(t_captains *log, char **argv)
{
	int	i;

	i = 0;
	while (i + 2 < log->arg_c)
	{
		log->cmmndswflgs[i] = ft_strdup(argv[i + 2]);
		////printf("commands with flags is %s\n", log->cmmndswflgs[i]);
		i++;
	}
	log->cmmndswflgs[i] = NULL;
	log->err_no = -2;
}

void	init_env(t_captains *log, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] != NULL)
	{
		log->paths = ft_split(envp[i] + 5, ':');
		i = 0;
		while (log->paths[i] != NULL)
		{
			log->paths[i] = pipex_strjoin(log->paths[i], "/", 1);
			i++;
		}
	}
}

void	initialise(int argc, char **argv, char **envp, t_captains *log)
{
	int	i;

	// ////printf("entering initialise\n");
	i = 0;
	init_env(log, envp);
	log->arg_c = argc - 1;
	log->cmmndswflgs = (char **)malloc(sizeof(char *) * (argc - 2));
	if (!log->cmmndswflgs)
		perror_exit("pipex: malloc", -1, log, 1);
	init_cmndsflgs(log, argv);
	////printf("exiting initialise\n");
}

int	main(int argc, char **argv, char **envp)
{
	// int			check;
	t_captains	log;
	int			status;

	if (argc >= 5) //for bonus >= 5
	{
		log = (t_captains){0};
		initialise(argc, argv, envp, &log);
		open_n_parse(argv + 1, &log);
		// if (check == -1)
		// {
		// 	free_everything(&log);
		// 	return (1);
		// }
		////printf("ENTERING PIPEX\n");
		status = ft_pipex(envp, &log);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		else
			status = WTERMSIG(status);
		free_to_cleanup(&log);
		return (status);
	}
	else
		return (invalid_argument(0, &log, NULL, 0));
}