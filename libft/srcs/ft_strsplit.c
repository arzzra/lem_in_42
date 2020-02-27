/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:07:26 by cdemetra          #+#    #+#             */
/*   Updated: 2020/01/19 18:14:47 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_counterwords(char const *s, char c)
{
	size_t	i;
	size_t	x;
	int		q;

	i = 0;
	q = 0;
	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == c && (q <= 0 || q >= -1))
			q = 1;
		if (s[x] != c && (q >= 0 || q <= 1))
		{
			q = -1;
			i++;
		}
		x++;
	}
	return (i);
}

static	char		**ft_dellfree(char **tabl, size_t n)
{
	size_t	i;

	i = 0;
	while (i <= n)
	{
		free(tabl[i]);
		i++;
	}
	free(tabl);
	return (NULL);
}

static	void		ft_copystrfromtable(char **tabl, char const *str, char c)
{
	size_t	i;
	size_t	x;
	size_t	z;

	z = 0;
	i = 0;
	while (str[z] != '\0')
	{
		if (str[z] != c)
		{
			x = 0;
			while (str[z] != c && str[z] != '\0')
			{
				tabl[i][x] = str[z];
				x++;
				z++;
			}
			tabl[i][x] = '\0';
			i++;
		}
		else
			z++;
	}
}

static	char		**ft_malloctable(char const *str, char c, size_t i)
{
	char	**tabl;
	size_t	s;

	s = 0;
	if ((tabl = (char**)malloc((i + 1) * sizeof(char*))) == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str != c)
		{
			i = 0;
			while (*str != c && *str != '\0')
			{
				str++;
				i++;
			}
			if ((tabl[s] = (char*)malloc((i + 1) * sizeof(char))) == NULL)
				return (ft_dellfree(tabl, s));
			s++;
		}
		else
			str++;
	}
	tabl[s] = NULL;
	return (tabl);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tabl;
	size_t	i;
	char	x;

	if (!s)
		return (NULL);
	x = c;
	if (!(i = ft_counterwords(s, x)))
		return (NULL);
	tabl = ft_malloctable(s, x, i);
	if (tabl == NULL)
		return (NULL);
	ft_copystrfromtable(tabl, s, x);
	return (tabl);
}
