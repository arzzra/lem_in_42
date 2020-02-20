/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:47:10 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/23 21:46:11 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_di_pos3(t_qualfrs *ql)
{
	t_flag		*fl;
	t_length	*len;

	fl = ql->flg;
	len = ql->len;
	if (ql->prcs > ql->countnum)
	{
		ft_print_space((ql->width - (ql->countnum + fl->plus)
		- (ql->prcs - ql->countnum)), ql);
	}
	else
		ft_print_space((ql->width - (ql->countnum + fl->plus)), ql);
	if (fl->space > 0 && fl->plus == 0 && (ql->width < ql->countnum
	|| ql->width <= ql->prcs))
		ft_print_space(1, ql);
	else if (fl->plus > 0)
		ql->countchr += write(1, &PLUS, 1);
	ft_print_zero((ql->prcs - ql->countnum), ql);
	ft_print_number(ql);
}

void	ft_print_di_neg4(t_qualfrs *ql)
{
	ql->countchr += write(1, &MINUS, 1);
	ft_print_zero((ql->prcs - ql->countnum), ql);
	ft_print_number(ql);
}

void	ft_print_di_pos4(t_qualfrs *ql)
{
	t_flag		*fl;
	t_length	*len;
	int			plus;

	fl = ql->flg;
	len = ql->len;
	plus = fl->plus > 0 ? 1 : 0;
	if (fl->space > 0 && fl->plus == 0)
		ft_print_space(1, ql);
	if (fl->plus > 0)
		ql->countchr += write(1, &PLUS, 1);
	ft_print_zero((ql->prcs - ql->countnum), ql);
	ft_print_number(ql);
}

void	ft_print_di_2(t_qualfrs *ql)
{
	if (ql->flg->minus)
	{
		if (ql->signum == -1)
			ft_print_di_neg(ql);
		else
			ft_print_di_pos(ql);
	}
	else
	{
		if (ql->flg->zero && ql->prcs == -1)
		{
			if (ql->signum == -1)
				ft_print_di_neg2(ql);
			else
				ft_print_di_pos2(ql);
		}
		else
		{
			if (ql->signum == -1)
				ft_print_di_neg3(ql);
			else
				ft_print_di_pos3(ql);
		}
	}
}

void	ft_print_di(t_qualfrs *ql)
{
	int		c;

	if (ql->len->l > 0 || ql->len->h > 0)
		ql->num = ft_sign_lenchoose(ql);
	else
	{
		c = va_arg(ql->ap, int);
		ql->signum = c < 0 ? -1 : 1;
		ql->num = (void*)ft_itoa2((unsigned long long)c
		* ql->signum, &(ql->countnum));
	}
	ql->countnum = (ql->num[0] == '0' && ql->prcs == 0)
	? 0 : ql->countnum;
	if (ql->width > ql->countnum)
		ft_print_di_2(ql);
	else
	{
		if (ql->signum == -1)
			ft_print_di_neg4(ql);
		else
			ft_print_di_pos4(ql);
	}
	free(ql->num);
}
