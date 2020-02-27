/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 21:06:21 by cdemetra          #+#    #+#             */
/*   Updated: 2019/05/14 16:08:48 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_reverse(char *str)
{
	size_t	a;
	size_t	b;
	char	c;

	if (str == NULL)
		return (NULL);
	a = ft_strlen(str);
	a = a - 1;
	b = 0;
	while (b < ((a + 1) / 2))
	{
		c = str[b];
		str[b] = str[a - b];
		str[a - b] = c;
		b++;
	}
	return (str);
}
