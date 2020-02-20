/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:07:41 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/26 19:14:04 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_u_3(t_qualfrs *ql)
{
	if (ql->prcs > ql->countnum)
	{
		ft_print_space((ql->width - (ql->prcs - ql->countnum)
		- ql->countnum), ql);
		ft_print_zero((ql->prcs - ql->countnum), ql);
		ql->countchr += write(1, ql->num, ql->countnum);
	}
	else
	{
		ft_print_space(ql->width - ql->countnum, ql);
		ql->countchr += write(1, ql->num, ql->countnum);
	}
}

void	ft_print_u_2(t_qualfrs *ql)
{
	if (ql->width > ql->countnum)
	{
		ft_print_zero((ql->width - ql->countnum), ql);
		ql->countchr += write(1, ql->num, ql->countnum);
	}
	else
	{
		ql->countchr += write(1, ql->num, ql->countnum);
	}
}

void	ft_print_u_1(t_qualfrs *ql)
{
	if (ql->prcs > ql->countnum)
	{
		ft_print_zero((ql->prcs - ql->countnum), ql);
		ql->countchr += write(1, ql->num, ql->countnum);
		ft_print_space((ql->width - (ql->prcs - ql->countnum)
		- ql->countnum), ql);
	}
	else
	{
		ql->countchr += write(1, ql->num, ql->countnum);
		ft_print_space(ql->width - ql->countnum, ql);
	}
}

void	ft_print_u2(t_qualfrs *ql)
{
	t_flag *fl;

	fl = ql->flg;
	if (ql->width > ql->countnum)
	{
		if (fl->minus)
			ft_print_u_1(ql);
		else
		{
			if (fl->zero && ql->prcs == -1)
				ft_print_u_2(ql);
			else
				ft_print_u_3(ql);
		}
	}
	else
	{
		if (ql->prcs > ql->countnum)
		{
			ft_print_zero((ql->prcs - ql->countnum), ql);
			ql->countchr += write(1, ql->num, ql->countnum);
		}
		else
			ql->countchr += write(1, ql->num, ql->countnum);
	}
}

void	ft_print_u(t_qualfrs *ql)
{
	t_length			*len;

	len = ql->len;
	if (len->l > 0 || len->h > 0)
		ql->num = ft_unsign_lenchoose(ql);
	else
	{
		ql->num = ft_itoa2((unsigned long long)va_arg(ql->ap, unsigned int),
		&(ql->countnum));
	}
	ql->countnum = (!ql->prcs && ql->num[0] == '0') ? 0 : ql->countnum;
	ft_print_u2(ql);
	free(ql->num);
}
