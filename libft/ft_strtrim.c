/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:16:41 by cdemetra          #+#    #+#             */
/*   Updated: 2019/06/17 21:13:32 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	x;
	char	*str;
	size_t	d;

	i = 0;
	d = 0;
	x = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	x = ft_strlen(s);
	if (i == x || s[0] == '\0')
		return (ft_strnew(1));
	while (s[x] == ' ' || s[x] == '\t' || s[x] == '\n' ||
	s[x] == '\0')
		x--;
	if (!(str = (char*)malloc(sizeof(char) * (x - i + 2))))
		return (NULL);
	while (i <= x)
		str[d++] = s[i++];
	str[d] = '\0';
	return (str);
}
