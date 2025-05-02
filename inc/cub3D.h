/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:57:13 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/02 15:06:55 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//--error--
void				error_exit(int fd, char *msg);
int					error_msg(int fd, char *msg, char *arg);

//--safe--
void				*safe_malloc(size_t bytes);

char	*get_next_line(int fd);


// 初期化関数
void	init_img(t_texture_img *img);
void	init_map(t_map_info *map);
void	init_game_info(t_game_info *game_info);

// ファイル検証関数
bool	is_directory(char *filename);
bool	has_cub_extension(char *filename);
int		check_file(char *filename);

// メモリ管理関数
void	free_game_info_no_mlx(t_game_info *game_info);
void	free_mlx_img(void *mlx, t_texture_img *img);
void	free_map(t_map_info *map_info);
void	free_game_info(t_game_info *game_info);

// パース・検証関数
int		is_map_line(char *line);
int		check_value_handle(char *line);
int		set_texture(t_game_info *game_info, char *line, t_opcode opcode);
void	set_colore(t_game_info *game_info, char *line, t_opcode opcode);
char	**add_line_to_map(char **map, char *line, int height);
void	set_width_check_map(t_map_info *map_data, char *line);
void	set_map(t_game_info *game_info, char *line);
void	set_info_handle(t_game_info *game_info, t_opcode opcode, char *line);

// プレイヤー・マップ処理関数
void	find_player_direction(t_map_info *map_info);
void	set_player_dir_position(t_map_info *map_info, int x, int y);
int		is_direction(char c);
void	validate_player_position(t_map_info *map_info);
void	replace_spaces_with_walls(t_map_info *map_info);

// 設定・実行関数
void	set_value_from_file(t_game_info *game_info, char *filename);
int		parse_args(t_game_info *game_info, char **argv);
void	print_game_info(t_game_info *game_info);