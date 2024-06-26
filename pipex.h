/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/05/13 21:36:42 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h> 
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include "Libft/include/libft.h"

typedef struct s_captains
{
	int		fd_in;
	int		fd_out;
	int		arg_c;
	int		cm_num;
	int		err_no;
	int		*pids;
	char	c;
	char	*cmnd_path;
	char	**paths;
	char	**cmmndswflgs;
	char	***execve_args;
}	t_captains;

typedef struct s_filedes
{
	int	fd_in;
	int	fd_out;
	int	fd_cls;
	int	i;
}	t_filedes;

//main.c
void	init_cmndsflgs(t_captains *log, char **argv);
void	init_env(t_captains *log, char **envp);
void	initialise(int argc, char **argv, char **envp, t_captains *log);
int		main(int argc, char **argv, char **envp);
//error.c
int		file_permission(t_captains *log, char *file);
int		invalid_argument(int option, t_captains *log, char *str, int com_num);
void	free_to_cleanup(t_captains *log);
void	free_triple(t_captains *log);
void	perror_exit(char *str, int to_free, t_captains *log, int option);
//open_and_parse.c
void	pathfinder(t_captains *log, int com_num, char *command);
int		opening_files(char *file, t_captains *log, int option);
void	open_n_parse(char **argv, t_captains *log);
//pipex.c
void	ft_child(char **envp, t_filedes *cripto, t_captains *log);
int		init_fds(t_captains *log, t_filedes *cripto, int *fds, int old);
void	forking(char **evnp, t_captains *log, t_filedes *cripto);
void	ft_parent(char **envp, t_captains *log, t_filedes *cripto);
int		ft_pipex(char **envp, t_captains *log);
//pipex_strjoin.c
char	*pipex_strjoin(char *s1, char *s2, int seq);
//pipex_split.c
int		w_count(char *s, char c, t_captains *log);
void	pipex_split(char *s, t_captains *log, int com_num);
//pipex_substr.c
char	*pipex_substr(char *s, unsigned int strt, size_t len,
			t_captains *log);
//utils.c
void	ft_transform(char *s, char c);
int		ft_skip(char *s, char c, int i);
int		check_for_c(char *s, char c);
void	set_errno(t_captains *log, int com_num);

#endif
