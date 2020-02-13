/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:55:04 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/30 10:55:28 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	size_t	n;
	char	*s;
	size_t	x;

	n = 0;
	s = NULL;
	x = ft_strlen(str);
	while (n <= x)
	{
		if (str[n] == (char)chr)
			s = &((char*)str)[n];
		n++;
	}
	return (s);
}
