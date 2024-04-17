/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:48:44 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/17 17:52:26 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	invalid_argument(void)
{
	write(1, "Argument error\n", 24);
	return (0); //cant do this, use perror or strerror
}
char	**free_all(char **res);
void	free_everything(t_captains *log)
{
	if (log->file1 != NULL)
		free(log->file1);
	if (log->file2 != NULL)
		free(log->file2);
	if (log->cmmndswflgs != NULL)
		free_all(log->cmmndswflgs);
	if (log->cmnds != NULL)
		free_all(log->cmnds);
	if (log->flags != NULL)
		free_all(log->flags);
	if (log->paths != NULL)
		free_all(log->paths);
}

void	ft_perror(char *str, int fail)
{
	if (fail == 1)
		write(2, "pipex: command not found: ", 26);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}