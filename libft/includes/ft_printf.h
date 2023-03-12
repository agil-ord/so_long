/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:23:19 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/12 20:04:39 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "memory_leaks.h"

int		ft_printf(char const	*str, ...);
void	ft_putchar_printf(char c, int *pt_i);
void	ft_putstr_printf(char *s, int *pt_i);
void	ft_putnbr_hex_p(unsigned long long nb, char *base, int *pt_i);
void	ft_putnbr_uns_printf(unsigned int nb, int *pt_i);
void	ft_putnbr_printf(int nb, int *pt_i);
void	ft_putnbr_hex_cap(unsigned int nb, char *base, int *pt_i);

#endif
