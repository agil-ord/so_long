/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:34:42 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/08 11:20:25 by agil-ord         ###   ########.fr       */
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

void	ft_flood_fill(t_game *game, int x, int y)
{
	if (!(x < 1 || y < 1 || x >= game->map_width || y > game->map_height
			|| game->map_2[y][x] == '1' || game->map_2[y][x] == 'X'))
	{
		game->map_2[y][x] = 'X';
		ft_flood_fill(game, x, y + 1);
		ft_flood_fill(game, x + 1, y);
		ft_flood_fill(game, x, y - 1);
		ft_flood_fill(game, x - 1, y);
	}
}

int	*ft_start(char **map_2)
{
	int	x;
	int	y;
	int	*pos;

	pos = (int *)malloc(sizeof(int) * 2);
	y = 0;
	while (map_2[y])
	{
		x = 0;
		while (map_2[y][x])
		{
			if (map_2[y][x] == 'P')
			{
				pos[0] = x;
				pos[1] = y;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

int	ft_check_path(t_game *game)
{
	int	i;
	int	j;

	game->n_meat2 = 0;
	game->n_exit = 0;
	game->n_luffy = 0;
	i = 0;
	while (game->map_2[i])
	{
		j = 0;
		while (game->map_2[i][j])
		{
			if (game->map_2[i][j] == 'E')
				game->n_exit++;
			else if (game->map_2[i][j] == 'P')
				game->n_luffy++;
			else if (game->map_2[i][j] == 'C')
				game->n_meat2++;
			j++;
		}
		i++;
	}
	if (game->n_meat2 != 0 || game->n_exit != 0 || game->n_luffy != 0)
		return (FALSE);
	return (TRUE);
}

int	ft_path(t_game *game, char *file)
{
	int	*pos;

	game->map_2 = ft_read_map(file);
	pos = ft_start(game->map_2);
	ft_flood_fill(game, pos[0], pos[1]);
	if (ft_check_path(game) == FALSE)
	{
		ft_printf("\nError!\n There is not a valid path\n");
		free(pos);
		ft_free_solong(game->map_2);
		return (FALSE);
	}
	ft_free_solong(game->map_2);
	free(pos);
	return (TRUE);
}
