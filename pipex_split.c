/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:21:50 by mspasic           #+#    #+#             */
/*   Updated: 2024/05/14 13:36:55 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	allocate(t_captains *log, int words, int com_num)
{
	int	i;

	i = log->arg_c - 1;
	if (com_num == 0)
	{
		log->execve_args = (char ***)malloc((sizeof(char **) * i));
		if (!log->execve_args)
			perror_exit("pipex: malloc", -1, log, 1);
		log->execve_args[i - 1] = NULL;
	}
	if (words == 0)
		words = 1;
	log->execve_args[com_num] = (char **)malloc(sizeof(char *) * (words + 1));
	if (!log->execve_args[com_num])
		perror_exit("pipex: malloc", -1, log, 1);
}

static int	resolve(char *s, char c, int i, t_captains *log)
{
	while (s[i] && s[i] != c)
	{
		if ((s[i] == '\'' || s[i] == '\"') && s[i - 1] == 32)
		{
			if (check_for_c(s, s[i]) == 2)
			{
				ft_transform(s, s[i]);
				log->c = 7;
				return (-2);
			}
		}
		else
			i++;
	}
	return (i);
}

int	w_count(char *s, char c, t_captains *log)
{
	int	words;
	int	i;
	int	prev_i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		prev_i = i;
		if (s[i] && s[i] != c)
		{
			i = resolve(s, c, i, log);
			if (i == -2)
				return (w_count(s, log->c, log));
		}
		if (prev_i != i)
			words++;
	}
	return (words);
}

char	**free_all(char **res);

static void	ft_splitstr(char *s, t_captains *log, int com_num)
{
	int	prev_i;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == log->c)
			i++;
		prev_i = i;
		while (s[i] && s[i] != log->c)
			i++;
		if (prev_i != i)
			log->execve_args[com_num][j++] = pipex_substr(s, \
				prev_i, i - prev_i, log);
	}
}

void	pipex_split(char *s, t_captains *log, int com_num)
{
	int		c_word;
	int		i;

	log->c = 32;
	i = 0;
	c_word = w_count(s, log->c, log);
	allocate(log, c_word, com_num);
	if (c_word == 0)
	{
		log->execve_args[com_num][0] = ft_strdup(s);
		//protect
		log->execve_args[com_num][1] = NULL;
		return ;
	}
	ft_splitstr(s, log, com_num);
	log->execve_args[com_num][c_word] = NULL;
}
