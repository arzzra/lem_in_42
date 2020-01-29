/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:10:15 by cdemetra          #+#    #+#             */
/*   Updated: 2019/06/17 20:22:53 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	q;
	int		e;

	q = 0;
	e = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
	*str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		e *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		q = q * 10 + (*str - '0');
		if (q < 0 && e == -1)
			return (0);
		else if (q < 0 && e == 1)
			return (-1);
		str++;
	}
	return (q * e);
}
