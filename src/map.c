/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:01:16 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/12 16:18:09 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_read_map(char *path)
{
	int		fd;
	char	*take_map;
	char	**map;
	int		n;

	n = 0;
	take_map = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!take_map)
		return (free(take_map), NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(take_map);
		return (NULL);
	}
	n = read(fd, take_map, BUFF_SIZE);
	if (n == -1 || n == 0)
		return (free(take_map), NULL);
	map = ft_split(take_map, '\n');
	free(take_map);
	close(fd);
	return (map);
}

void	ft_size_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->n_meat = ft_count_meat(game);
	game->map_width = ft_strlen(map[0]) * 64;
	while (map[i])
		i++;
	game->map_height = i * 64;
}
