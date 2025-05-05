/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:29:07 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/05/05 20:39:59 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3D.h"
# include "error.h"
# include "get_next_line.h"
# include "keycode.h"
# include "libft.h"
# include "raycast.h"
// # include "render.h"
# include "parse.h"
# include "utils.h"

// /* render.c */
int		render(t_game_info *game_info);

/* src/map/minimap.c*/
void init_trig_tables(void);
float	get_cos(int angle);
float	get_sin(int angle);
void	move_player(int keycode, t_player *player);
int	key_press(int keycode, void *param);
int key_release(int keycode, void *param);
void	put_pixel_to_image(t_cub_img *img, int x, int y, int color);
void	draw_map_to_image(t_game_info *game_info, t_cub_img *minimap);
void	draw_block(t_cub_img *img, int draw_x, int draw_y, int color);
void draw_player_on_minimap(t_game_info *game_info, t_cub_img *minimap);
void draw_line(t_cub_img *img, int x1, int y1, int x2, int y2, int color);
int	get_block_color(char c);
void	draw_minimap(t_game_info *game_info);



#endif
