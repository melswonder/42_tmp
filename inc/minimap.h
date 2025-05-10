/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:08:42 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/10 10:44:01 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3D.h"
# include "error.h"
# include "get_next_line.h"
# include "keycode.h"
# include "libft.h"
# include "parse.h"
# include "raycast.h"
# include "render.h"
# include "utils.h"
// # include "minimap.h"
# include "player.h"

# define MAP_GREEN 0x00008000 // 0x00008000だと半透明になるらしいがlinuxだとできない
# define MAP_WHITE 0x00FFFFFF
# define MAP_PINK 0x00FFDBED
# define MAP_RED 0x00FF0000
# define BLUE 0x000000FF

# define SPEED 5       // minimapのplayerの移動速度
# define BLOCK_SIZE 12 // mapnのブロックサイズ
# define MAP_SIZE 1    // minimapのサイズ
# define MAP_X 10      // minimapのX座標
# define MAP_Y 10      // minimapのY座標
// # define M_PI 3.14159265

// /* map/minimap.c */
void initialize_minimap(t_game_info *game_info, t_cub_img *minimap);
void	draw_minimap(t_game_info *game_info, t_cub_img *minimap);
// void	draw_minimap(t_game_info *game_info);
void	draw_map_to_image(t_game_info *game_info, t_cub_img *minimap);
void	draw_block(t_cub_img *img, int draw_x, int draw_y, int color);
int		get_block_color(char c);
void	put_pixel_to_image(t_cub_img *img, int x, int y, int color);
void	draw_player_on_minimap(t_game_info *game_info, t_cub_img *minimap);
void	draw_rays_on_minimap(t_game_info *game_info, t_ray *ray);

#endif
