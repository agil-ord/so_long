/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:49:50 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/06 18:34:58 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_meat(t_game *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_delete_collect(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->n_meat)
	{
		if (((game->imag->meat->instances[i].y
					== game->imag->luffy->instances[0].y)
				&& (game->imag->meat->instances[i].x
					== game->imag->luffy->instances[0].x))
			&& game->imag->meat->instances[i].enabled == true)
		{
			game->imag->meat->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	ft_collect_meat(t_game *game)
{
	if (game->map[game->imag->luffy->instances[0].y / 64]
		[game->imag->luffy->instances[0].x / 64] == 'C')
	{
		ft_delete_collect(game);
		game->map[game->imag->luffy->instances[0].y / 64]
		[game->imag->luffy->instances[0].x / 64] = '0';
		game->count_meat++;
	}
	if (game->map[game->imag->luffy->instances[0].y / 64]
		[game->imag->luffy->instances[0].x / 64] == 'E')
	{
		if (game->count_meat == game->n_meat)
		{
			mlx_close_window(game->mlx);

		}
	}
}
