/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:42:34 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/16 17:01:33 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_stradd(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

char	*pipex_strjoin(char *s1, char *s2, int seq)
{
	char	*space_to_fill;
	size_t	n;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	i = ft_strlen((char *)s1);
	j = 0;
	n = i + ft_strlen((char *)s2) + 1;
	space_to_fill = (char *)malloc(n);
	if (space_to_fill == NULL)
		return (NULL);
	space_to_fill = ft_stradd((char *)s1, space_to_fill);
	while (s2[j] != '\0')
	{
		space_to_fill[i] = s2[j];
		i++;
		j++;
	}
	space_to_fill[i] = '\0';
	if (seq != 0)
		free(s1);
	return (space_to_fill);
}
