/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:55 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 11:59:42 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*solve_f(uint64_t *p_i, uint64_t *p_f, char **res_s, t_qualfrs *fmt)
{
	char			*si;
	char			*pnt;
	long long		totallen;

	if (fmt->typs == 'f' || fmt->typs == 'F')
		totallen = get_totallen_f(p_i, fmt);
	else
		totallen = fmt->ld->totallen;
	*res_s = (char*)malloc((totallen + 1) * sizeof(char));
	(*res_s)[totallen - 1] = '\0';
	pnt = save_fp(*res_s, p_f, p_i, fmt);
	si = save_int_part(pnt, p_i, fmt);
	if (fmt->ld->realprec > 0 || fmt->flg->sharp)
	{
		si[ft_strlen(si)] = '.';
	}
	else if (fmt->flg->minus && (fmt->ld->delta) > 0)
	{
		si[ft_strlen(si)] = ' ';
	}
	write(1, pnt, fmt->ld->totallen - 1);
	return (NULL);
}

void		put_first_simbol(char **p, t_qualfrs *fmt)
{
	if (fmt->flg->plus > 0)
		**p = '+';
	else if (fmt->flg->plus < 0)
		**p = '-';
	else if (fmt->flg->space)
	{
		**p = ' ';
	}
	else
		return ;
	(*p)++;
}

char		*zero_nminus(char *p, t_qualfrs *fmt)
{
	if (fmt->flg->plus != 0 || fmt->flg->space == 1)
		put_first_simbol(&p, fmt);
	if (fmt->ld->delta > 0 && fmt->flg->zero)
	{
		ft_memset(p, '0', fmt->ld->delta);
		p += fmt->ld->delta;
	}
	return (p);
}

char		*save_int_part(char *res_s, uint64_t *buf, t_qualfrs *fmt)
{
	char	*p;

	p = res_s;
	if (fmt->flg->zero && !fmt->flg->minus)
		p = zero_nminus(p, fmt);
	else if (!fmt->flg->zero && !fmt->flg->minus)
	{
		if (fmt->ld->delta > 0)
		{
			ft_memset(p, ' ', fmt->ld->delta);
			p += fmt->ld->delta;
		}
		put_first_simbol(&(p), fmt);
	}
	else if (fmt->flg->plus != 0 || fmt->flg->space == 1)
		put_first_simbol(&p, fmt);
	buf_to_str(buf, p);
	return (res_s);
}

long long	get_buflen(uint64_t *buf)
{
	unsigned long	last_el;
	long long		buflen;

	buflen = 0;
	last_el = buf[buf[0]];
	buflen = (buf[0] - 1) * BASELEN;
	if (buf[0] == 1 && buf[1] == 0)
		return (1);
	while (last_el)
	{
		last_el /= 10;
		(buflen)++;
	}
	return (buflen);
}
