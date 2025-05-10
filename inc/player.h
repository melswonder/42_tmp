/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:12:55 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/07 23:27:40 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3D.h"
# include "error.h"
# include "get_next_line.h"
# include "keycode.h"
# include "libft.h"
# include "minimap.h"
# include "parse.h"
# include "raycast.h"
# include "render.h"
# include "utils.h"
// # include "player.h"

// /* move_player/player_possion.c */
void	update_player_position(t_game_info *game_info);
int		is_valid_position(t_game_info *game_info, float x, float y);

// /* move_player/player_ray.c */
void	draw_player_ray(t_game_info *game_info, t_cub_img *minimap);
void	draw_line(t_cub_img *img, int x1, int y1, int x2, int y2, int color);

// /* move_player/key.c */
bool	had_key_press(t_game_info *game_info);

#endif
