/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ox2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:29:49 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/23 21:50:51 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_sharp(t_qualfrs *ql)
{
	t_flag *fl;

	fl = ql->flg;
	if (ql->typs == TYPES[5] && fl->sharp)
		ql->countchr += write(1, &ZERO, 1);
	else if (ql->num[0] != '0')
	{
		if (ql->typs == TYPES[7] && fl->sharp)
			ql->countchr += write(1, &ADDRESS, 2);
		else if (ql->typs == TYPES[8] && fl->sharp)
			ql->countchr += write(1, &ADDRESS2, 2);
		fl->sharp = fl->sharp ? 2 : fl->sharp;
	}
	else
		fl->sharp = 0;
}

char	*ft_len_ox2(unsigned long long numb, t_qualfrs *ql)
{
	t_length				*ln;
	unsigned long int		z;
	unsigned long long int	x;

	ln = ql->len;
	if (ln->l == 1)
	{
		z = (unsigned long int)numb;
		if (ql->typs == TYPES[5])
			return (ft_10_to_8((unsigned long long)z, ql));
		else if (ql->typs == TYPES[7] || ql->typs == TYPES[8])
			return (ft_10_to_16((unsigned long long)z, ql));
	}
	else if (ln->l == 2)
	{
		x = (unsigned long long int)numb;
		if (ql->typs == TYPES[5])
			return (ft_10_to_8((unsigned long long)x, ql));
		else if (ql->typs == TYPES[7] || ql->typs == TYPES[8])
			return (ft_10_to_16((unsigned long long)x, ql));
	}
	return (NULL);
}

char	*ft_len_ox(unsigned long long numb, t_qualfrs *ql)
{
	t_length			*ln;
	unsigned short int	z;
	unsigned char		x;

	ln = ql->len;
	if (ln->h == 1)
	{
		z = (unsigned short int)numb;
		if (ql->typs == TYPES[5])
			return (ft_10_to_8((unsigned long long)z, ql));
		else if (ql->typs == TYPES[7] || ql->typs == TYPES[8])
			return (ft_10_to_16((unsigned long long)z, ql));
	}
	else if (ln->h == 2)
	{
		x = (unsigned char)numb;
		if (ql->typs == TYPES[5])
			return (ft_10_to_8((unsigned long long)x, ql));
		else if (ql->typs == TYPES[7] || ql->typs == TYPES[8])
			return (ft_10_to_16((unsigned long long)x, ql));
	}
	else
		return (ft_len_ox2(numb, ql));
	return (NULL);
}

void	ft_print_ox(t_qualfrs *ql)
{
	unsigned long long	numb;
	unsigned int		c;
	t_flag				*fl;
	t_length			*len;

	fl = ql->flg;
	len = ql->len;
	numb = va_arg(ql->ap, unsigned long long);
	if (len->l > 0 || len->h > 0)
		ql->num = ft_len_ox(numb, ql);
	else
	{
		c = (unsigned int)numb;
		if (ql->typs == TYPES[5])
			ql->num = (void*)ft_10_to_8((unsigned long long)c, ql);
		else if (ql->typs == TYPES[7] || ql->typs == TYPES[8])
			ql->num = (void*)ft_10_to_16((unsigned long long)c, ql);
	}
	ft_print_ox2(ql);
	free(ql->num);
}
