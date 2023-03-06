/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:31:18 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:45:56 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_chars(int n)
{
	long int	nb;
	int			chars;

	nb = n;
	chars = 1;
	if (n < 0)
	{
		chars++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		chars++;
	}
	return (chars);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	int			i;

	str = ft_calloc((count_chars(n) + 1), sizeof(char));
	if (!str)
		return (NULL);
	str[count_chars(n)] = '\0';
	i = count_chars(n) - 1;
	nb = n;
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb >= 10)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	str[i] = nb + '0';
	return (str);
}
/*
static int	ft_size_nbr(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	else if (n < 0)
	{
		n = -n;
		count ++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_size_nbr(n);
	str = (char *) ft_calloc(len + 2, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[len] = 48 + (n % 10);
		n = n / 10;
		len --;
	}
	return (str);
}
	*/