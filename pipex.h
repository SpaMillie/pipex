/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/26 14:59:22 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "Libft/include/libft.h"
//check which headers you need 
typedef	struct s_captains
{
	int		fd_in;
	int		fd_out;
	char	*file1;
	char	*file2;
	char	**paths; //if a command doesn't exist do perror and have NULL for it
	char	***execve_args;
	char	**cmmndswflgs; //probably can just use argv
	char	**cmnd_path;
	int		arg_c;
	int		cm_num;
	int		*pids;
}	t_captains;

typedef	struct s_filedes
{
	int fd_in;
	int	fd_out;
	int	fd_cls;
} t_filedes;

//main.c
int		allocate(t_captains *log);
int		parsing_commands(t_captains *log, int count);
int		check_if_valid(char **argv,  t_captains *log);
void	initialise(int argc, char **argv, char **envp, t_captains *log);
int		main(int argc, char **argv, char **envp);
//is_it_valid.c
int		if_valid_file(char *file1, char *file2, t_captains *log);
int		if_valid_command(char *command, t_captains *log, int com_num);
//error.c
int		invalid_argument(void);
void	free_everything(t_captains *log);
void	ft_perror(char *str, int fail);
//pipex.c
void	ft_child(char **envp, t_filedes *cripto, t_captains *log);
void	init_fds(t_captains *log, t_filedes *cripto, int i, int **fds, int old);
void	ft_parent(char **envp, t_captains *log, t_filedes *cripto);
void	ft_pipex(char **envp, t_captains *log);
//pipex_strjoin.c
char	*pipex_strjoin(char *s1, char *s2, int seq);
//pipex_split.c
int		pipex_split(char *s, char c, t_captains *log, int com_num);

#endif
