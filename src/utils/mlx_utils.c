/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:35:00 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/05/04 19:22:18 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"
#include "../inc/utils.h"

int	exit_event(int keycode, void *param)
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

int	close_window(void *param)
{
	t_game_info	*game_info;

	game_info = (t_game_info *)param;
	free_game_info(game_info);
	exit(0);
	return (0);
}

void	ft_mlx_putpixel(t_cub_img *image, int x, int y, int color)
{
	char	*pixel;

	if (!image || !image->line_length || !image->bits_per_pixel)
	{
		printf("Either addr, line_length, bits per pixel is null\n");
		return ;
	}
	pixel = NULL;
	if (0 <= x && x < WIN_X && 0 <= y && y <= WIN_Y)
		pixel = image->addr + (y * image->line_length + (x * image->bits_per_pixel
					/ 8));
	*(unsigned int *)pixel = color;
}
