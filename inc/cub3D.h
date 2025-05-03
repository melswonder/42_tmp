/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:57:13 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 12:27:52 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include <dirent.h>
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef O_DIRECTORY
# define O_DIRECTORY 0x10000
#endif

typedef enum e_opcode
{
	NORTH_TEXTURE,
	SOUTH_TEXTURE,
	WEST_TEXTURE,
	EAST_TEXTURE,
	FLOOR_COLOR,
	CEILING_COLOR,
	MAP,
	ERROR_OPCODE,
	SPACE_OPCODE
}					t_opcode;

typedef enum e_direction
{
	NOTHING,
	NORTH,
	SOUTH,
	WEST,
	EAST
}					t_direction;

typedef struct s_map_info
{
	char			**map;
	int				map_width;
	int				map_height;
	t_direction		dir;
	int				player_start_x;
	int				player_start_y;
}					t_map_info;

typedef struct s_texture_img
{
	char			*name;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_texture_img;

typedef struct s_game_info
{
	t_texture_img	*north_texture;
	t_texture_img	*south_texture;
	t_texture_img	*west_texture;
	t_texture_img	*east_texture;
	int				floor_color[3];
	int				ceiling_color[3];
	t_map_info		*map_data;
	void			*mlx;
	void			*mlx_win;
	// t_player	*player;　レイトレーシングの構造体を追加するならこんな感じ？？
}					t_game_info;

#endif