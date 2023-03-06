/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_cap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:42:51 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:47:34 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_cap(unsigned int nb, char *base, int *pt_i)
{
	size_t	n;

	n = (size_t)nb;
	if (nb >= 16)
	{
		ft_putnbr_hex_cap((n / 16), base, pt_i);
		ft_putnbr_hex_cap((n % 16), base, pt_i);
	}
	else
		ft_putchar_printf(base[n], pt_i);
}
