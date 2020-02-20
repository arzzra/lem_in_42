/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:20:20 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/23 21:47:54 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_di_neg(t_qualfrs *ql)
{
	t_flag		*fl;
	t_length	*len;

	fl = ql->flg;
	len = ql->len;
	ql->countchr += write(1, &MINUS, 1);
	if (ql->prcs > ql->countnum)
	{
		ft_print_zero((ql->prcs - ql->countnum), ql);
		ft_print_number(ql);
		ft_print_space((ql->width - (ql->prcs - ql->countnum)
		- ql->countnum - 1), ql);
	}
	else
	{
		ft_print_number(ql);
		ft_print_space(ql->width - ql->countnum - 1, ql);
	}
}

void	ft_print_di_pos(t_qualfrs *ql)
{
	t_flag		*fl;
	t_length	*len;
	int			plus;

	fl = ql->flg;
	len = ql->len;
	plus = fl->plus || fl->space ? 1 : 0;
	if (fl->space > 0 && fl->plus == 0)
		ft_print_space(1, ql);
	if (fl->plus > 0)
		ql->countchr += write(1, &PLUS, 1);
	if (ql->prcs > ql->countnum)
	{
		ft_print_zero((ql->prcs - ql->countnum), ql);
		ft_print_number(ql);
		ft_print_space((ql->width - (ql->prcs - ql->countnum)
		- ql->countnum - plus), ql);
	}
	else
	{
		ft_print_number(ql);
		ft_print_space(ql->width - ql->countnum - plus, ql);
	}
}

void	ft_print_di_neg2(t_qualfrs *ql)
{
	ql->countchr += write(1, &MINUS, 1);
	if (ql->width > ql->countnum)
	{
		ft_print_zero((ql->width - ql->countnum - 1), ql);
		ft_print_number(ql);
	}
	else
		ft_print_number(ql);
}

void	ft_print_di_pos2(t_qualfrs *ql)
{
	t_flag		*fl;
	t_length	*len;

	fl = ql->flg;
	len = ql->len;
	if (fl->space > 0 && fl->plus == 0)
		ft_print_space(1, ql);
	else if (fl->plus > 0)
	{
		ql->countchr += write(1, &PLUS, 1);
		fl->space = 0;
	}
	if (ql->width > ql->countnum)
	{
		ft_print_zero((ql->width - ql->countnum -
		fl->plus - fl->space), ql);
		ft_print_number(ql);
	}
	else
		ft_print_number(ql);
}

void	ft_print_di_neg3(t_qualfrs *ql)
{
	if (ql->prcs > ql->countnum)
		ft_print_space((ql->width - (ql->countnum + 1)
		- (ql->prcs - ql->countnum)), ql);
	else
		ft_print_space((ql->width - (ql->countnum + 1)), ql);
	ql->countchr += write(1, &MINUS, 1);
	ft_print_zero((ql->prcs - ql->countnum), ql);
	ft_print_number(ql);
}
