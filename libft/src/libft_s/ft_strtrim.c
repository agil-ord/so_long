/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:40:29 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:45:56 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*str;
	size_t	s1len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1len = ft_strlen(s1);
	while (s1len != 0 && ft_strchr(set, s1[s1len]))
		s1len--;
	str = ft_substr(s1, 0, s1len + 1);
	return (str);
}
//if (ft_substr(set, 0, ft_strlen(set)))