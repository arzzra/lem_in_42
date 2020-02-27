/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:25:11 by cdemetra          #+#    #+#             */
/*   Updated: 2019/06/28 17:59:35 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;
	size_t	i;

	s = NULL;
	if (size)
	{
		i = 0;
		if ((s = malloc(size)) == NULL)
			return (NULL);
		ft_bzero(s, size);
	}
	return (s);
}
