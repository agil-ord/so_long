/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:28:50 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:45:56 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s1);
	str = (char *) malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		str[i] = s1[i];
		i ++;
	}
	str[i] = '\0';
	return (str);
}
