/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_e_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:08:28 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 12:28:29 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*get_end_index(char *s_full, t_qualfrs *fmt)
{
	char	*p;

	p = s_full;
	if (fmt->ld->iflg == 0 && fmt->ld->fflg == 0)
	{
		ft_memset(p, '0', fmt->ld->realprec);
		return (p += fmt->ld->realprec);
	}
	else if (fmt->ld->realprec > 0)
		return (&s_full[fmt->ld->realprec + 1]);
	else
		return (&s_full[fmt->ld->realprec]);
}

uint64_t	*cut_buf(uint64_t *buf, long long len)
{
	long long	n;
	long long	lf;

	if (buf[0] == 1)
		return (buf);
	n = 0;
	lf = number_pow((long long)buf[buf[0]]);
	len -= lf;
	if (len > 0)
	{
		n = (len) / (BASELEN);
		if ((len) % BASELEN > 0)
			n++;
	}
	n++;
	buf[buf[0] - n] = n;
	return (&(buf[buf[0] - n]));
}

void		fill_e_end(char *s_full, t_qualfrs *fmt)
{
	char		*p;
	long long	i;

	p = (get_end_index(s_full, fmt));
	p = put_e_sig(p, fmt);
	i = number_pow((long long)fmt->ld->e);
	if (i < 2)
	{
		i == 0 ? i++ : 1;
		*(p) = '0';
		p++;
	}
	p += i;
	*(p) = '\0';
	if (fmt->ld->e == 0)
		*(--p) = 48;
	while (fmt->ld->e)
	{
		*(--p) = (fmt->ld->e % 10) + 48;
		fmt->ld->e /= 10;
	}
}
