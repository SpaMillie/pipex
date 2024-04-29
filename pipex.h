/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/29 14:32:01 by mspasic          ###   ########.fr       */
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
typedef struct s_captains
{
	int		fd_in;
	int		fd_out;
	int		arg_c;
	int		cm_num;
	int		err_no;
	int		*pids;
	char	*file1;
	char	*file2;
	char	**paths; //if a command doesn't exist do perror and have NULL for it
	char	**cmmndswflgs;
	char	**cmnd_path;
	char	***pre_execve;
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
void	initialise(int argc, char **argv, char **envp, t_captains *log);
int		main(int argc, char **argv, char **envp);
//error.c
int		invalid_argument(int option, t_captains *log, char *str, int com_num);
void	free_to_cleanup(t_captains *log);
void	free_triple(t_captains *log);
// void	ft_perror(char *str, int fail);
void	perror_exit(char *str, int to_free, t_captains *log, int option);
//open_and_parse.c
void	pathfinder(t_captains *log, int com_num, char *command);
void	opening_files(char *file1, char *file2, t_captains *log);
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
void	pipex_split(char *s, char c, t_captains *log, int com_num);
//pipex_substr.c
char	*pipex_substr(char const *s, unsigned int strt, size_t len,
			t_captains *log);

#endif
