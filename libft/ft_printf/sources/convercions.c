/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convercions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:30:19 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/23 18:51:55 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_10_to_8(unsigned long long x, t_qualfrs *ql)
{
	char				*num8;
	int					i;
	unsigned long long	g;

	g = x;
	i = 1;
	while (g /= 8)
		i++;
	i = (x == 0 && ql->flg->sharp) ? 0 : i;
	ql->countnum = i;
	if (!(num8 = ft_strnew(i)))
		return (NULL);
	while (--i >= 0)
	{
		num8[i] = x % 8 + '0';
		x /= 8;
	}
	return (num8);
}

char	*ft_10_to_16(unsigned long long x, t_qualfrs *ql)
{
	char				*num8;
	int					i;
	unsigned long long	g;
	char				up;

	g = x;
	i = 1;
	if (ql->flg->sharp)
		ql->flg->sharp++;
	while (g /= 16)
		i++;
	ql->countnum = i;
	if (!(num8 = ft_strnew(i)))
		return (NULL);
	up = (ql->typs == TYPES[8]) ? 'A' : 'a';
	while (--i >= 0)
	{
		num8[i] = (x % 16 < 10) ? x % 16 + '0' : x % 16 - 10 + up;
		x /= 16;
	}
	return (num8);
}

void	ft_putcharutf8(char c)
{
	char			wr;
	unsigned char	c2;

	c2 = (unsigned char)c;
	if (c2 < 0)
		return ;
	if (c2 > 0x7F)
	{
		wr = (c2 >> 6) | 0xC0;
		write(1, &wr, 1);
		wr = c2 & 0xbf;
		write(1, &wr, 1);
	}
	else
		write(1, &c2, 1);
}
