/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:59:57 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/24 18:56:29 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipex(t_captains *log, char **envp)
{
	int		fd[2][2]; //can this be const for norm?
	pid_t	pid;

	if (pipe(fd[0]) != -1)
	{
		
	}
	perror("pipex: ft_pipex");
	//free everything?
	exit(EXIT_FAILURE); //skontaj konacno
}
