/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:38:57 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/08 16:49:52 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_textures(t_game *game)
{
	game->textu = malloc(sizeof(t_textures));
	game->textu->floor = mlx_load_png("./images/floor.png");
	game->textu->exit_2 = mlx_load_png("./images/trampilla.png");
	game->textu->wall = mlx_load_png("./images/wall.png");
	game->textu->meat = mlx_load_png("./images/meat.png");
	game->textu->luffy = mlx_load_png("./images/spriteLuffy/luffy-front.png");
	game->textu->exit = mlx_load_png("./images/stair.png");
}

void	get_images(t_game *game)
{
	game->imag = malloc(sizeof(t_images));
	game->imag->floor = mlx_texture_to_image(game->mlx, game->textu->floor);
	game->imag->wall = mlx_texture_to_image(game->mlx, game->textu->wall);
	game->imag->meat = mlx_texture_to_image(game->mlx, game->textu->meat);
	game->imag->luffy = mlx_texture_to_image(game->mlx, game->textu->luffy);
	game->imag->exit = mlx_texture_to_image(game->mlx, game->textu->exit);
	game->imag->exit_2 = mlx_texture_to_image(game->mlx, game->textu->exit_2);
	mlx_delete_texture(game->textu->floor);
	mlx_delete_texture(game->textu->wall);
	mlx_delete_texture(game->textu->meat);
	mlx_delete_texture(game->textu->luffy);
	mlx_delete_texture(game->textu->exit);
	mlx_delete_texture(game->textu->exit_2);
}

int	ft_floor(t_game *game, t_images *imag)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, imag->floor, x * 64, y * 64);
			if (game->map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, imag->exit, x * 64, y * 64);
				mlx_image_to_window(game->mlx, imag->exit_2, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_map_draw(t_game *game, t_images *imag)
{
	int	y;
	int	x;

	y = 0;
	ft_floor(game, imag);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, imag->wall, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, imag->meat, x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, imag->luffy, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (0);
}
