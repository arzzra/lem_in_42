/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:04:17 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/22 01:47:09 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *append)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (append[n] != '\0')
	{
		dest[i] = append[n];
		n++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
