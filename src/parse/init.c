/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:59:12 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 15:36:18 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

void	init_game_info(t_game_info *game_info)
{
	game_info->north_texture = safe_malloc(sizeof(t_texture_img));
	game_info->south_texture = safe_malloc(sizeof(t_texture_img));
	game_info->west_texture = safe_malloc(sizeof(t_texture_img));
	game_info->east_texture = safe_malloc(sizeof(t_texture_img));
	game_info->map_data = safe_malloc(sizeof(t_map_info));
	init_img(game_info->north_texture);
	init_img(game_info->south_texture);
	init_img(game_info->west_texture);
	init_img(game_info->east_texture);
	game_info->floor_color[0] = 0;
	game_info->floor_color[1] = 0;
	game_info->floor_color[2] = 0;
	game_info->ceiling_color[0] = 0;
	game_info->ceiling_color[1] = 0;
	game_info->ceiling_color[2] = 0;
	init_map(game_info->map_data);
	game_info->mlx = NULL;
	game_info->mlx_win = NULL;
}

void	init_img(t_texture_img *img)
{
	img->name = NULL;
	img->img = NULL;
	img->width = 0;
	img->height = 0;
}

void	init_map(t_map_info *map)
{
	map->map = NULL;
	map->map_width = 0;
	map->map_height = 0;
	map->dir = NOTHING;
	map->player_start_x = 0;
	map->player_start_y = 0;
}
