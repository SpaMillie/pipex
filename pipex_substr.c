/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:11:30 by mspasic           #+#    #+#             */
/*   Updated: 2024/05/02 17:53:13 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*pipex_substr(char *s, unsigned int strt, size_t len, \
	t_captains *log)
{
	char	*sub_s;
	char	c;

	//printf("len is %zu\n", len);
	if (s[strt] == '\'' || s[strt] == '\"')
	{
		c = s[strt];
		if (s[len] == c)
		{
			strt += 1;
			
			//printf("I was here\n");
		}
	}
	sub_s = (char *)malloc(len + 1);
	if (sub_s == NULL)
		perror_exit("pipex: malloc", -1, log, 1);
	//printf("total length is %lu\n", len + 1);
	//printf("c is %c\n", s[strt]);
	ft_strlcpy(sub_s, s + strt, len + 1);
	return (sub_s);
}
