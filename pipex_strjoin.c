/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:42:34 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/17 17:30:56 by mspasic          ###   ########.fr       */
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
size_t	ft_strlen(const char *str);
char	*pipex_strjoin(char *s1, char *s2, int seq)
{
	char	*space_to_fill;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	printf("%s and %s\n", s1, s2);
	printf("%zu and %zu\n", i, ft_strlen(s2));
	space_to_fill = (char *)malloc(ft_strlen(s2) + i + 1);
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
	if (seq == 1)
		free(s1);
	else if (seq == 2)
		free(s2);
	return (space_to_fill);
}
