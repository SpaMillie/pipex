/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:11:30 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/28 19:42:37 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// char	*ft_strdup(const char *s1);
char	*pipex_substr(char const *s, unsigned int strt, size_t len, \
	t_captains *log)
{
	char			*sub_s;
	size_t			str_len;

	sub_s = (char *)malloc(len + 1);
	if (sub_s == NULL)
		perror_exit("pipex: malloc", -1, log, 1);
	ft_strlcpy(sub_s, s + strt, len + 1);
	return (sub_s);
}
