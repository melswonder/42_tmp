/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:57:13 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/01 18:35:55 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <dirent.h>
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define ERR_ARG_MISSING "ERROR: MISSING ARGUMENT"
#define ERR_FILE_OPEN_ERROR "ERROR: FILE OPEN ERROR"
#define ERR_INVALID_EXTENSION "ERROR: NOT A .CUB FILE"
#define ERR_FILE_IS_DIR "ERROR: FILE IS DIRECTORY"

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
}				t_opcode;

typedef enum e_direction
{
	NOTHING,
	NORTH,
	SOUTH,
	WEST,
	EAST
}				t_direction;

typedef struct s_map_info
{
	char		**map;
	int			map_width;
	int			map_height;
	t_direction	dir;
	int			player_start_x;
	int			player_start_y;
}				t_map_info;

typedef struct s_img
{
	char		*name;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_game_info
{
	t_img		*north_texture;
	t_img		*south_texture;
	t_img		*west_texture;
	t_img		*east_texture;
	int			floor_color[3];
	int			ceiling_color[3];
	t_map_info	*map_data;
	void		*mlx;
	void		*mlx_win;
	// t_player	*player;　レイトレーシングの構造体を追加するならこんな感じ？？
}				t_game_info;

//--error--
void			error_exit(int fd, char *msg);
int				error_msg(int fd, char *msg, char *arg);

//--safe--
void			*safe_malloc(size_t bytes);