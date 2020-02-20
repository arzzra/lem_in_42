/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:25 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 12:27:54 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*lead_zeros(long long exp, char *part, char flag)
{
	if (flag == 'f')
	{
		while (exp >= 0)
		{
			*part = '0';
			part++;
			exp--;
		}
		return (&(*part));
	}
	if (flag == 'i')
	{
		while (exp >= 0)
		{
			*part = '0';
			part++;
			exp--;
		}
		*part = '\0';
	}
	return (part);
}

static int	begin_action(uint64_t *buf, char *s_int)
{
	buf[0] = 1;
	buf[1] = 0;
	if (*s_int == '\0')
		return (-1);
	return (0);
}

uint64_t	*convert_integer(uint64_t *buf, char *s_int)
{
	unsigned	maxpow;
	unsigned	i;
	uint64_t	buf_2n[2000];

	if (begin_action(buf, s_int) == -1)
		return (buf);
	i = 0;
	maxpow = ft_strlen(s_int) - 1;
	while (s_int[maxpow - i] == '0')
	{
		if (maxpow - i == 0)
			return (buf);
		i++;
	}
	pow_of_two(buf_2n, i);
	while (i <= maxpow)
	{
		if (i == 0)
			buf[1] = 0;
		if (s_int[maxpow - i] == '1')
			add(buf, buf_2n);
		mul_s(buf_2n, 2);
		i++;
	}
	return (buf);
}
