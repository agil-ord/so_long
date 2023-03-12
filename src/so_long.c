/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:30:34 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/12 16:18:27 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_argv(char *path_map)
{
	int	i;

	i = ft_strlen(path_map) - 1;
	if (path_map[i] != 'r' || path_map[i - 1] != 'e'
		|| path_map[i - 2] != 'b'
		|| path_map[i - 3] != '.')
	{
		ft_printf("\nError\ninvalid extension map.\n");
		return (FALSE);
	}
	return (TRUE);
}

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

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		if (ft_argv(av[1]) == FALSE)
			return (255);
		game.map = ft_read_map(av[1]);
		if (!game.map)
			return (ft_printf("\nError \nwith file\n"), 255);
		if (ft_checker_map(game.map) == FALSE)
			return (ft_free_solong(game.map), 255);
		ft_size_map(&game, game.map);
		if (ft_min_tiles(game) == FALSE)
			return (ft_free_solong(game.map), 255);
		if (ft_path(&game, av[1]) == FALSE)
			return (ft_free_solong(game.map), 255);
		ft_game_init(&game);
		return (0);
	}
	ft_printf("\nError\nyou don't have a map\n");
	return (255);
}
