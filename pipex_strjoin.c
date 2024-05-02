/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:42:34 by mspasic           #+#    #+#             */
/*   Updated: 2024/05/02 17:53:13 by mspasic          ###   ########.fr       */
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

	////printf("entering p_strjoin\n");
	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
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
	////printf("the new string is %s\n", space_to_fill);
	if (seq == 1)
		free(s1);
	else if (seq == 2)
		free(s2);
	////printf("exiting p_strjoin\n");
	return (space_to_fill);
}
