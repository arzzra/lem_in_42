/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:29:01 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/30 12:20:00 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *append, size_t n)
{
	size_t			i;
	size_t			x;
	char			*d;
	const char		*a;

	x = n;
	d = dest;
	a = append;
	while (*d != '\0' && x-- != 0)
		d++;
	i = d - dest;
	x = n - i;
	if (x == 0)
		return (i + ft_strlen(append));
	while (*a != '\0')
	{
		if (x != 1)
		{
			*d++ = *a;
			x--;
		}
		a++;
	}
	*d = '\0';
	return (i + (a - append));
}
