/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:19:29 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/24 17:39:20 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	d;
	size_t	i;
	size_t	s;

	d = 0;
	s = 0;
	if (str2[0] == '\0')
		return ((char*)str1);
	while (str1[s] != '\0')
	{
		i = 0;
		if (str1[s] == str2[i])
		{
			d = s;
			while (str1[d] == str2[i] && str2[i] != '\0')
			{
				d++;
				i++;
			}
			if (str2[i] == '\0' && d <= n)
				return (&((char*)str1)[s]);
		}
		s++;
	}
	return (NULL);
}
