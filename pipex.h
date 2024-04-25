/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/25 18:55:27 by mspasic          ###   ########.fr       */
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
	int		**fds;
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
//pipex_strjoin.c
char	*pipex_strjoin(char *s1, char *s2, int seq);
//pipex_split.c
int		pipex_split(char *s, char c, t_captains *log, int com_num);

#endif
