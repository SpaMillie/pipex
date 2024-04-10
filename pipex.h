/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/10 16:40:33 by mspasic          ###   ########.fr       */
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
	char	*command1;
	char	*flags1;
	char	*command2;
	char	*flags2;
	int		fd_in;
	int		fd_out;
	char	**paths;
}	t_captains;


//main.c
int	check_if_valid(char **argv, t_captains *log);
int	main(int argc, char **argv);
//pipex.c

//error.c
int	invalid_argument(void);

#endif
