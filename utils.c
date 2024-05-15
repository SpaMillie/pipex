/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:07:57 by mspasic           #+#    #+#             */
/*   Updated: 2024/05/15 16:31:15 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_transform(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i = ft_skip(s, c, i);
		else if (s[i] == 32)
			s[i++] = 7;
		else
			i++;
	}
}

int	ft_skip(char *s, char c, int i)
{
	s[i++] = 7;
	while (s[i] && s[i] != c)
		i++;
	s[i] = 7;
	return (i);
}

int	check_for_c(char *s, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			check++;
		i++;
	}
	if (check % 2 == 0)
		return (2);
	return (0);
}

void	set_errno(t_captains *log, int com_num)
{
	if ((log->fd_in == -1 && com_num == 0) || \
		(log->fd_out == -1 && com_num == log->arg_c - 3))
		log->err_no = -1;
	else
		log->err_no = -2;
}
