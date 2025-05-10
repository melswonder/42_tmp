/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/05/10 17:17:26 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3D.h"
# include "error.h"
# include "get_next_line.h"
# include "keycode.h"
# include "libft.h"
// # include "parse.h"
# include "minimap.h"
# include "raycast.h"
# include "render.h"
# include "utils.h"

/* main.c */
int		main(int argc, char **argv);

/* parse/parse.c */
int		parse_args(t_game_info *game_info, char **argv);
int		check_file(char *filename);
int		set_value_from_file(t_game_info *game_info, char *filename);
int		is_all_assigned(t_game_info *game_info);

/* parse/init.c */
void	init_game_info(t_game_info *game_info);
void	init_texture_img(t_cub_img *img);
void	init_map(t_map_info *map);
int		init_mlx_and_texture(t_game_info *game_info);
void	init_mlx_img(t_game_info *game_info, t_cub_img *image, int width,
			int height);
void	init_player(t_game_info *game_info);

/* parse/handle.c */
int		check_and_set_line(t_game_info *game_info, t_opcode opcode, char *line);
int		check_value_handle(char *line);

/* parse/checks.c */
bool	is_directory(char *filename);
bool	is_cub_extension(char *filename);
int		is_map_line(char *line);

/* parse/texture.c */
int		check_set_texture(t_game_info *game_info, char *line, t_opcode opcode);
int		check_set_color(t_game_info *game_info, char *line, t_opcode opcode);

/* parse/safe.c */
void	*safe_malloc(size_t bytes);

/* map/player.c */
int		detect_player_position(t_map_info *map_info);
void	set_player_dir_position(t_map_info *map_info, int x, int y);
int		is_direction_char(char c);

/* map/map_loader.c */
char	**add_line_to_map(char **map, char *line, int height);
int		check_set_map(t_game_info *game_info, char *line);
int		validate_map_line(t_map_info *map_data, char *line);

/* map/map_validator.c */
void	replace_spaces_with_walls(t_map_info *map_info);
bool	check_valid_map(t_map_info *map_info);
bool	is_map_closed(t_map_info *map_info);
char	**map_copy(t_map_info *map_info);

/* map/fllod_fill.c */
bool	check_valid_map(t_map_info *map_info);
char	**map_copy(t_map_info *map_info);
bool	floodFill(char **map, int x, int y, char target, char replace, int rows,
			int cols);
bool	isInBounds(int x, int y, int rows, int cols);

/* debug/debug.c */
void	print_game_info(t_game_info *game_info);
void	print_key_press(int keycode);

/* xpm_loader.c */
int		load_texture_from_xpm(t_game_info *game_info);

#endif
