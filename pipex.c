/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:59:57 by mspasic           #+#    #+#             */
/*   Updated: 2024/05/13 17:02:11 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(char **envp, t_filedes *cripto, t_captains *log)
{
	// ////printf("entering ft_child\n");
	if (cripto->fd_cls != -2)
		close (cripto->fd_cls);
	// ////printf("so far so good\n");
	if (dup2(cripto->fd_in, STDIN_FILENO) == -1)
		perror_exit("pipex: dup2", 1, log, 1);
	// ////printf("2so far so good\n");
	close (cripto->fd_in);
	if (dup2(cripto->fd_out, STDOUT_FILENO) == -1)
		perror_exit("pipex: dup2", 1, log, 1);
	close (cripto->fd_out);
	if (log->cm_num == 0 && log->fd_in == -1)
			log->err_no = -1;
	execve(log->execve_args[log->cm_num][0], log->execve_args[log->cm_num], \
		envp);
	perror_exit(log->execve_args[log->cm_num][0], 1, log, 2);
}

int	init_fds(t_captains *log, t_filedes *cripto, int *fds, int old)
{
	cripto->fd_in = old;
	cripto->fd_out = fds[1];
	cripto->fd_cls = fds[0];
	// ////printf("entering init_fds\n");
	if (cripto->i == 0)
	{
		cripto->fd_in = log->fd_in;
		if (log->fd_in == -1)
			return (-1);
	}
	else if (cripto->i == log->arg_c - 3)
	{
		// ////printf("outfile fd is %d\n", log->fd_out);
		cripto->fd_out = log->fd_out;
		cripto->fd_cls = -2;
		if (log->fd_out == -1)
			return (-1);
	}
	return (0);
	// ////printf("fdin is %d and fdout is %d and fdcls is %d\n", cripto->fd_in, cripto->fd_out, cripto->fd_cls);
	// ////printf("exiting init_fds\n");
}

void	forking(char **envp, t_captains *log, t_filedes *cripto)
{
	log->pids[cripto->i] = fork();
	if (log->pids[cripto->i] == -1)
		perror_exit("pipex: pid", -1, log, 1);
	if (log->pids[cripto->i] == 0)
		ft_child(envp, cripto, log);
}

void	ft_parent(char **envp, t_captains *log, t_filedes *cripto)
{
	int	fds[2];
	int	oldfd;
	int	to_f_or_not;
	// printf("entering ft_parent\n");
	cripto->i = 0;
	while (cripto->i < log->arg_c - 2)
	{
		if (cripto->i != log->arg_c - 3)
			if (pipe(fds) == -1)
				perror_exit("pipex: pipe", -1, log, 1);
		to_f_or_not = init_fds(log, cripto, fds, oldfd);
		oldfd = fds[0];
		if (to_f_or_not != -1 && log->execve_args[cripto->i][0][0] != 9)
			forking(envp, log, cripto);
		if (cripto->fd_in != -1)
			close(cripto->fd_in);
		if (cripto->fd_out != -1)
			close(cripto->fd_out);
		log->cm_num++;
		cripto->i++;
	}
	// printf("exiting ft_parent\n");
}

int	ft_pipex(char **envp, t_captains *log)
{
	t_filedes	cripto;
	int			i;
	int			status;

	// printf("entering ft_pipex\n");
	log->cm_num = 0;
	i = 0;
	log->pids = (int *)malloc(sizeof(int) * (log->arg_c - 2));
	if (!log->pids)
		perror_exit("pipex: malloc", -1, log, 1);
	ft_parent(envp, log, &cripto);
	i = 0;
	while (i < log->arg_c - 2)
		waitpid(log->pids[i++], &status, 0);
	if (log->fd_out == -1)
		status = 1;
	else if (log->execve_args[i - 1][0][0] == 9)
		status = 127;
	// printf("exiting ft_pipex\n");
	return (status);
}
