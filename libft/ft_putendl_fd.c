/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 22:33:14 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/25 14:23:09 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	q;

	if (s == NULL)
		return ;
	q = 0;
	while (s[q] != '\0')
	{
		ft_putchar_fd(s[q], fd);
		q++;
	}
	ft_putchar_fd('\n', fd);
}
