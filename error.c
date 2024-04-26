/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:48:44 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/26 16:20:52 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	invalid_argument(void)
{
	write(1, "pipex: invalid arguments\n", 26);
	return (0); //cant do this, use perror or strerror
}
char	**free_all(char **res);
void	free_everything(t_captains *log)
{
	free(log->file1);
	free(log->file2);
	free_all(log->cmmndswflgs);
	free_all(log->cmnds);
	printf("flags is %p\n", log->flags);
	free_all(log->flags);
	free_all(log->paths);
}

void	ft_perror(char *str, int fail)
{
	if (fail == 1)
		write(2, "pipex: command not found: ", 26);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
void	perror_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
