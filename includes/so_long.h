/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:56:01 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/06 18:18:09 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdint.h>
# include <stdlib.h>
# include "MLX42.h"
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include "../../../a/include/memory_leaks.h"
# include <fcntl.h>

# define BUFF_SIZE 10000
# define FALSE		1
# define TRUE		0
# define MOVE		32

typedef struct s_textures {
	mlx_texture_t	*enemies;
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*meat;
	mlx_texture_t	*luffy;
	mlx_texture_t	*exit;
}				t_textures;

typedef struct s_images {
	mlx_image_t	*enemies;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*meat;
	mlx_image_t	*luffy;
	mlx_image_t	*exit;
}				t_images;

typedef struct s_player {
	int	x_player;
	int	y_player;
}				t_player;

typedef struct s_game
{
	struct s_textures	*textu;
	struct s_images		*imag;
	void				*mlx;
	char				**map;
	int					map_width;
	int					map_height;
	int					count_meat;
	int					move_count;
	int					n_meat;
	int					n_exit;
	int					n_luffy;
}	t_game;

//
//							map.c
//
//funcion leer mapa
char		**ft_read_map(char *path);
//funcion para saacar tamaño mapa
void		ft_size_map(t_game *game, char **map);
//
//							draw_images.c
//
//función para decir donde se encuentra la textura que quiero montar
void		get_textures(t_game *game);
//función que le dara una imagen a una textura
void		get_images(t_game *game);
//pintamos el mapa con las imagenes cargadas
int			ft_map_draw(t_game *game, t_images *imag);
//colocamos el suelo en la capa 0
int			ft_floor(t_game *game, t_images *imag);
//
//							move.c
//
void		ft_move_up(t_game *game);
void		ft_move_down(t_game *game);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);
//carga de todos los movimientos
void		my_keyhook(mlx_key_data_t keydata, void *param);
//
//						check_map.c
//
int			ft_checker_map(char **map);
//cheker si esta rodeados de muros
int			ft_map_wall(char **map);
//cheker si es rectangular
int			ft_map_rectangle(char **map);
//mapa es cuadrado
int			ft_map_square(char **map);
//que no tenga caracteres extraños
int			ft_different_c(char **map);
//
//						check_map2.c
//
int			ft_min_tiles(t_game game);

//inicializacion del juego

//
//						collectibles.c
//
int			ft_count_meat(t_game *game);

void		ft_collect_meat(t_game *game);

void		ft_delete_collect(t_game *game);
//
//						so_long.c
//
void		ft_game_init(t_game *game);

int			ft_argv(char *path_map);

void		ft_free_solong(char **map);

#endif
