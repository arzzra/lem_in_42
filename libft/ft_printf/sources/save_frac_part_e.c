/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_frac_part_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:40:08 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 11:50:29 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	after_round(char *sf, t_qualfrs *fmt)
{
	char	*dup;

	if (sf[0] == '9' && check_last_dig(&(sf[1])))
	{
		replace_dig(&(sf[0]), &(fmt->ld->carry));
		dup = ft_strdup(sf);
		fmt->ld->e++;
		sf[0] = '1';
		fmt->ld->tmp = sf[0];
		ft_strncpy(&(sf[1]), dup, ft_strlen(dup) - 1);
		free(dup);
	}
}

void	before_round(char *sf, t_qualfrs *fmt)
{
	if (fmt->ld->realprec == 0)
	{
		if (check_last_dig(&(sf[1])))
		{
			fmt->ld->e++;
			sf[0] = '1';
		}
	}
	fmt->ld->tmp = sf[0];
	if (fmt->ld->realprec > 0 || fmt->flg->sharp)
	{
		sf[0] = '.';
	}
}

void	fill_last_part(char *sf, uint64_t *p_frac, t_qualfrs *fmt)
{
	size_t		len;
	char		*p;
	long long	dt;

	len = ft_strlen(sf);
	if (fmt->ld->e >= 0)
	{
		ft_memset(&(sf[len]), '0', fmt->ld->count_0);
		len += fmt->ld->count_0;
	}
	buf_to_str(p_frac, &(sf[len]));
	len = ft_strlen(sf);
	dt = fmt->ld->realprec - (long long)len;
	p = &(sf[len + dt]);
	while (dt >= 0)
	{
		*p = '0';
		p--;
		dt--;
	}
}

int		fill_int_part(char *sf, uint64_t *p_int, t_qualfrs *fmt)
{
	int i;

	i = 1;
	if (fmt->ld->iflg == 0 && fmt->ld->fflg == 0)
	{
		if (fmt->ld->realprec > 0 || fmt->flg->sharp == 1)
		{
			*sf = '.';
			sf++;
			i++;
		}
		fmt->ld->e = 0;
		fill_e_end((sf), fmt);
		return (-i);
	}
	if (fmt->ld->iflg == 1)
	{
		if (p_int[0] * BASELEN > (uint64_t)fmt->ld->totallen)
		{
			p_int = cut_buf(p_int, fmt->ld->totallen + 7);
		}
		buf_to_str(p_int, sf);
	}
	return (i);
}

char	*save_fp_e(char *sf, uint64_t *p_int, uint64_t *p_frac, t_qualfrs *fmt)
{
	int	i;

	sf[0] = '\0';
	fmt->ld->carry = 0;
	if ((i = fill_int_part(sf, p_int, fmt)) < 0)
		return (fill_res_e(&(sf[-(i - 1)]), fmt));
	i--;
	fill_last_part(&(sf[i]), p_frac, fmt);
	before_round(&(sf[0]), fmt);
	round_line(&(sf[1]), fmt);
	after_round(&(sf[0]), fmt);
	fill_e_end(&(sf[i]), fmt);
	return (fill_res_e(&(sf[i]), fmt));
}
