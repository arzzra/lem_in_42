/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 11:49:19 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/29 16:02:38 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	replace_dig(char *s_base_i, short *f)
{
	if (*s_base_i - 48 < 9)
	{
		*s_base_i += 1;
		*f = 0;
	}
	else
	{
		*s_base_i = '0';
		*f = 1;
	}
}

int		check_last_dig(char *s)
{
	char		*snum;
	size_t		len;

	snum = s;
	len = ft_strlen(snum);
	if (s[0] == '0' || len == 0)
		return (0);
	s[8] = '\0';
	len = ft_strlen(snum);
	snum = ft_itoa(ft_atoi(s) + 1);
	if (ft_strlen(snum) > len || snum[0] > '5')
	{
		return (1);
	}
	if (snum[0] == '5')
	{
		if (ft_atoi(&(snum[1])) > 0)
			return (1);
	}
	return (0);
}

void	round_line(char *s_full, t_qualfrs *fmt)
{
	long long	i;
	short		f;

	i = fmt->ld->realprec;
	if (check_last_dig(&(s_full[i])))
	{
		if (i >= 1)
			replace_dig(&(s_full[i - 1]), &f);
		else
			f = 1;
		while (f == 1)
		{
			if (i - 1 <= 0)
			{
				fmt->ld->carry = 1;
				break ;
			}
			i--;
			replace_dig(&(s_full[i - 1]), &f);
		}
	}
	s_full[fmt->ld->realprec] = '\0';
}
