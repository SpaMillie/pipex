/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:08:04 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/16 20:38:06 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	allocate(t_captains *log)
{
	int	count;
	printf("entering allocate\n");
	count = 0;
	while (log->cmmndswflgs[count] != NULL)
		count++;
	log->cmnds = malloc((sizeof(char *) * (count + 1)));
	if (log->cmnds == NULL)
		return (-1);
	log->flags = malloc((sizeof(char *) * (count + 1)));
	if (log->flags == NULL)
	{
		free(log->cmnds);
		return (-1);
	}
	printf("exiting allocate\n");
	return (0);
}

int	parsing_commands(t_captains *log, int count) //should you be putting perror everywhere?
{
	int	check;
	printf("entering parsing_command\n");
	count = allocate(log);
	if (count == -1)
		return (-1);
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
	printf("exiting parsing_command\n");
	return (0);
}

int	check_if_valid(char **argv,  t_captains *log)
{
	int	i;
	printf("entering check_if_valid\n");
	if (if_valid_file(argv[0], argv[log->arg_c], log) == -1)
		return (-1);
	printf
	i = parsing_commands(log, 0);
	if (i == -1)
		return (-1);
	while (i + 1 < log->arg_c)
	{
		if (if_valid_command(log->cmnds[i], log, i) == -1)
		{
			perror(argv[i + 1]);
			return (-1);
		}
		i++;
	}
	printf("exiting check_if_valid\n");
	return (0);
}
void	initialise(int argc, char **argv, char **envp, t_captains *log)
{
	int	i;

	printf("entering initialise\n");
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
			i++;
	log->paths = ft_split(envp[i] + 5, ':');
	log->arg_c = argc - 1;
	log->cmmndswflgs = (char **)malloc(sizeof(char *) * (argc - 2));
	if (!log->cmmndswflgs)
	{
		perror("pipex: initialise");
		return ;
	}
	i = 0;
	while (i + 2 < log->arg_c)
	{
		log->cmmndswflgs[i] = ft_strdup(argv[i + 2]);
		i++; 
	}
	log->cmmndswflgs[i] = NULL;
	printf("exiting initialise\n");
}

int	main(int argc, char **argv, char **envp)
{
	int			check;
	t_captains	log;

	if (argc == 5) //for bonus >= 5
	{
		initialise(argc, argv, envp, &log);
		check = check_if_valid(argv + 1, &log);
		if (check == -1)
			return (1);
	}
	else
		return(invalid_argument());
}
