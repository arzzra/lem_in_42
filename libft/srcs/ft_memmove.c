/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:40:46 by cdemetra          #+#    #+#             */
/*   Updated: 2019/06/17 19:50:05 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == source)
		return (dest);
	if (dest > source)
	{
		while (i < n)
		{
			((char*)dest)[n - i - 1] = ((char*)source)[n - i - 1];
			i++;
		}
	}
	else
		while (i < n)
		{
			((char*)dest)[i] = ((char*)source)[i];
			i++;
		}
	return (dest);
}
