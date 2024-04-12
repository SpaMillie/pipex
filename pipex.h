/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/12 19:33:27 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "Libft/include/libft.h"

typedef	struct s_captains
{
	int		fd_in;
	int		fd_out;
	char	**paths;
	char	**cmnds;
	char	**flags;
	char	**cmmndswflgs;
	int		arg_c;
}	t_captains;


//main.c
int		if_valid_file(char *file1, char *file2, t_captains *log);
int		if_valid_command(char *command, t_captains *log, int com_num);
int		check_if_valid(char **argv, char *env, t_captains *log);
void	initialise(t_captains *log, char **envp, int argc);
int		main(int argc, char **argv, char **envp);
//pipex.c

//error.c
int		invalid_argument(void);
//pipex_strjoin.c
char	*pipex_strjoin(char const *s1, char const *s2, int seq);
//pipex_split.c
int		pipex_split(char const *s, char c, t_captains *log, int com_num);

#endif
