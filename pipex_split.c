/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:21:50 by mspasic           #+#    #+#             */
/*   Updated: 2024/04/30 20:53:49 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	allocate(t_captains *log, int words, int com_num)
{
	int	i;
	// //printf("entering allocate\n");
	i = log->arg_c - 1;
	if (com_num == 0)
	{
		log->execve_args = (char ***)malloc((sizeof(char **) * i));
		if (!log->execve_args)
			perror_exit("pipex: malloc", -1, log, 1);
		log->execve_args[i - 1] = NULL;
	}
	log->execve_args[com_num] = (char **)malloc(sizeof(char *) * (words + 1));
	if (!log->execve_args[com_num])
		perror_exit("pipex: malloc", -1, log, 1);
	// //printf("exiting allocate\n");
}

static int	ft_skip(const char *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i + 1);
}

static int	count_word(const char *s, char c)
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
		while (s[i] && s[i] != c)
		{
			if (s[i] == '\'' || s[i] == '\"')
				i = ft_skip(s, s[i], i + 1);
			else
				i++;
		}
		if (prev_i != i)
			words++;
	}
	return (words);
}

char	**free_all(char **res);
// {
// 	int	i;

// 	i = 0;
// 	while (res[i])
// 		free(res[i++]);
// 	free(res);
// 	return (0);
// }

static void	ft_splitstr(char *s, t_captains *log, int com_num)
{
	int	prev_i;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == 32)
			i++;
		prev_i = i;
		while (s[i] && s[i] != 32)
		{
			if (s[i] == '\'' || s[i] == '\"')
				i = ft_skip(s, s[i], i + 1);
			else
				i++;
		}
		if (prev_i != i)
			log->execve_args[com_num][j++] = pipex_substr(s, \
				prev_i, i - prev_i, log);
	}
	return ;
}

void	pipex_split(char *s, char c, t_captains *log, int com_num)
{
	int		c_word;

	printf("entering pipex_split\n");
	c_word = count_word(s, c);
	if (c_word == 0)
	{
		invalid_argument(1, log, s, com_num);
		return ;
	}
	printf("c-word = %d\n", c_word);
	allocate(log, c_word, com_num);
	ft_splitstr(s, log, com_num);
	int i = 0;
	while (i < c_word)
		printf("command is %s\n", log->execve_args[com_num][i++]);
	printf("allocated\n");
	log->execve_args[com_num][c_word] = NULL;
	printf("exiting pipex_split\n");
}

// #include <stdio.h>
// int    main(void)
// {
// // s = ft_split();
// 	char *s = "      split       this for   me  !       ";

//         char **ns = ft_split(s, ' ');
// 		//printf("%p\n", ns);

// 	// //printf("Result 1:\n");
// 	// if (!ns)
// 	// 	//printf("Test\n");
// 	// if (ns[0])
// 	// 	//printf("Ok\n");
//     for (int i = 0; ns[i] != 0; i++) {
//         //printf("[%d]: %s\n", i, ns[i]);
//         free(ns[i]);
//     }
// 	free (ns);
// 	// system("leaks a.out");
//     return (0);
// }
