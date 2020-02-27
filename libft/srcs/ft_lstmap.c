/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:10:22 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/30 14:19:07 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_dellst(void *content, size_t size_content)
{
	if (size_content > 0)
		free(content);
	content = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*hlist;
	t_list	*elm;

	list = NULL;
	hlist = NULL;
	if (!(f) || lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (!(elm = f(lst)))
		{
			if (hlist != NULL)
				ft_lstdel(&hlist, &ft_dellst);
			return (NULL);
		}
		if (list != NULL)
			list->next = elm;
		else
			hlist = elm;
		list = elm;
		lst = lst->next;
	}
	return (hlist);
}
