/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:37:40 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/06 16:52:38 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/player.h"

bool	had_key_press(t_game_info *game_info)
{
	t_player *player;

	player = game_info->player;
	if (player->move_up || player->move_down || player->move_left
		|| player->move_right || player->rotate_left || player->rotate_right)
		return (true);
	return (false);
}

int	key_press(int keycode, void *param)
{
	t_game_info	*game_info;

	game_info = (t_game_info *)param;
	if (keycode == W_KEY)
		game_info->player->move_up = true;
	if (keycode == S_KEY)
		game_info->player->move_down = true;
	if (keycode == A_KEY)
		game_info->player->move_left = true;
	if (keycode == D_KEY)
		game_info->player->move_right = true;
	if (keycode == LEFT_KEY)
		game_info->player->rotate_left = true;
	if (keycode == RIGHT_KEY)
		game_info->player->rotate_right = true;
	if (keycode == ESC_KEY)
	{
		free_game_info(game_info);
		exit(0);
	}
	print_key_press(keycode);
	return (had_key_press(game_info));
}

int	key_release(int keycode, void *param)
{
	t_game_info	*game_info;

	game_info = (t_game_info *)param;
	if (keycode == W_KEY)
		game_info->player->move_up = false;
	if (keycode == S_KEY)
		game_info->player->move_down = false;
	if (keycode == A_KEY)
		game_info->player->move_left = false;
	if (keycode == D_KEY)
		game_info->player->move_right = false;
	if (keycode == LEFT_KEY)
		game_info->player->rotate_left = false;
	if (keycode == RIGHT_KEY)
		game_info->player->rotate_right = false;
	return (0);
}
