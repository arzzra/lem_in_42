/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_totallen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:14:37 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 11:36:36 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	baselen(t_qualfrs *fmt)
{
	long long	i;

	i = 0;
	if (fmt->ld->realprec > 0 || fmt->flg->sharp)
	{
		i++;
		fmt->ld->sf_index++;
		i += fmt->ld->realprec;
		fmt->ld->sf_index += fmt->ld->realprec;
	}
	if (fmt->flg->plus != 0 || fmt->flg->space == 1)
		i++;
	return (i);
}

void		get_e_val(uint64_t *p_int, t_qualfrs *fmt)
{
	fmt->ld->e = 0;
	if (fmt->ld->iflg == 0 && fmt->ld->fflg != 0)
	{
		if (fmt->ld->carry == 1)
			fmt->ld->e = -fmt->ld->count_0;
		else
			fmt->ld->e = -fmt->ld->count_0 - 1;
	}
	else
	{
		fmt->ld->e = get_buflen(p_int) - 1;
	}
}

long long	get_totallen_e(uint64_t *p_int, t_qualfrs *fmt)
{
	long long	totallen;
	int			dt;
	long long	tmp;

	totallen = 4;
	fmt->ld->sf_index = 2;
	totallen += baselen(fmt);
	get_e_val(p_int, fmt);
	tmp = number_pow((size_t)fmt->ld->e);
	if (tmp <= 1)
		tmp = 2;
	totallen += tmp;
	fmt->ld->sf_index += tmp;
	(dt = fmt->width - totallen + 1) > 0 ? totallen += dt : 1;
	fmt->ld->delta = dt;
	fmt->ld->totallen = totallen;
	fmt->ld->sf_index = totallen - fmt->ld->sf_index - 1;
	return (totallen);
}

long long	get_totallen_f(uint64_t *p_int, t_qualfrs *fmt)
{
	long long	totallen;
	int			dt;

	fmt->ld->intlen = get_buflen(p_int);
	totallen = fmt->ld->intlen + 1 + fmt->ld->ovrld + fmt->ld->realprec;
	if (fmt->ld->realprec > 0 || fmt->flg->sharp)
	{
		totallen++;
	}
	if (fmt->flg->plus != 0 || fmt->flg->space == 1)
	{
		totallen++;
	}
	(dt = fmt->width - totallen + 1) > 0 ? totallen += dt : 1;
	fmt->ld->delta = dt;
	fmt->ld->totallen = totallen;
	return (totallen);
}

void		pow_of_num(uint64_t *buf_n, uint64_t exp, unsigned num)
{
	buf_n[0] = 1;
	buf_n[1] = 1;
	while (exp > 0)
	{
		mul_s(buf_n, num);
		exp--;
	}
}
