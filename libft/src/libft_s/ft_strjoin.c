/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:04:37 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:45:56 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*totalstr;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	totalstr = (char *) malloc((s1len + s2len + 1) * sizeof(char));
	if (!totalstr)
		return (NULL);
	ft_memcpy(totalstr, s1, s1len);
	ft_memcpy(totalstr + s1len, s2, s2len);
	totalstr[s1len + s2len] = '\0';
	return (totalstr);
}
