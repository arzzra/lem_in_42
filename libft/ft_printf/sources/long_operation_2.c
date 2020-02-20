/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_operation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 11:46:02 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 12:20:02 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uint64_t	*mul_s(uint64_t *buf, unsigned dig)
{
	uint64_t	c;
	unsigned	i;

	c = 0;
	i = 1;
	while (i <= buf[0])
	{
		c = buf[i] * dig + c;
		buf[i] = c % BASE;
		c = c / BASE;
		if (i == buf[0] && c != 0)
		{
			buf[0]++;
			buf[buf[0]] = c;
			break ;
		}
		i++;
	}
	return (buf);
}

void		div_mod_s(uint64_t *buf_a, uint64_t b, uint64_t *res, uint64_t *rem)
{
	uint64_t	r;
	uint64_t	tmp;
	long long	i;

	res[0] = buf_a[0];
	r = 0;
	i = buf_a[0];
	while (i > 0)
	{
		tmp = r * BASE + buf_a[i];
		res[i] = tmp / b;
		r = tmp - res[i] * b;
		i--;
	}
	*rem = r;
	i = buf_a[0];
	while ((i > 0) && (res[i] == 0))
		i--;
	res[0] = i;
}

uint64_t	*div_s(uint64_t *buf, unsigned dig, uint64_t *res)
{
	uint64_t		c;
	unsigned long	i;

	c = 0;
	i = buf[0];
	res[0] = buf[0];
	while (i >= 1)
	{
		c = c * BASE + buf[i];
		res[i] = c / dig;
		c = c % dig;
		i--;
	}
	i = 1;
	while (i <= buf[0])
	{
		buf[i] = res[i];
		i++;
	}
	return (res);
}

uint64_t	*mul_l(uint64_t *buf1, uint64_t *buf2, uint64_t *res)
{
	unsigned long long	c;
	unsigned			i;
	unsigned			j;
	unsigned			maxlen;

	res[0] = buf1[0] + buf2[0];
	maxlen = res[0];
	i = 1;
	while (i < maxlen)
	{
		c = 0;
		j = 1;
		while (j < maxlen)
		{
			c = c + buf1[j] * buf2[i] + res[j];
			res[j] = c % BASE;
			c = c / BASE;
			j++;
		}
		i++;
	}
	return (res);
}

void		pow_of_two(uint64_t *buf_2n, unsigned long exp)
{
	buf_2n[0] = 1;
	buf_2n[1] = 1;
	while (exp > 0)
	{
		mul_s(buf_2n, 2);
		exp--;
	}
}
