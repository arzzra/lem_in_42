/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:28:29 by cdemetra          #+#    #+#             */
/*   Updated: 2019/06/17 20:15:37 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	y;

	if (s1 == NULL || s2 == NULL ||
	(str = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
	* sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (s1[i] != '\0')
	{
		str[y] = s1[i];
		i++;
		y++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[y] = s2[i];
		i++;
		y++;
	}
	str[y] = '\0';
	return (str);
}
