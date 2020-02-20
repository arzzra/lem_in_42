/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:56:40 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/23 19:02:20 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_unsign_lenchoose2(t_qualfrs *ql)
{
	t_length				*ln;
	unsigned long int		z;
	unsigned long long int	x;

	ln = ql->len;
	if (ln->l == 1)
	{
		z = va_arg(ql->ap, unsigned long);
		return (ft_itoa2(z, &(ql->countnum)));
	}
	else if (ln->l == 2)
	{
		x = va_arg(ql->ap, unsigned long long int);
		return (ft_itoa2((unsigned long long)x, &(ql->countnum)));
	}
	else
		return (NULL);
}

char	*ft_unsign_lenchoose(t_qualfrs *ql)
{
	t_length			*ln;
	unsigned short int	z;
	unsigned char		x;

	ln = ql->len;
	if (ln->h == 1)
	{
		z = (unsigned short int)va_arg(ql->ap, int);
		return (ft_itoa2((unsigned long long)z, &(ql->countnum)));
	}
	else if (ln->h == 2)
	{
		x = (unsigned char)va_arg(ql->ap, int);
		return (ft_itoa2((unsigned long long)x, &(ql->countnum)));
	}
	else
		return (ft_unsign_lenchoose2(ql));
}

char	*ft_sign_lenchoose2(t_qualfrs *ql)
{
	t_length		*ln;
	long int		z;
	long long int	x;

	ln = ql->len;
	if (ln->l == 1)
	{
		z = va_arg(ql->ap, long int);
		ql->signum = z < 0 ? -1 : 1;
		return (ft_itoa2((unsigned long long)z * ql->signum, &(ql->countnum)));
	}
	else if (ln->l == 2)
	{
		x = va_arg(ql->ap, long long int);
		ql->signum = x < 0 ? -1 : 1;
		return (ft_itoa2((unsigned long long)x * ql->signum, &(ql->countnum)));
	}
	else
		return (NULL);
}

char	*ft_sign_lenchoose(t_qualfrs *ql)
{
	t_length	*ln;
	short int	z;
	signed char	x;

	ln = ql->len;
	if (ln->h == 1)
	{
		z = (short int)va_arg(ql->ap, int);
		ql->signum = z < 0 ? -1 : 1;
		return (ft_itoa2((unsigned long long)z * ql->signum, &(ql->countnum)));
	}
	else if (ln->h == 2)
	{
		x = (signed char)va_arg(ql->ap, int);
		ql->signum = x < 0 ? -1 : 1;
		return (ft_itoa2((unsigned long long)x * ql->signum, &(ql->countnum)));
	}
	else
		return (ft_sign_lenchoose2(ql));
}
