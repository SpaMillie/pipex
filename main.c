/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:08:04 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/09 20:21:08 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	if_valid_file(char *file1, char *file2, t_params *params)
{
	params->fd_in = open(file1, O_RDONLY);
	if (params->fd_in == -1)
	{
		perror("infile");
		return (-1);
	}
	params->fd_out = open(file2, O_WRONLY);
	if (params->fd_out != -1)
		return (0);
	perror("outfile");
	close(params->fd_in);
	return (-1);
}

int	if_valid_command(char *command, t_params *params)
{
	//use env to get possible paths
	//check if any of the possible paths are valid
	//if yes, save it in the struct
	//if no, return -1
	//use access, x_OK
}

int	check_if_valid(char **argv, t_params *params)
{	
	if (if_valid_file(argv[0], argv[3], params) == -1)
	{

		return (-1);
	}
	if (if_valid_command(argv[1], params) == -1)
		return (-1);
	if (if_valid_command(argv[2], params) == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	int			check;
	t_params	params;

	if (argc == 5)
	{
		check = check_if_valid(argv + 1, &params);
		printf("checck iis %d\n", check);
		if (check == -1)
			return (invalid_argument());
	}
	else
		return(invalid_argument());
}
