/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_contentsearch.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:18:01 by cdemetra          #+#    #+#             */
/*   Updated: 2019/05/14 18:14:12 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_contentsearch(t_list *lst, void *content_search)
{
	t_list	*temp;

	if (lst != NULL || content_search != NULL)
	{
		temp = lst;
		while (temp)
		{
			if (!ft_memcmp(temp->content, content_search, temp->content_size))
				return (temp);
			temp = temp->next;
		}
	}
	return (NULL);
}
