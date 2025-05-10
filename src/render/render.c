/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:28:38 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/05/10 10:46:19 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

// static void	test_plot(t_cub_img *image)
// {
// 	int	i;

// 	i = 0;
// 	while (++i < 100)
// 	{
// 		ft_mlx_putpixel(image, i, i, 0x0000FF00);
// 	}
// }

int	draw_ceiling_and_floor(t_game_info *game_info, t_cub_img *image)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!game_info)
		return (-1);
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			if (x > 400 || y > 400)
				ft_mlx_putpixel(image, x, y, 0x0000FF00);
			if (y > WIN_Y / 2)
				ft_mlx_putpixel(image, x, y, 0x0000FFFF);
			else if (y <= WIN_Y / 2)
				ft_mlx_putpixel(image, x, y, 0x00008888);
			x++;
		}
		y++;
	}
	return (0);
}



int draw_main_window(t_game_info *game_info, t_cub_img *image)
{
	// init_texture_img(image);
	// init_mlx_img(game_info, image, WIN_X, WIN_Y);

	draw_ceiling_and_floor(game_info, image);

	//スタート時の真正面にRayを飛ばす
	// shoot_single_ray(game_info, 0, 1);
	// shoot_single_ray(game_info, sqrt(2)/2, sqrt(2)/2);

	// 複数のrayを飛ばす
	shoot_multiple_rays(game_info, image);

	// -----------------
	mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, image->img, 0, 0);
	return 0;
}

int	render(t_game_info *game_info)
{
	if (!game_info)
		return (EXIT_FAILURE);

	t_cub_img main_image;
	t_cub_img minimap_image;

	// initialize main_image
	init_texture_img(&main_image);
	init_mlx_img(game_info, &main_image, WIN_X, WIN_Y);

	// initialize_minimap;
	initialize_minimap(game_info, &minimap_image);

	// draw
	draw_main_window(game_info, &main_image);
	draw_minimap(game_info, &minimap_image); // マップの再描画

	// destroy image
	mlx_destroy_image(game_info->mlx, main_image.img);
	mlx_destroy_image(game_info->mlx, minimap_image.img);
	
	return (0);
}
