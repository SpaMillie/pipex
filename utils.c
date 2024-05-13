/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:07:57 by mspasic           #+#    #+#             */
/*   Updated: 2024/05/13 12:21:22 by mspasic          ###   ########.fr       */
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
	return (check);
}
