//insert header

#include "pipex.h"

// #include <stdio.h>
// #include <stdlib.h>

// void	*ft_memset(void *array, int c, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*ptr;

// 	i = 0;
// 	ptr = array;
// 	while (i < n)
// 	{
// 		ptr[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (array);
// }
// void	ft_bzero(void *s, size_t n)
// {
// 	ft_memset(s, 0, n);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*space;
// 	size_t	bytes;

// 	bytes = size * count;
// 	if (count == 0 || size == 0)
// 		return (ft_calloc(1, 1));
// 	if (bytes / size != count)
// 		return (0);
// 	space = malloc(count * size);
// 	if (space != NULL)
// 		ft_bzero(space, count * size);
// 	return (space);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
// {
// 	size_t	srcsize;
// 	size_t	i;

// 	i = 0;
// 	srcsize = ft_strlen(src);
// 	if (dstsize > 0)
// 	{
// 		while (i + 1 < dstsize && i < srcsize)
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (srcsize);
// }
// char	*ft_strdup(const char *s1)
// {
// 	char	*s1_cpy;
// 	int		i;

// 	i = 0;
// 	while (s1[i] != '\0')
// 		i++;
// 	s1_cpy = (char *)malloc(i + 1);
// 	if (s1_cpy == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		s1_cpy[i] = (char)s1[i];
// 		i++;
// 	}
// 	s1_cpy[i] = '\0';
// 	return (s1_cpy);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*sub_s;
// 	size_t			str_len;

// 	if (s == 0)
// 		return (0);
// 	str_len = ft_strlen(s);
// 	if (str_len < start)
// 		return (ft_strdup(""));
// 	if (len > str_len - start)
// 		len = str_len - start;
// 	sub_s = (char *)malloc(len + 1);
// 	if (sub_s == NULL)
// 		return (NULL);
// 	ft_strlcpy(sub_s, s + start, len + 1);
// 	return (sub_s);
// }
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
			return(ft_substr(s, prev_i, ft_strlen(s) - prev_i));
	}
	return (NULL);
}

int	pipex_split(char *s, char c, t_captains *log, int com_num)
{
	int		i;
	int		c_word;

	if (!s)
		return (-1); 
	c_word = count_word(s, c);
	printf("words = %d\n", c_word);
	i = 0;
	log->execve_args[0][com_num] = ft_splitstr(s, c, 1);
	printf("cmm1 is %s\n", log->execve_args[0][com_num]);
	if (log->execve_args[0][com_num] == NULL)
	{
		free_all(log->execve_args[0]);
		free_all(log->execve_args[1]);
		return (-1);
	}
	if (c_word >= 2)
	{
		log->execve_args[1][com_num] = ft_splitstr(s, c, 2);
		if (log->execve_args[1][com_num] == NULL)
		{
			free_all(log->execve_args[0]);
			free_all(log->execve_args[1]);
			return (-1);
		}
	}
	else
		log->execve_args[1][com_num] = NULL;
	return (0);
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
