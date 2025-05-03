/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:00:47 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 17:38:30 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"
#include <stdlib.h>

#define WIN_X 1200
#define WIN_Y 800

#define IMG_WIDTH 64
#define IMG_HEIGHT 64

/* main.c */
int		main(int argc, char **argv);

/* parse/parse.c */
int		parse_args(t_game_info *game_info, char **argv);
int		check_file(char *filename);
void	set_value_from_file(t_game_info *game_info, char *filename);

/* parse/init.c */
void	init_game_info(t_game_info *game_info);
void	init_img(t_texture_img *img);
void	init_map(t_map_info *map);

/* parse/free.c */
void	free_game_info_no_mlx(t_game_info *game_info);
void	free_game_info(t_game_info *game_info);
void	free_map(t_map_info *map_info);
void	free_mlx_img(void *mlx, t_texture_img *img);

/* parse/handle.c */
void	set_info_handle(t_game_info *game_info, t_opcode opcode, char *line);
int		check_value_handle(char *line);

/* parse/checks.c */
bool	is_directory(char *filename);
bool	is_cub_extension(char *filename);
int		is_map_line(char *line);

/* parse/texture.c */
int		set_texture(t_game_info *game_info, char *line, t_opcode opcode);
void	set_colore(t_game_info *game_info, char *line, t_opcode opcode);

/* parse/safe.c */
void	*safe_malloc(size_t bytes);

/* map/player.c */
void	detect_player_position(t_map_info *map_info);
void	set_player_dir_position(t_map_info *map_info, int x, int y);
int		is_direction_char(char c);

/* map/map_loader.c */
char	**add_line_to_map(char **map, char *line, int height);
void	set_map(t_game_info *game_info, char *line);
void	validate_map_line(t_map_info *map_data, char *line);

/* map/map_validator.c */
void	replace_spaces_with_walls(t_map_info *map_info);
bool	validate_map_boundaries(t_map_info *map_info);
bool	is_map_enclosed(t_map_info *map_info);

/* util.c */
void	error_exit(int fd, char *msg);
int		error_msg(int fd, char *msg, char *arg);

/* debug/debug.c */
void	print_game_info(t_game_info *game_info);
void	print_key_press(int keycode);

/* xpm_loader.c */
int		load_texture_from_xpm(t_game_info *game_info);
