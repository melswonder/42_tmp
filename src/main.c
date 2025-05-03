/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:11:15 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 17:34:53 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/error.h"
#include "../inc/parse.h"
#include "../inc/keycode.h"

static int	exit_event(int keycode, void *param)
{
	t_game_info	*game_info;

	game_info = (t_game_info *)param;
	print_key_press(keycode);
	if (keycode == ESC_KEY)
	{
		free_game_info(game_info);
		exit(0);
	}
	return (0);
}

static int	close_window(void *param)
{
	t_game_info	*game_info;

	game_info = (t_game_info *)param;
	free_game_info(game_info);
	exit(0);
	return (0);
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
	mlx_key_hook(game_info->mlx_win, exit_event, game_info);      // ESCで抜ける
	mlx_hook(game_info->mlx_win, 17, 0, close_window, game_info); //バツボタンで抜ける　https://harm-smits.github.io/42docs/libs/minilibx/events.html
	mlx_loop(game_info->mlx);
	return (0);
}
