/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_csp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:47:10 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/25 17:01:46 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_print_format(char *as, t_qualfrs *qual)
{
	size_t	r;
	char	*str;
	char	*sa;

	if (!(sa = ft_strchr(as, '%')))
	{
		qual->countchr += write(1, as, ft_strlen(as));
		return (NULL);
	}
	r = sa - as;
	if (r > 0)
	{
		str = ft_strncpy(ft_strnew(r), as, r);
		qual->countchr += write(1, str, r);
		free(str);
		return (++sa);
	}
	sa++;
	return (sa);
}

void	ft_print_char(t_qualfrs *ql)
{
	t_flag	*fl;
	char	c;

	fl = ql->flg;
	if (ql->width > 0)
	{
		if (fl->minus > 0)
		{
			c = va_arg(ql->ap, int);
			ql->countchr += write(1, &c, 1);
			ft_print_space(ql->width - 1, ql);
		}
		else
		{
			c = va_arg(ql->ap, int);
			ft_print_space(ql->width - 1, ql);
			ql->countchr += write(1, &c, 1);
		}
	}
	else
	{
		c = va_arg(ql->ap, int);
		ql->countchr += write(1, &c, 1);
	}
}

void	ft_print_str(t_qualfrs *ql)
{
	if (ql->typs == TYPES[1])
	{
		if (!(ql->num = va_arg(ql->ap, char*)))
			ql->num = NULLPRINT;
		ql->countnum = ft_strlen(ql->num);
		ql->countnum = (ql->prcs >= 0 && ql->prcs < ql->countnum)
		? ql->prcs : ql->countnum;
		ql->countnum = ql->countnum > 0 ? ql->countnum : 0;
	}
	else if (ql->typs == TYPES[14])
	{
		if (!(ql->num = va_arg(ql->ap, char*)))
			ql->num = NULLPRINT;
		ql->countnum = ft_wstrlen(ql->num);
		ql->countnum = (ql->prcs >= 0 && ql->prcs < ql->countnum)
		? ql->prcs : ql->countnum;
		ql->countnum = ql->countnum > 0 ? ql->countnum : 0;
	}
	ft_print_str2(ql);
}

void	ft_print_pointer2(t_qualfrs *ql)
{
	t_flag	*fl;

	fl = ql->flg;
	if (ql->width > 0)
	{
		if (fl->minus)
		{
			ql->countchr += write(1, &ADDRESS, 2);
			ft_print_zero(ql->prcs - ql->countnum, ql);
			ql->countchr += write(1, ql->num, ql->countnum);
			ft_print_space(ql->width - ql->countnum - 2, ql);
		}
		else
			ft_print_pointer2_1(ql);
	}
	else
	{
		ql->countchr += write(1, &ADDRESS, 2);
		ft_print_zero(ql->prcs - ql->countnum, ql);
		ql->countchr += write(1, ql->num, ql->countnum);
	}
}

void	ft_print_pointer(t_qualfrs *ql)
{
	char				*poin;
	unsigned long long	tr;
	unsigned long long	rt;
	int					i;

	i = 1;
	poin = va_arg(ql->ap, char*);
	tr = (unsigned long long)poin;
	rt = tr;
	while (tr /= 16)
		i++;
	i = (rt == 0 && !ql->prcs) ? 0 : i;
	if (!(ql->num = ft_strnew(i)))
		return ;
	ql->countnum = i;
	while (--i >= 0)
	{
		ql->num[i] = (rt % 16 < 10) ? rt % 16 + '0' : rt % 16 - 10 + 'a';
		rt /= 16;
	}
	ft_print_pointer2(ql);
	free(ql->num);
}
