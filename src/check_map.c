/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:04:31 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/12 15:24:04 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_void_map(char **map)
{
	if (map[0])
		return (TRUE);
	else
		return (FALSE);
}

int	ft_map_rectangle(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (FALSE);
		else
			i++;
	}
	return (TRUE);
}

int	ft_map_wall(char **map)
{
	size_t	i;
	int		j;
	int		row;

	row = 0;
	while (map[row])
		row++;
	i = 1;
	while (i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[row - 1][i] != '1')
			return (FALSE);
		i++;
	}
	j = 1;
	while (j < (row - 1))
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[0]) - 1] != '1')
			return (FALSE);
		j++;
	}
	return (TRUE);
}

int	ft_different_c(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!((map[i][j] == '1' || map[i][j] == '0')
				|| (map[i][j] == 'E' || map[i][j] == 'P')
				|| (map[i][j] == 'C')))
				return (FALSE);
			else
				j++;
		}
		i++;
	}
	return (TRUE);
}

int	ft_checker_map(char **map)
{
	if (ft_void_map(map) == FALSE)
	{
		ft_printf("\nError\nfile map is void.\n");
		return (FALSE);
	}
	if (ft_map_rectangle(map) == FALSE)
	{
		ft_printf("\nError\nmap is not rectangle.\n");
		return (FALSE);
	}
	if (ft_different_c(map) == FALSE)
	{
		ft_printf("\nError\nmap have extrange componets.\n");
		return (FALSE);
	}
	if (ft_map_wall(map) == FALSE)
	{
		ft_printf("\nError\nmap is not close.\n");
		return (FALSE);
	}
	return (TRUE);
}
