/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:17:14 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:47:41 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(int nb, int *pt_i)
{
	long long	n;

	n = (long long)nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		*pt_i += 1;
	}
	if (n > 9)
	{
		ft_putnbr_printf(n / 10, pt_i);
	}
	ft_putchar_printf(48 + n % 10, pt_i);
}
