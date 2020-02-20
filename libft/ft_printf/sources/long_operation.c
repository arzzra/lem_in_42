/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:06 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 11:48:03 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		zero_ceil(uint64_t *buf, unsigned maxlen)
{
	unsigned i;

	i = (buf[0] + 1);
	while (i <= maxlen)
	{
		buf[i] = 0;
		i++;
	}
}

static void	get_maxlen(unsigned *maxlen, uint64_t *buf1, uint64_t *buf2)
{
	if (buf1[0] > buf2[0])
	{
		*maxlen = buf1[0];
		zero_ceil(buf2, *maxlen);
	}
	else if (buf1[0] < buf2[0])
	{
		*maxlen = buf2[0];
		zero_ceil(buf1, *maxlen);
		buf1[0] = buf2[0];
	}
	else
		*maxlen = buf1[0];
}

uint64_t	*add(uint64_t *buf1, uint64_t *buf2)
{
	uint64_t	c;
	unsigned	i;
	unsigned	maxlen;

	get_maxlen(&maxlen, buf1, buf2);
	c = 0;
	i = 1;
	while (i <= maxlen)
	{
		c = buf1[i] + buf2[i] + c;
		buf1[i] = c % BASE;
		c = c / BASE;
		if (i == maxlen && c != 0)
		{
			buf1[0]++;
			buf1[buf1[0]] = c;
			break ;
		}
		i++;
	}
	return (buf1);
}

uint64_t	*add_s(uint64_t *buf, uint64_t dig)
{
	uint64_t	c;
	unsigned	i;
	unsigned	maxlen;

	i = 1;
	maxlen = buf[0];
	c = buf[i] + dig;
	while (i <= maxlen)
	{
		buf[i] = c % BASE;
		c = c / BASE;
		if (i == maxlen && c != 0)
		{
			buf[0]++;
			buf[buf[0]] = c;
			break ;
		}
		i++;
	}
	return (buf);
}

void		print_bits(size_t size, void *ptr, char space)
{
	unsigned char	*b;
	unsigned char	byte;
	int				i;
	int				j;

	b = (unsigned char*)ptr;
	i = size - 1;
	j = 7;
	while (i >= 0)
	{
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			ft_putchar(byte + '0');
			j--;
		}
		if (space == 1)
			ft_putchar(' ');
		j = 7;
		i--;
	}
	ft_putchar('\n');
}
