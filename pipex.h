/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:31 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/04 20:59:07 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "Libft/include/libft.h"

typedef	struct s_params
{
	char	*command1;
	char	*flags1;
	char	*command2;
	char	*flags2;
	int		fd_in;
	int		fd_out;
}	t_params;


//main.c
int	check_if_valid(char **argv, t_params *params);
int	main(int argc, char **argv);
//pipex.c

//error.c
int	invalid_argument(void);

#endif
