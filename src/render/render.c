/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:28:38 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/05/04 20:50:11 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void test_plot(t_cub_img *image)
{
	int i;
	i =0;
	while (++i < 100)
	{
		ft_mlx_putpixel(image, i, i, 0x0000FF00);
	}
}

int render(t_game_info *game_info)
{
	if (!game_info)
		return EXIT_FAILURE;

	t_cub_img image;
	init_texture_img(&image);
	init_mlx_img(game_info, &image, WIN_X, WIN_Y);

	// -----------------
	int x;
	int y;

	x = 0;
	y = 0;

	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			if (x > 400 || y > 400)
				ft_mlx_putpixel(&image, x, y, 0x0000FF00);
			if (y > WIN_Y / 2)
				ft_mlx_putpixel(&image, x, y, 0x0000FFFF);
			else if (y <= WIN_Y / 2)
				ft_mlx_putpixel(&image, x, y, 0x00008888);
			x++;
		}
		y++;
	}
	test_plot(&image);

	// -----------------
	mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, image.img, 0, 0);
	mlx_destroy_image(game_info->mlx, image.img);

	return 0;
}