/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:50:19 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:47:44 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_uns_printf(unsigned int nb, int *pt_i)
{
	long long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar_printf('-', pt_i);
		ft_putnbr_uns_printf(-n, pt_i);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_uns_printf(n / 10, pt_i);
		}
		ft_putchar_printf(48 + n % 10, pt_i);
	}
}
