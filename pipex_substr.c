/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:11:30 by mspasic           #+#    #+#             */
/*   Updated: 2024/05/13 21:18:03 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*pipex_substr(char *s, unsigned int strt, size_t len, \
	t_captains *log)
{
	char	*sub_s;
	char	c;

	if (s[strt] == '\'' || s[strt] == '\"')
	{
		c = s[strt];
		if (s[len] == c)
			strt += 1;
	}
	sub_s = (char *)malloc(len + 1);
	if (sub_s == NULL)
		perror_exit("pipex: malloc", -1, log, 1);
	ft_strlcpy(sub_s, s + strt, len + 1);
	return (sub_s);
}
