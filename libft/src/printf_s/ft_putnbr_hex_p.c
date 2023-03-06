/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:30:05 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:47:38 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_p(unsigned long long nb, char *base, int *pt_i)
{
	unsigned long long	n;

	n = (unsigned long long)nb;
	if (nb >= 16)
	{
		ft_putnbr_hex_p((n / 16), base, pt_i);
		ft_putnbr_hex_p((n % 16), base, pt_i);
	}
	else
		ft_putchar_printf(base[n], pt_i);
}
