/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:23:08 by cdemetra          #+#    #+#             */
/*   Updated: 2019/06/28 17:22:55 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *str)
{
	size_t	q;

	q = 0;
	if (str == NULL)
		return (NULL);
	while (str[q] != '\0')
	{
		str[q] = ft_tolower((int)str[q]);
		q++;
	}
	return (str);
}
