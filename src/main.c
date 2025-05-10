/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:11:15 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/10 16:52:41 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/error.h"
#include "../inc/keycode.h"
#include "../inc/minimap.h"
#include "../inc/parse.h"
#include "../inc/render.h"

int	game_loop(void *param)
{
	t_game_info		*game_info;
	static float	prev_x = 0;
	static float	prev_y = 0;
	static float	prev_angle = 0;

	game_info = (t_game_info *)param;
	if (had_key_press(game_info) == false)
		return (0);
	if (prev_x != game_info->player->pos_x || prev_y != game_info->player->pos_y
		|| prev_angle != game_info->player->angle)
	{
		render(game_info);
		prev_x = game_info->player->pos_x;
		prev_y = game_info->player->pos_y;
		prev_angle = game_info->player->angle;
		// draw_minimap(game_info); // マップの再描画
	}
	update_player_position(game_info); // キー状態に基づいてプレイヤー移動
	return (0);
}

int	main(int argc, char **argv)
{
	t_game_info	*game_info;

	if (argc != 2)
		return (error_msg(2, ERR_ARG_INVALID, NULL));
	game_info = safe_malloc(sizeof(t_game_info));
	init_game_info(game_info);
	if (parse_args(game_info, argv) == true)
		return (1);
	print_game_info(game_info);
	init_mlx_and_texture(game_info);
	render(game_info);
	// draw_minimap(game_info);
	mlx_hook(game_info->mlx_win, 2, 1L << 0, key_press, game_info);  
		// keyが押されたか
	mlx_hook(game_info->mlx_win, 3, 1L << 1, key_release, game_info);
		// keyが離されたか
	mlx_hook(game_info->mlx_win, 17, 0, close_window, game_info);    
		//バツボタンで抜ける　https://harm-smits.github.io/42docs/libs/minilibx/events.html
	mlx_loop_hook(game_info->mlx, game_loop, game_info);             
		// minmapの再描画、上から塗りつぶし対策
	mlx_loop(game_info->mlx);
	return (0);
}
