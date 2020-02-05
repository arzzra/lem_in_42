/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:13:52 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/24 17:19:41 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t	n;
	size_t	i;
	size_t	s;

	n = 0;
	s = 0;
	if (str2[0] == '\0')
		return ((char*)str1);
	while (str1[s] != '\0')
	{
		i = 0;
		if (str1[s] == str2[i])
		{
			n = s;
			while (str1[n] == str2[i] && str2[i] != '\0')
			{
				n++;
				i++;
			}
			if (str2[i] == '\0')
				return (&((char*)str1)[s]);
		}
		s++;
	}
	return (NULL);
}
