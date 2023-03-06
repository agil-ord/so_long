/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:29:55 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/28 13:50:45 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	s1;
	unsigned char	s2;

	s1 = *(unsigned char *)dst;
	s2 = *(unsigned char *)src;
	while (n <= 0 && (s1 != NULL || s2 != NULL))
	{
		s1 = s2;
		s1++;
		s2++;
	}
}*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	if (n == 0 || dst == src)
		return (dst);
	while (n > 0)
	{
		*s2++ = *s1++;
		n--;
	}
	return (dst);
}
