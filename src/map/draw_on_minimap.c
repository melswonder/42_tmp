/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:11:42 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/07 23:47:57 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minimap.h"

// minimapにプレイヤーを表示させる
void	draw_player_on_minimap(t_game_info *game_info, t_cub_img *minimap)
{
	int	player_x;
	int	player_y;
	int	size;

	game_info->player->minimap_player_x = game_info->player->pos_x * BLOCK_SIZE;
	game_info->player->minimap_player_y = game_info->player->pos_y * BLOCK_SIZE;
	player_x = game_info->player->minimap_player_x;
	player_y = game_info->player->minimap_player_y;
	size = 4; // playerのサイズ
	int i, j;
	for (i = -size; i <= size; i++)
	{
		for (j = -size; j <= size; j++)
		{
			if (i * i + j * j <= size * size)
				put_pixel_to_image(minimap, player_x + j, player_y + i,
					0x00FF0000);
		}
	}
	draw_player_ray(game_info, minimap);
}

void	draw_rays_on_minimap(t_game_info *game_info, t_ray *ray)
{
	float	px;
	float	py;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;

	px = game_info->player->pos_x;
	py = game_info->player->pos_y;
	// float hit_x = px + ray->dir_x * ray->distance_to_wall_perp;
	// float hit_y = py + ray->dir_y * ray->distance_to_wall_perp;
	start_x = (int)(px * BLOCK_SIZE);
	start_y = (int)(py * BLOCK_SIZE);
	end_x = (int)(px + ray->dir_x * ray->distance_to_wall_perp * BLOCK_SIZE);
	end_y = (int)(px + ray->dir_x * ray->distance_to_wall_perp * BLOCK_SIZE);
	// draw_line(game_info->minimap, start_x, start_y, end_x, end_y, 0xFFFFDD);
}
