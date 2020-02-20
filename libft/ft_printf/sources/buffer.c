/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:22:28 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 12:23:08 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	foo(char *s_full, unsigned len, unsigned delta)
{
	unsigned	i;

	if (delta > 0 && len > 0)
	{
		i = 0;
		while (i < delta)
		{
			s_full[len + i] = '0';
			i++;
		}
	}
}

void		buf_to_str(uint64_t *buf, char *s_full)
{
	char		*s_base;
	unsigned	buflen;
	unsigned	i;
	unsigned	j;
	unsigned	delta;

	buflen = buf[0];
	j = 0;
	i = 0;
	delta = 0;
	while (j < buflen)
	{
		s_base = ft_itoa_base_ll(buf[buflen - j], 10);
		j > 0 ? delta = (BASELEN - ft_strlen(s_base)) : 1;
		foo(s_full, i, delta);
		ft_strcpy(&(s_full[i + delta]), s_base);
		i += ft_strlen(s_base) + delta;
		j += 1;
	}
}
