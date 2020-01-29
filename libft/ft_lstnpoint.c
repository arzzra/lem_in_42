/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnpoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 07:12:21 by cdemetra          #+#    #+#             */
/*   Updated: 2019/05/14 16:58:38 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnpoint(t_list *lst, size_t n)
{
	t_list	*pointer;

	pointer = NULL;
	if (n == 1)
		return (lst);
	if (lst != NULL && n != 0)
	{
		while (n > 0 && lst != NULL)
		{
			lst = lst->next;
			pointer = lst;
			n--;
		}
	}
	return (pointer);
}
