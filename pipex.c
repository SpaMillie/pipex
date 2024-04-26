/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:59:57 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/26 18:36:53 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(char **envp, t_filedes *cripto, t_captains *log)
{
	if (cripto->fd_cls != -1)
		close (cripto->fd_cls);
	if (dup2(cripto->fd_in, STDIN_FILENO) == -1)
		perror_exit("dup2", 1, log);
	close (cripto->fd_in);
	if (dup2(cripto->fd_out, STDOUT_FILENO) == -1)
		perror_exit("dup2", 1, log);
	close (cripto->fd_out);
	execve(log->cmnd_path[log->cm_num], log->execve_args[log->cm_num], envp);
	perror_exit(log->execve_args[log->cm_num][0], 1, log);	
}

void	init_fds(t_captains *log, t_filedes *cripto, int i, int **fds, int old)
{
	if (i == 0)
	{
		cripto->fd_in = log->fd_in;
		cripto->fd_out = *fds[1];
		cripto->fd_cls = *fds[0];
	}
	else if (i == log->arg_c - 1)
	{
		cripto->fd_in = old;
		cripto->fd_out = log->fd_out;
		cripto->fd_cls = -1;	
	}
	else
	{
		cripto->fd_in = old;
		cripto->fd_out = *fds[1];
		cripto->fd_cls = *fds[0];
	}
}

void	ft_parent(char **envp, t_captains *log, t_filedes *cripto)
{
	int fds[2];
	int	oldfd;
	int	i;

	i = 0;
	while (i < log->arg_c)
	{
		if (i != log->arg_c - 1 && pipe(fds) == -1)
			perror_exit("pipe", -1, log);
		init_fds(log, cripto, i, &fds, oldfd);
		oldfd = fds[0];
		log->pids[i] = fork();
		if (log->pids[i] == -1)
				perror_exit("pid", -1, log);
		if (log->pids[i] == 0)
			ft_child(envp, cripto, log);
		else
		{
			close(cripto->fd_in);
			close(cripto->fd_out);
		}
		log->cm_num++;
		i++;
	}
	log->pids[i] = -2;
}

int	ft_pipex(char **envp, t_captains *log)
{
	t_filedes	cripto;
	int			i;

	log->cm_num = 0;
	i = 0;
	log->pids = (int *)malloc(sizeof(int) * (log->arg_c - 1));
	if (!log->pids)
		perror_exit("malloc", -1, log);
	ft_parent(envp, log, &cripto);
	while (log->pids[i] != -2)
		wait(log->pids[i++]);
	return (0);
}
