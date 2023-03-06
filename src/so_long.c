/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:30:34 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/06 20:29:13 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_solong(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		free(map[i]);
	}
	free(map);
}

void	ft_game_init(t_game *game)
{	
	game->move_count = 0;
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", false);
	if (!(game->mlx))
		exit(EXIT_FAILURE);
	get_textures(game);
	get_images(game);
	ft_map_draw(game, game->imag);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_free_solong(game->map);
	free(game->textu);
	free(game->imag);
}

void	ft_l(void)
{
	system("leaks -q so_long");
}

int	main(int ac, char **av)
{
	t_game	game;

	atexit(ft_l);
	if (ac == 2)
	{
		ft_main(game, av[1]);
		if (ft_argv(av[1]) == FALSE)
			return (255);
		game.map = ft_read_map(av[1]);
		if (!game.map)
			return (255);
		if (ft_checker_map(game.map) == FALSE)
		{
			ft_free_solong(game.map);
			return (255);
		}
		game.n_meat = ft_count_meat(&game);
		ft_size_map(&game, game.map);
		if (ft_min_tiles(game) == FALSE)
		{
			ft_free_solong(game.map);
			return (255);
		}
		ft_game_init(&game);
		return (0);
	}
	ft_printf("\nError, you don't have a map\n");
	return (255);
}
