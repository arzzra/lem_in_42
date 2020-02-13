/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 20:51:08 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/30 14:18:38 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_numbcounter(unsigned int n)
{
	int				i;
	unsigned int	s;

	i = 0;
	if (n == 0)
		return (1);
	s = n;
	while (s > 0)
	{
		s = s / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				q;
	int				a;
	unsigned int	s;

	a = (n >= 0) ? 0 : 1;
	s = (n >= 0) ? n : n * -1;
	q = ft_numbcounter(s);
	q = (n >= 0) ? q : (q + 1);
	if (!(str = ft_strnew(q)))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (--q >= a)
	{
		str[q] = (s % 10) + 48;
		s = s / 10;
	}
	return (str);
}
