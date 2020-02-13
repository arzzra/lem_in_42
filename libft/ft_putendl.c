/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 22:03:29 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/25 14:23:09 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	size_t	q;

	if (s == NULL)
		return ;
	q = 0;
	while (s[q] != '\0')
	{
		ft_putchar(s[q]);
		q++;
	}
	ft_putchar('\n');
}
