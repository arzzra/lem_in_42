/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:23:52 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/23 20:14:31 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *append, size_t n)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (dest[i] != '\0')
		i++;
	while (append[x] != '\0' && x < n)
	{
		dest[i] = append[x];
		i++;
		x++;
	}
	dest[i] = '\0';
	return (dest);
}
