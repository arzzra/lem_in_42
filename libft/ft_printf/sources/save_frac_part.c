/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_frac_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:34 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 11:59:21 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		fill_prec(char *s_full, uint64_t *buf, t_qualfrs *fmt)
{
	if (buf[0] == 1 && buf[1] == 0)
	{
		ft_memset(s_full, '0', fmt->ld->realprec);
		s_full[fmt->ld->realprec] = '\0';
		return ;
	}
	buf_to_str(buf, s_full);
}

long long	get_start_index(char *s_full, uint64_t *buf, t_qualfrs *fmt)
{
	long long	i;
	char		*s_base;

	i = fmt->ld->realprec - fmt->ld->count_0;
	if (i <= 0)
	{
		ft_memset(s_full, '0', fmt->ld->realprec);
		if (i == -1)
		{
			s_base = ft_itoa_base_ll(buf[buf[0]], 10);
			if (s_base[0] - 48 >= 5)
				s_full[fmt->ld->realprec] = '1';
		}
		s_full[fmt->ld->realprec] = '\0';
		return (-1);
	}
	else
	{
		ft_memset(s_full, '0', fmt->ld->count_0);
		s_full[fmt->ld->count_0] = '0';
		return (fmt->ld->count_0);
	}
}

int			nozero_prec(t_qualfrs *fmt, char *s_full, uint64_t *pf)
{
	long long		i;

	i = get_start_index(&(s_full[1]), pf, fmt) + 1;
	if (i == 0 && s_full[fmt->ld->count_0 + 1] == '0')
		return (-1);
	fill_prec(&(s_full[fmt->ld->count_0 + 1]), pf, fmt);
	round_line(&(s_full[1]), fmt);
	if (fmt->ld->count_0 > 0 && fmt->ld->carry == 1)
	{
		s_full[i - 1] = '1';
		fmt->ld->carry = 0;
	}
	return (0);
}

char		*save_fp(char *res, uint64_t *pf, uint64_t *pi, t_qualfrs *fmt)
{
	char	s_full[fmt->ld->realprec + 2 + 8];

	fmt->ld->carry = 0;
	if (fmt->ld->realprec == 0)
	{
		zero_prec(&(s_full[0]), pf, fmt);
	}
	else
	{
		s_full[0] = '.';
		if (nozero_prec(fmt, s_full, pf) == -1)
			return (fill_res_f(res, &(s_full[0]), fmt));
	}
	if (fmt->ld->carry == 1)
	{
		add_s(pi, 1);
		if (fmt->ld->intlen < get_buflen(pi))
		{
			fmt->ld->newmem = 1;
			fmt->ld->totallen += 1;
			res[fmt->ld->totallen] = '\0';
		}
	}
	return (fill_res_f(res, &(s_full[0]), fmt));
}

void		zero_prec(char *s_full, uint64_t *buf, t_qualfrs *fmt)
{
	char		*s_base;

	if (fmt->flg->sharp == 1)
		s_full[0] = '.';
	if (buf[buf[0]] != 0)
	{
		if (fmt->ld->count_0 > 0)
			return ;
		s_base = ft_itoa_base_ll(buf[buf[0]], 10);
		if (((s_base[0] - 48) > 5)
			|| ((s_base[0] - 48) == 5 && s_base[1] - 48 > 0))
			fmt->ld->carry = 1;
	}
	s_full[1] = '\0';
}
