/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver_parts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:57:53 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/28 17:58:43 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	correct_prec(t_qualfrs *fmt)
{
	if (fmt->ld->d < 0)
		fmt->ld->d *= -1;
	if (fmt->ld->sign_exp == -1)
	{
		fmt->ld->exp *= -1;
	}
	fmt->ld->realprec = fmt->prcs;
	if (fmt->prcs < 6)
	{
		fmt->prcs = 6;
	}
	fmt->ld->ovrld = 0;
	if (fmt->prcs > 16383)
	{
		fmt->ld->ovrld = fmt->prcs - 16383;
		fmt->prcs = 16383;
		fmt->ld->realprec = fmt->prcs;
	}
}

char	minlen_type(uint64_t *p_int, t_qualfrs *fmt)
{
	long long	tmp;

	tmp = get_totallen_e(p_int, fmt);
	if (tmp > get_totallen_f(p_int, fmt))
		return ('f');
	fmt->ld->totallen = tmp;
	return ('e');
}

void	solve_type(uint64_t *p_int, uint64_t *p_frac, t_qualfrs *fmt)
{
	char	*res_str;

	res_str = NULL;
	if ((fmt->typs) == 'f' || (fmt->typs) == 'F')
		solve_f(p_int, p_frac, &res_str, fmt);
	if ((fmt->typs) == 'e' || (fmt->typs) == 'E')
		solve_e(p_int, p_frac, &res_str, fmt);
	if ((fmt->typs) == 'g' || (fmt->typs) == 'G')
	{
		if (minlen_type(p_int, fmt) == 'e')
			solve_e(p_int, p_frac, &res_str, fmt);
		else
			solve_f(p_int, p_frac, &res_str, fmt);
	}
	if (res_str)
		free(res_str);
}

void	conver_parts(char *s_int, char *s_frac, t_qualfrs *fmt)
{
	uint64_t	buf_i[2000];
	uint64_t	buf_f[2000];
	uint64_t	*p_int;
	uint64_t	*p_frac;

	fmt->ld->fflg = 0;
	p_int = convert_integer(buf_i, s_int);
	if (buf_i[0] == 1 && buf_i[1] == 0)
		fmt->ld->iflg = 0;
	else
		fmt->ld->iflg = 1;
	correct_prec(fmt);
	if (fmt->ld->fflg == 1 || s_frac[0] == '\0')
		fmt->ld->count_0 = 0;
	else
		fmt->ld->count_0 = count_zero_after_point(fmt->ld->d, fmt);
	p_frac = convert_fraction(s_frac, buf_f, fmt);
	if (buf_f[0] == 1 && buf_f[1] == 0)
		fmt->ld->fflg = 0;
	else
		fmt->ld->fflg = 1;
	solve_type(p_int, p_frac, fmt);
}
