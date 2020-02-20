/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:59:40 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/27 15:49:21 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	char	*ft_cut_zero(char *str, int *h)
{
	size_t	i;

	i = 0;
	while (str[i] == '0')
		i++;
	*h = 64 - i;
	return (ft_strdup(&(str[i])));
}

void			ft_print_b(t_qualfrs *ql)
{
	long long int	y;
	char			*bin;

	y = va_arg(ql->ap, long long int);
	if (!(bin = ft_strnew(64)))
		return ;
	print_bits2(&y, bin, 7);
	if (!(ql->num = ft_cut_zero(bin, &ql->countnum)))
		return ;
	free(bin);
	ft_print_u2(ql);
	free(ql->num);
}
