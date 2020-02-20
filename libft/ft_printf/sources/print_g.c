/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:53:02 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/27 15:49:44 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			print_bits2(void *ptr, char *frac, int i)
{
	unsigned char	*b;
	unsigned char	byte;
	int				j;

	b = (unsigned char*)ptr;
	j = 7;
	while (i >= 0)
	{
		while (j >= 0)
		{
			byte = (b[i] >> j) & 1;
			*frac = byte + '0';
			frac++;
			j--;
		}
		j = 7;
		i--;
	}
}

static	void	ft_print_nan_inf(t_qualfrs *ql, int f)
{
	if (f == 1)
	{
		if (ql->width)
			ft_print_space(ql->width - 3, ql);
		if (ql->typs >= 65 && ql->typs <= 90)
			ql->countchr += write(1, &"NAN", 3);
		else
			ql->countchr += write(1, &"nan", 3);
	}
	else if (f == 2)
	{
		if (ql->width)
			ft_print_space(ql->width - 3 - ql->signum, ql);
		ql->countchr += write(1, &MINUS, ql->signum);
		if (ql->typs >= 65 && ql->typs <= 90)
			ql->countchr += write(1, &"INF", 3);
		else
			ql->countchr += write(1, &"inf", 3);
	}
}

int				ft_inf_nan(t_qualfrs *ql)
{
	int		i;
	char	s_int[81];

	print_bits2((void*)&(ql->ld->d), s_int, 9);
	s_int[80] = '\0';
	i = 1;
	while (s_int[i] == '1' && i < 16)
		i++;
	if (i != 16)
		return (0);
	else if (s_int[++i] == '1')
	{
		while (s_int[i] == '0' && s_int[i])
			i++;
		if (i < 80)
			ft_print_nan_inf(ql, 1);
		else
		{
			if (s_int[0] == '1')
				ql->signum = 1;
			ft_print_nan_inf(ql, 2);
		}
		return (1);
	}
	return (0);
}

void			ft_print_pointer2_1(t_qualfrs *ql)
{
	t_flag	*fl;

	fl = ql->flg;
	if (fl->zero && ql->prcs == -1)
	{
		ql->countchr += write(1, &ADDRESS, 2);
		ft_print_zero(ql->width - ql->countnum - 2, ql);
		ql->countchr += write(1, ql->num, ql->countnum);
	}
	else
	{
		ft_print_space(ql->width - ql->countnum - 2, ql);
		ql->countchr += write(1, &ADDRESS, 2);
		ft_print_zero(ql->prcs - ql->countnum, ql);
		ql->countchr += write(1, ql->num, ql->countnum);
	}
}
