/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:06:25 by cdemetra          #+#    #+#             */
/*   Updated: 2019/05/14 17:40:23 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	if (size + 1 > size)
	{
		if ((str = (char*)malloc((size + 1) * sizeof(char))) == NULL)
			return (NULL);
		ft_bzero(str, (size + 1));
	}
	return (str);
}
