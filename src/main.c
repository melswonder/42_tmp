/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:11:15 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/05 21:21:55 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/error.h"
#include "../inc/keycode.h"
#include "../inc/parse.h"
#include "../inc/render.h"

#define BLOCK_SIZE 12 // mapのサイズを定義できます

void		update_player_position(t_game_info *game_info);
int			is_valid_position(t_game_info *game_info, float x, float y);

int	game_loop(void *param)
{
	t_game_info	*game_info;

	game_info = (t_game_info *)param;
	// キー状態に基づいてプレイヤー移動
	update_player_position(game_info);
	// マップの再描画
	draw_minimap(game_info);
	return (0);
}

// プレイヤー位置の更新
void	update_player_position(t_game_info *game_info)
{
	float	cos_val;
	float	sin_val;
	float	new_x;
	float	new_y;
	float	temp_x;
	float	temp_y;

	static int rotate_counter = 0; //曲がりすぎないように
	float speed = 0.05;            // 移動速度（滑らかさのために調整）
	cos_val = get_cos(game_info->player->angle);
	sin_val = get_sin(game_info->player->angle);
	new_x = game_info->player->x;
	new_y = game_info->player->y;
	// 移動方向の計算
	if (game_info->player->move_up)
	{
		temp_x = new_x + cos_val * speed;
		temp_y = new_y + sin_val * speed;
		if (is_valid_position(game_info, temp_x, new_y))
			new_x = temp_x;
		if (is_valid_position(game_info, new_x, temp_y))
			new_y = temp_y;
	}
	if (game_info->player->move_down)
	{
		temp_x = new_x - cos_val * speed;
		temp_y = new_y - sin_val * speed;
		if (is_valid_position(game_info, temp_x, new_y))
			new_x = temp_x;
		if (is_valid_position(game_info, new_x, temp_y))
			new_y = temp_y;
	}
	if (game_info->player->move_left)
	{
		temp_x = new_x - sin_val * speed;
		temp_y = new_y + cos_val * speed;
		if (is_valid_position(game_info, temp_x, new_y))
			new_x = temp_x;
		if (is_valid_position(game_info, new_x, temp_y))
			new_y = temp_y;
	}
	if (game_info->player->move_right)
	{
		temp_x = new_x + sin_val * speed;
		temp_y = new_y - cos_val * speed;
		if (is_valid_position(game_info, temp_x, new_y))
			new_x = temp_x;
		if (is_valid_position(game_info, new_x, temp_y))
			new_y = temp_y;
	}
	if (game_info->player->rotate_left || game_info->player->rotate_right)
	{
		rotate_counter++;
		if (rotate_counter >= 5)
		{
			if (game_info->player->rotate_left)
				game_info->player->angle = (game_info->player->angle - 1 + 360)
					% 360;
			if (game_info->player->rotate_right)
				game_info->player->angle = (game_info->player->angle + 1) % 360;
			rotate_counter = 0;
		}
	}
	game_info->player->x = new_x;
	game_info->player->y = new_y;
}

// 位置の有効性チェック
int	is_valid_position(t_game_info *game_info, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = x / BLOCK_SIZE;
	map_y = y / BLOCK_SIZE;
	// マップ範囲外チェック
	if (map_x < 0 || map_y < 0 || map_x >= game_info->map_data->map_width
		|| map_y >= game_info->map_data->map_height)
		return (0);
	// 壁衝突チェック
	if (game_info->map_data->map[map_y][map_x] == '1')
		return (0);
	return (1);
}

static void	init_player_dir(t_game_info *game_info)
{
	if (game_info->map_data->dir == NORTH)
		game_info->player->angle = 0;
	if (game_info->map_data->dir == SOUTH)
		game_info->player->angle = 180;
	if (game_info->map_data->dir == WEST)
		game_info->player->angle = 90;
	if (game_info->map_data->dir == EAST)
		game_info->player->angle = 270;
	game_info->player->move_up = 0;
	game_info->player->move_down = 0;
	game_info->player->move_left = 0;
	game_info->player->move_right = 0;
	game_info->player->rotate_left = 0;
	game_info->player->rotate_right = 0;
	game_info->player->x = game_info->map_data->player_start_x * BLOCK_SIZE;
	game_info->player->y = game_info->map_data->player_start_y * BLOCK_SIZE;
}

int	main(int argc, char **argv)
{
	t_game_info	*game_info;

	if (argc != 2)
		return (error_msg(2, ERR_ARG_MISSING, NULL));
	game_info = safe_malloc(sizeof(t_game_info));
	init_game_info(game_info);
	if (parse_args(game_info, argv) == true)
		return (1);
	print_game_info(game_info);
	init_mlx_and_texture(game_info);
	init_trig_tables();
	init_player_dir(game_info);
	render(game_info);
	mlx_hook(game_info->mlx_win, 2, 1L << 0, key_press, game_info);   // key
	mlx_hook(game_info->mlx_win, 3, 1L << 1, key_release, game_info); // key
	mlx_hook(game_info->mlx_win, 17, 0, close_window, game_info);
	//バツボタンで抜ける　https://harm-smits.github.io/42docs/libs/minilibx/events.html
	mlx_loop_hook(game_info->mlx, game_loop, game_info);
	mlx_loop(game_info->mlx);
	return (0);
}
