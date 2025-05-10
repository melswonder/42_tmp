/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:57:13 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/07 23:43:33 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <ctype.h>
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef O_DIRECTORY
#  define O_DIRECTORY 0x10000
# endif

// ============================
// ====== Macros ==============
// ============================

// Macros - general
# define FAILURE 1
# define SUCCESS 0

// Macros - mlx
# define WIN_X 1200
# define WIN_Y 800
# define IMG_WIDTH 64
# define IMG_HEIGHT 64
# define WIN_X 1200
# define WIN_Y 800
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

# define FOV_SCALE 0.66

// ============================
// ===== Typedefs =============
// ============================
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

typedef enum e_side
{
	VERTICAL_SIDE,
	HORIZONTAL_SIDE
}				t_side;

typedef struct s_map_info
{
	char		**map;
	int			map_width;
	int			map_height;
	t_direction	dir;
	int			player_start_x;
	int			player_start_y;
}				t_map_info;

/*
** Gets the data address of the current image.
**
** void *img_ptr		the image instance;
** int  *bits_per_pixel	a pointer to where the bpp is written;
** int  *size_line		a pointer to where the line is written;
** int  *endian			a pointer to where the endian is written;
** char*				the memory address of the image.
*/
typedef struct s_cub_img
{
	char		*name;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_cub_img;

typedef struct s_player
{
	float minimap_player_x; // minimapのplayerのx
	float		minimap_player_y;
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		angle;
	bool move_up; //キーが押されたかのbool
	bool		move_down;
	bool		move_left;
	bool		move_right;
	bool		rotate_left;
	bool		rotate_right;
}				t_player;

typedef struct s_ray
{
	float		camera_x;
	int			map_x;
	int			map_y;
	float		dir_x;
	float		dir_y;
	float		side_dist_x;
	float		side_dist_y;
	int			step_x;
	int			step_y;
	float		delta_dist_x;
	float		delta_dist_y;
	float		distance_to_wall_full;
	float		distance_to_wall_perp;
	int			collision_side;
}				t_ray;

typedef struct s_game_info
{
	t_cub_img	*north_texture;
	t_cub_img	*south_texture;
	t_cub_img	*west_texture;
	t_cub_img	*east_texture;
	int			floor_color[3];
	int			ceiling_color[3];
	t_map_info	*map_data;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_player *player; //レイトレーシングの構造体を追加するならこんな感じ？？
	// t_ray	*ray;
	// t_cub_img *main_img;
	// t_cub_img *minimap;
}				t_game_info;

#endif