/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:08:16 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/10 10:46:28 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minimap.h"

void initialize_minimap(t_game_info *game_info, t_cub_img *minimap)
{
    // t_cub_img minimap;
	int map_width;
	int map_height;

	map_height = game_info->map_data->map_height * (BLOCK_SIZE * MAP_SIZE);
	map_width = game_info->map_data->map_width * (BLOCK_SIZE * MAP_SIZE);
	minimap->img = mlx_new_image(game_info->mlx, map_width, map_height);
	minimap->addr = mlx_get_data_addr(minimap->img, &minimap->bits_per_pixel,
			&minimap->line_length, &minimap->endian);
	minimap->width = map_width;
	minimap->height = map_height;
}

void	draw_minimap(t_game_info *game_info, t_cub_img *minimap)
{
	draw_map_to_image(game_info, minimap);
	draw_player_on_minimap(game_info, minimap); // playerの位置を描画する
	mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, minimap->img,
		MAP_X, MAP_Y);
	// mlx_destroy_image(game_info->mlx, minimap->img);
}

void	draw_map_to_image(t_game_info *game_info, t_cub_img *minimap)
{
	t_map_info	*map_info;
	int			x;
	int			y;

	map_info = game_info->map_data;
	y = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			draw_block(minimap, x, y, get_block_color(map_info->map[y][x]));
			x++;
		}
		y++;
	}
}

void	draw_block(t_cub_img *img, int draw_x, int draw_y, int color)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_x = draw_x * (BLOCK_SIZE * MAP_SIZE);
	start_y = draw_y * (BLOCK_SIZE * MAP_SIZE);
	y = 0;
	while (y < (BLOCK_SIZE * MAP_SIZE))
	{
		x = 0;
		while (x < (BLOCK_SIZE * MAP_SIZE))
		{
			put_pixel_to_image(img, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

// イメージのピクセルに直接色を設定
void	put_pixel_to_image(t_cub_img *img, int x, int y, int color)
{
	char	*dest;

	// if (x < 0 || y < 0 || x >= img->width || y >= img->height)
	if (x < 0 || y < 0 || x >= WIN_X || y >= WIN_Y)
		return ;
	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}


int	get_block_color(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (MAP_RED);
	else if (c == '0')
		return (MAP_PINK);
	else if (c == '1')
		return (MAP_GREEN);
	else
		return (MAP_RED);
}
