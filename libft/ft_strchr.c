/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:42:55 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/22 01:47:13 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] == (char)chr)
			return (&((char*)str)[n]);
		n++;
	}
	if (str[n] == (char)chr)
		return (&((char*)str)[n]);
	return (NULL);
}
