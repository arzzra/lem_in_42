/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 23:25:59 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/30 11:38:55 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	q;

	if (n == 0)
		return (0);
	q = 0;
	while ((s1[q] != '\0' || s2[q] != '\0') && q < n)
	{
		if (s1[q] != s2[q])
			return ((unsigned char)s1[q] - (unsigned char)s2[q]);
		q++;
	}
	return (0);
}
