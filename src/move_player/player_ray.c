/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:11:33 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/07 23:27:46 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minimap.h"
#include <math.h>

void	draw_player_ray(t_game_info *game_info, t_cub_img *minimap)
{
    int		player_x;
    int		player_y;
    int		dir_length;
    int		dir_x;
    int		dir_y;
    float	angle_rad;

    player_x = game_info->player->minimap_player_x;
    player_y = game_info->player->minimap_player_y;
    dir_length = 30;
    
    // 角度をラジアンに変換（update_player_positionと同じ処理）
    angle_rad = game_info->player->angle * M_PI / 180.0;
    
    dir_x = player_x + dir_length * cos(angle_rad);
    dir_y = player_y - dir_length * sin(angle_rad);
 
    draw_line(minimap, player_x, player_y, dir_x, dir_y, BLUE);
}

//ブレゼンハムのアルゴリズム
//与えられた始点と終点の間に連続した点を置き、近似的な直線を引くためのアルゴリズム
void	draw_line(t_cub_img *img, int x1, int y1, int x2, int y2, int color)
{
	// X方向とY方向の距離
	int delta_x = abs(x2 - x1);
	int delta_y = abs(y2 - y1);
	// X方向とY方向の移動方向（+1または-1）
	int step_x = (x1 < x2) ? 1 : -1;
	int step_y = (y1 < y2) ? 1 : -1;
	// 誤差変数（これにより、どちらの軸を優先して移動するか)
	float error = delta_x - delta_y;
	while (1)
	{
		// 現在位置にピクセルを描画
		put_pixel_to_image(img, x1, y1, color);

		// 終点に到達したら終了
		if (x1 == x2 && y1 == y2)
			break ;

		// 誤差の2倍を計算（計算を簡略化するため）
		float error_2 = 2 * error;

		// X軸方向に進むべきか判断
		if (error_2 > -delta_y)
		{
			error -= delta_y; // 誤差を更新
			x1 += step_x;     // X座標を進める
		}

		// Y軸方向に進むべきか判断
		if (error_2 < delta_x)
		{
			error += delta_x; // 誤差を更新
			y1 += step_y;     // Y座標を進める
		}
	}
}