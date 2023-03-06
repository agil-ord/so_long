/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:07:36 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/06 19:36:24 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(t_game *game)
{
	if (game->map[game->imag->luffy->instances[0].y / 64 - 1]
		[game->imag->luffy->instances[0].x / 64] != '1')
	{
		game->imag->luffy->instances[0].y -= MOVE;
		game->imag->luffy->instances[0].y -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	ft_move_down(t_game *game)
{		
	if (game->map[game->imag->luffy->instances[0].y / 64 + 1]
		[game->imag->luffy->instances[0].x / 64] != '1')
	{
		game->imag->luffy->instances[0].y += MOVE;
		game->imag->luffy->instances[0].y += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->imag->luffy->instances[0].y / 64]
		[game->imag->luffy->instances[0].x / 64 - 1] != '1')
	{
		game->imag->luffy->instances[0].x -= MOVE;
		game->imag->luffy->instances[0].x -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->imag->luffy->instances[0].y / 64]
		[game->imag->luffy->instances[0].x / 64 + 1] != '1')
	{
		game->imag->luffy->instances[0].x += MOVE;
		game->imag->luffy->instances[0].x += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = &(*param);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		ft_move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		ft_move_down(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		ft_move_right(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		ft_move_left(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	ft_collect_meat(game);
}
