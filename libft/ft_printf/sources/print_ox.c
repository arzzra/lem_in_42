/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:26:24 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/23 21:48:40 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_xo4(t_qualfrs *ql)
{
	t_flag *fl;

	fl = ql->flg;
	ft_print_sharp(ql);
	if (ql->prcs > ql->countnum)
	{
		if (ql->typs == TYPES[5])
			ft_print_zero((ql->prcs - ql->countnum - fl->sharp), ql);
		else
			ft_print_zero((ql->prcs - ql->countnum), ql);
		ql->countchr += write(1, ql->num, ql->countnum);
	}
	else if (ql->prcs == 0 && ql->num[0] == '0')
	{
		if (ql->width > 0)
			ft_print_space(1, ql);
		return ;
	}
	else
		ql->countchr += write(1, ql->num, ql->countnum);
}

void	ft_print_xo3(t_qualfrs *ql)
{
	t_flag *fl;

	fl = ql->flg;
	fl->sharp = ql->num[0] == '0' ? 0 : fl->sharp;
	if (ql->prcs > ql->countnum)
		ft_print_space(ql->width - ql->prcs - fl->sharp, ql);
	else
		ft_print_space(ql->width - ql->countnum - fl->sharp, ql);
	ft_print_sharp(ql);
	if (ql->prcs > ql->countnum)
	{
		ft_print_zero((ql->prcs - ql->countnum), ql);
		ql->countchr += write(1, ql->num, ql->countnum);
	}
	else if (ql->prcs == 0 && ql->num[0] == '0')
		ft_print_space(1, ql);
	else
		ql->countchr += write(1, ql->num, ql->countnum);
}

void	ft_print_xo2(t_qualfrs *ql)
{
	t_flag *fl;

	fl = ql->flg;
	ft_print_sharp(ql);
	if (ql->width > ql->countnum)
	{
		ft_print_zero((ql->width - ql->countnum - fl->sharp), ql);
		ql->countchr += write(1, ql->num, ql->countnum);
	}
	else
		ql->countchr += write(1, ql->num, ql->countnum);
}

void	ft_print_xo(t_qualfrs *ql)
{
	t_flag *fl;

	fl = ql->flg;
	ft_print_sharp(ql);
	if (ql->prcs > ql->countnum)
	{
		ft_print_zero((ql->prcs - ql->countnum), ql);
		ql->countchr += write(1, ql->num, ql->countnum);
		ft_print_space(ql->width - ql->prcs - fl->sharp, ql);
	}
	else if (ql->prcs == 0 && ql->num[0] == '0')
	{
		ft_print_space(ql->width, ql);
		return ;
	}
	else
	{
		ql->countchr += write(1, ql->num, ql->countnum);
		ft_print_space(ql->width - ql->countnum - fl->sharp, ql);
	}
}

void	ft_print_ox2(t_qualfrs *ql)
{
	t_flag	*fl;

	fl = ql->flg;
	fl->sharp = (ql->typs == TYPES[5] && ql->prcs > ql->countnum)
	? 0 : fl->sharp;
	if (ql->width > ql->countnum)
	{
		if (fl->minus)
			ft_print_xo(ql);
		else
		{
			if (fl->zero && ql->prcs == -1)
				ft_print_xo2(ql);
			else
				ft_print_xo3(ql);
		}
	}
	else
		ft_print_xo4(ql);
}
