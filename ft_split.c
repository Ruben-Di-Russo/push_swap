/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:37:54 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/03 17:28:33 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	charsep(char c, char del)
{
	int	i;

	i = 0;
	if (c == del || c == '\0')
		return (1);
	return (0);
}

int	count_chars(char *str, char del)
{
	int	x;
	int	chars;

	x = 0;
	chars = 0;
	while (str[x] != '\0')
	{
		if (charsep(str[x + 1], del) == 1 && charsep(str[x], del) == 0)
			chars++;
		x++;
	}
	return (chars);
}

void	write_oneword(char *dst, char *src, char del)
{
	int	i;

	i = 0;
	while (charsep(src[i], del) == 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	*strsplitwrite(char **str2, char *str, char del)
{
	int	i;
	int	j;
	int	sep;

	sep = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (charsep(str[i], del) == 1)
				i++;
		else
		{
			j = 0;
			while (charsep(str[i + j], del) == 0)
				j++;
			str2[sep] = (char *)malloc(sizeof(char) * (j + 1));
			if (!str2[sep])
				return (NULL);
			write_oneword(str2[sep], str + i, del);
			i = i + j;
			sep++;
		}
	}
	return ((void *)1);
}

char	**ft_split(char const *s, char c)
{
	static char	**strarray;
	char		*str;
	int			chars;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	chars = count_chars(str, c);
	if (chars == 0)
		return (0);
	strarray = (char **)malloc(sizeof(char *) * (chars + 1));
	if (!strarray)
		return (NULL);
	strarray[chars] = 0;
	strsplitwrite(strarray, str, c);
	return (strarray);
}
