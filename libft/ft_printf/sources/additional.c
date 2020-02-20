/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:21:22 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/25 17:01:16 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_without_typs(t_qualfrs *ql)
{
	t_flag *fl;

	fl = ql->flg;
	if (fl->minus)
	{
		ql->countchr += write(1, &(ql->sformat)[0], 1);
		ft_print_space(ql->width - 1, ql);
	}
	else
	{
		ft_print_space(ql->width - 1, ql);
		ql->countchr += write(1, &(ql->sformat)[0], 1);
	}
	ql->sformat++;
}

void	ft_print_percent(t_qualfrs *ql)
{
	t_flag *fl;

	fl = ql->flg;
	if (ql->width > 1)
	{
		if (fl->minus)
		{
			ql->countchr += write(1, &(TYPES)[13], 1);
			ft_print_space(ql->width - 1, ql);
		}
		else
		{
			if (fl->zero)
				ft_print_zero(ql->width - 1, ql);
			else
				ft_print_space(ql->width - 1, ql);
			ql->countchr += write(1, &(TYPES)[13], 1);
		}
	}
	else
		ql->countchr += write(1, &(TYPES)[13], 1);
}

int		ft_zd(char *frm, t_qualfrs *ql)
{
	if (*frm == 'z' || *frm == 'j')
	{
		ql->len->l = 2;
		return (1);
	}
	else
		return (0);
}

void	ft_print_str_uni(t_qualfrs *ql)
{
	int				i;
	wchar_t			*e;

	if (ql->typs == TYPES[1])
		ql->countchr += write(1, ql->num, ql->countnum);
	else if (ql->typs == TYPES[14])
	{
		e = (wchar_t*)ql->num;
		i = 0;
		while (i < ql->countnum)
		{
			ft_printwchar(e[i], ql);
			i++;
		}
	}
}

void	ft_print_number(t_qualfrs *ql)
{
	if (ql->prcs == 0 && ql->num[0] == '0')
		return ;
	else
		ql->countchr += write(1, ql->num, ql->countnum);
}
