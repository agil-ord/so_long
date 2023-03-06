/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:51:31 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:47:28 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_format(char c, va_list	lst, int *pt_i )
{
	if (c == '%')
		ft_putchar_printf('%', pt_i);
	else if (c == 'c')
		ft_putchar_printf(va_arg(lst, int), pt_i);
	else if (c == 's')
		ft_putstr_printf(va_arg(lst, char *), pt_i);
	else if (c == 'p')
	{
		ft_putstr_printf("0x", pt_i);
		ft_putnbr_hex_p(va_arg(lst, unsigned long long),
			"0123456789abcdef", pt_i);
	}
	else if (c == 'd')
		ft_putnbr_printf(va_arg(lst, int), pt_i);
	else if (c == 'i')
		ft_putnbr_printf(va_arg(lst, int), pt_i);
	else if (c == 'u')
		ft_putnbr_uns_printf(va_arg(lst, unsigned long), pt_i);
	else if (c == 'x')
		ft_putnbr_hex_p(va_arg(lst, unsigned int), "0123456789abcdef", pt_i);
	else if (c == 'X')
		ft_putnbr_hex_cap(va_arg(lst, unsigned int), "0123456789ABCDEF", pt_i);
	return (*pt_i);
}

int	ft_printf(char const	*str, ...)
{
	va_list	lst;
	int		i;
	int		pt_i;

	pt_i = 0;
	i = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_format(str[i + 1], lst, &pt_i);
			i++;
		}
		else
			ft_putchar_printf((char) str[i], &pt_i);
		i++;
	}
	va_end(lst);
	return (pt_i);
}
