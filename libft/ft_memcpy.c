/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:00:17 by cdemetra          #+#    #+#             */
/*   Updated: 2019/06/17 20:27:47 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *des, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (des == src)
		return (des);
	while (i < n)
	{
		((char*)des)[i] = ((char*)src)[i];
		i++;
	}
	return (des);
}
