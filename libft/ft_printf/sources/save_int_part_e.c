/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_int_part_e.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:42 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/28 18:57:54 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*save_int_part_e(char *res_str, t_qualfrs *fmt)
{
	char	*p;

	p = res_str;
	p += fill_left_part(res_str, fmt);
	if (fmt->ld->iflg == 0 && fmt->ld->fflg == 0)
	{
		*p = '0';
	}
	else
	{
		if (fmt->ld->tmp == '9')
			fmt->ld->tmp = '1';
		*p = fmt->ld->tmp;
	}
	if (fmt->ld->realprec > 0 || fmt->flg->sharp == 1)
		*(++p) = '.';
	return (res_str);
}

void	nzero_nminus_e(char **p, t_qualfrs *fmt)
{
	if (fmt->ld->delta > 0)
	{
		ft_memset(*p, ' ', fmt->ld->delta);
		*p += fmt->ld->delta;
	}
	put_first_simbol(p, fmt);
}

void	zero_nminus_e(char **p, t_qualfrs *fmt)
{
	if (fmt->flg->plus != 0 || fmt->flg->space == 1)
		put_first_simbol(p, fmt);
	if (fmt->ld->delta > 0)
	{
		ft_memset(*p, '0', fmt->ld->delta);
		*p += fmt->ld->delta;
	}
}

long	fill_left_part(char *res_str, t_qualfrs *fmt)
{
	char	*p;

	p = res_str;
	if (fmt->flg->zero && !fmt->flg->minus)
		zero_nminus_e(&p, fmt);
	else if (!fmt->flg->zero && !fmt->flg->minus)
		nzero_nminus_e(&p, fmt);
	else if (fmt->flg->plus != 0 || fmt->flg->space == 1)
		put_first_simbol(&p, fmt);
	return (p - res_str);
}
