/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:34:42 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/06 19:38:51 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_min_tiles(t_game game)
{
	int	i;
	int	j;

	game.n_exit = 0;
	game.n_luffy = 0;
	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] == 'E')
				game.n_exit++;
			if (game.map[i][j] == 'P')
				game.n_luffy++;
			j++;
		}
		i++;
	}
	if (game.n_exit != 1 || game.n_luffy != 1 || game.n_meat < 1)
	{
		ft_printf("\nError\n You don't have the correct components\n");
		return (FALSE);
	}
	return (TRUE);
}

int	ft_argv(char *path_map)
{
	int	i;

	i = ft_strlen(path_map) - 1;
	if (path_map[i] != 'r' || path_map[i - 1] != 'e'
		|| path_map[i - 2] != 'b'
		|| path_map[i - 3] != '.')
	{
		ft_printf("Error\n invalid extension map.\n");
		return (FALSE);
	}
	return (TRUE);
}
