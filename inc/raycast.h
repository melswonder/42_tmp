/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:00:47 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/05/07 23:51:26 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3D.h"
# include "error.h"
# include "get_next_line.h"
# include "keycode.h"
# include "libft.h"
# include "minimap.h"
# include "parse.h"
// # include "raycast.h"
# include "player.h"
# include "render.h"
# include "utils.h"

/* init_ray.c */
void	init_ray(t_ray *ray);

/* shoot_ray.c */
t_ray	shoot_single_ray(t_game_info *game_info, float ray_dir_x, float ray_dir_y);
int 	shoot_multiple_rays(t_game_info *game_info, t_cub_img *image);
void	set_ray_for_dda(t_game_info *game_info, t_ray *ray, float ray_dir_x, float ray_dir_y);
void	calculate_ray_for_dda(t_game_info *game_info, t_ray *ray);
int		do_dda(t_game_info *game_info, t_ray *ray);
void 	get_distance_to_wall_full(t_game_info *game_info, t_ray *ray);
void 	get_distance_to_wall_perp(t_game_info *game_info, t_ray *ray);


void	draw_wall_line(t_cub_img *image,  t_ray *ray, int x);


#endif
