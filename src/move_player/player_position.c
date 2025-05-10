/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:07:59 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/10 11:57:03 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minimap.h"
#include <math.h>
#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

void	update_player_position(t_game_info *game_info)
{
	float		new_x;
	float		new_y;
	float		temp_x;
	float		temp_y;
	float		angle_rad;
	static int	angle_count = 0;

	float speed = 0.005; // minimapのプレイヤーの移動速度
	new_x = game_info->player->pos_x;
	new_y = game_info->player->pos_y;
	if (game_info->player->move_up)
	{
		temp_x = new_x + game_info->player->dir_x * speed;
		temp_y = new_y - game_info->player->dir_y * speed;
		if (is_valid_position(game_info, temp_x, new_y))
			new_x = temp_x;
		if (is_valid_position(game_info, new_x, temp_y))
			new_y = temp_y;
	}
	if (game_info->player->move_down)
	{
		temp_x = new_x - game_info->player->dir_x * speed;
		temp_y = new_y + game_info->player->dir_y * speed;
		if (is_valid_position(game_info, temp_x, new_y))
			new_x = temp_x;
		if (is_valid_position(game_info, new_x, temp_y))
			new_y = temp_y;
	}
	if (game_info->player->move_left) //左　現在の角度に+90度（π/2ラジアン）した方向に移動
	{
		temp_x = new_x - game_info->player->dir_y * speed;
		temp_y = new_y - game_info->player->dir_x * speed;
		if (is_valid_position(game_info, temp_x, new_y))
			new_x = temp_x;
		if (is_valid_position(game_info, new_x, temp_y))
			new_y = temp_y;
	}
	if (game_info->player->move_right)
	{
		temp_x = new_x + game_info->player->dir_y * speed;
		temp_y = new_y + game_info->player->dir_x * speed;
		if (is_valid_position(game_info, temp_x, new_y))
			new_x = temp_x;
		if (is_valid_position(game_info, new_x, temp_y))
			new_y = temp_y;
	}
	if (game_info->player->rotate_left || game_info->player->rotate_right)
	{
		if (angle_count == 20)
		{
			if (game_info->player->rotate_left)
			{
				game_info->player->angle += 1.0;
				if (game_info->player->angle >= 360)
					game_info->player->angle -= 360;
			}
			if (game_info->player->rotate_right)
			{
				game_info->player->angle -= 1.0;
				if (game_info->player->angle < 0)
					game_info->player->angle += 360;
			}
			angle_rad = game_info->player->angle * M_PI / 180.0;
			game_info->player->dir_x = cos(angle_rad);
			game_info->player->dir_y = sin(angle_rad);
			game_info->player->plane_x = -game_info->player->dir_y * FOV_SCALE;
			game_info->player->plane_y = game_info->player->dir_x * FOV_SCALE;
			angle_count = 0;
		}
		angle_count++;
	}
	game_info->player->pos_x = new_x;
	game_info->player->pos_y = new_y;
	printf("x=%f,y=%f, angle=%f\n", game_info->player->pos_x, game_info->player->pos_y, game_info->player->angle);
}

int	is_valid_position(t_game_info *game_info, float x, float y) //衝突判定をpos_x yをに修正する
{
	int	map_x;
	int	map_y;

	map_x = x;
	map_y = y;
	// minimapのサイズに揃える
	if (map_x < 0 || map_y < 0 || map_x >= game_info->map_data->map_width
		|| map_y >= game_info->map_data->map_height) // マップ範囲外チェック
		return (0);
	if (game_info->map_data->map[map_y][map_x] == '1') // 壁衝突チェック
		return (0);
	return (1);
}
