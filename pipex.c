/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:59:57 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/25 18:55:25 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void

int	ft_child(char **envp, int fd_in, int fd_out, int fd_cls, t_captains *log)
{
	close (fd_cls);
	if (dup2(fd_in, STDIN_FILENO) == -1)
	{
		perror("pipex : dup2: ");
		//ovo treba svaki put?
	}
	close (fd_in);
	dup2(fd_out, STDOUT_FILENO);
	close (fd_out);
	execve(log->cmnd_path[log->cm_num], log->execve_args[log->cm_num], envp);
	perror("pipex: execve: ");
	exit(EXIT_FAILURE);
}

int	ft_parent(char **envp, t_captains *log, t_filedes *criptors)
{
	pid_t	pid;
	int		cm_num;
	int		i;

	cm_num = 0;
	i = 0;
	while (cm_num < log->arg_c - 4)
	{
		if (pipe(log->fds[i]) == -1)
		{
			perror("pipex: pipe: ");
			exit(EXIT_FAILURE); //skontaj konacno	
		}
		pid = fork();
		if (pid == -1)
		{
			perror("pipex: pid");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
			ft_child(envp, log->fd_in, log->fds[i][1], log->fds[i][0], log);
		else
		{
			wait(NULL);
			close(log->fd_in);
			close(log->fds[i][1]);
		}
		i++;
		cm_num++;
	}
}

int	ft_pipex(char **envp, t_captains *log)
{
	t_filedes	crptrs;
	int			cm_num;

	cm_num = 0;

	while (cm_num < log->arg_c - 4)
	{
		if (cm_num == 0)
		{
			crptrs.fd_in = log->fd_in;
		}
	}
	

	while (log->cm_num < log->arg_c - 2) //check what is arg_c
	{
		if (log->cm_num == 0)
		{
			ft_parent(log, envp);
		}
		while (log->cm_num < log->arg_c - 3)
		{
			ft_parent()
		}
		if ()
	}
}
