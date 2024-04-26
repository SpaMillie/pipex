/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:48:44 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/26 19:55:51 by mspasic          ###   ########.fr       */
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
	free(log->pids);
	free_all(log->cmmndswflgs);
	free_all(log->paths);
}

// void	ft_perror(char *str, int fail)
// {
// 	if (fail == 1)
// 		perror_exit(str);
// 	if (fail == 2)
// 		write(2, "pipex: malloc failed", 20);
// 	write(2, str, ft_strlen(str));
// 	write(2, "\n", 1);
// 	exit(EXIT_FAILURE);
// }
void	perror_exit(char *str, int to_free, t_captains *log)
{
	perror("pipex: ");
	write (2, ": ", 2);
	write(2, str, ft_strlen(str));
	if (to_free == -1)
		free_everything(log);
	exit(EXIT_FAILURE);
}
