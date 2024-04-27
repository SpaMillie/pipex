//insert header

#include "pipex.h"

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
			i++;
		if (prev_i != i && words < 3)
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

static char	*ft_splitstr(const char *s, char c, int option)
{
	int		prev_i;
	int		i;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		prev_i = i;
		while (s[i] && s[i] != c)
			i++;
		if (option == 1 && prev_i != i)
			return (ft_substr(s, prev_i, i - prev_i));
		else if (prev_i != i)
		{
			while(s[i] && s[i] == c)
				i++;
			if (s[i])
				return (ft_substr(s, i, ft_strlen(s) - i));
		}
	}
	return (NULL);
}

void	pipex_split(char *s, char c, t_captains *log, int com_num)
{
	int		i;
	int		c_word;

	printf("entering pipex_split\n");
	c_word = count_word(s, c);
	if (c_word == 0)
	{
		perror_exit(s, 1, log, 3);
		return ;
	}
	printf("c-word = %d\n", c_word);
	i = 0;
	log->execve_args[com_num][0] = ft_splitstr(s, c, 1);
	printf("command is %s\n", log->execve_args[com_num][0]);
	if (log->execve_args[com_num][0] == NULL)
		perror_exit("pipex: malloc", -1, log, 1);
	if (c_word >= 2)
	{
		log->execve_args[com_num][1] = ft_splitstr(s, c, 2);
		if (log->execve_args[com_num][1] == NULL)
			perror_exit("pipex: malloc", -1, log, 1);
		printf("flag is %s\n", log->execve_args[com_num][1]);
	}
	else
		log->execve_args[com_num][1] = NULL;
	printf("allocated\n");
	log->execve_args[com_num][2] = NULL;
	printf("exiting pipex_split\n");
	// return (0);
}

// #include <stdio.h>
// int    main(void)
// {
// // s = ft_split();
// 	char *s = "      split       this for   me  !       ";

//         char **ns = ft_split(s, ' ');
// 		printf("%p\n", ns);

// 	// printf("Result 1:\n");
// 	// if (!ns)
// 	// 	printf("Test\n");
// 	// if (ns[0])
// 	// 	printf("Ok\n");
//     for (int i = 0; ns[i] != 0; i++) {
//         printf("[%d]: %s\n", i, ns[i]);
//         free(ns[i]);
//     }
// 	free (ns);
// 	// system("leaks a.out");
//     return (0);
// }
