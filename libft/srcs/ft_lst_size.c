/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:09:41 by cdemetra          #+#    #+#             */
/*   Updated: 2019/05/14 17:13:33 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lst_size(t_list *begin_list)
{
	t_list	*lis;
	size_t	counter;

	counter = 1;
	if (begin_list == NULL)
		return (0);
	lis = begin_list;
	while (lis->next != NULL)
	{
		lis = lis->next;
		counter++;
	}
	return (counter);
}
