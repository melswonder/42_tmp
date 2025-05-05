/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:28:49 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/05 21:27:37 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"
#include "../../inc/keycode.h"
#include "../../inc/render.h"

#define MAP_GREEN 0x00008000
#define MAP_WHITE 0x00FFFFFF
#define MAP_PINK 0x00FFDBED
#define MAP_RED 0x00FF0000
#define BLUE 0x000000FF

#define SPEED 5
#define BLOCK_SIZE 12 // mapのサイズを定義できます
#define MAP_SIZE 1
#define MAP_X 10
#define MAP_Y 10

#define PI 3.141592654
#define ANGLE_COUNT 360

float	cos_table[ANGLE_COUNT];
float	sin_table[ANGLE_COUNT];

void	init_trig_tables(void)
{
	int	i;

	cos_table[0] = 1.0;
	sin_table[0] = 0.0;
	cos_table[90] = 0.0;
	sin_table[90] = 1.0;
	cos_table[180] = -1.0;
	sin_table[180] = 0.0;
	cos_table[270] = 0.0;
	sin_table[270] = -1.0;
	for (i = 1; i < 90; i++)
	{
		cos_table[i] = cos_table[0] - (i / 90.0) * (cos_table[0]
				- cos_table[90]);
		sin_table[i] = sin_table[0] + (i / 90.0) * (sin_table[90]
				- sin_table[0]);
	}
	for (i = 91; i < 180; i++)
	{
		cos_table[i] = cos_table[90] - (i - 90) / 90.0 * (cos_table[90]
				- cos_table[180]);
		sin_table[i] = sin_table[90] - (i - 90) / 90.0 * (sin_table[90]
				- sin_table[180]);
	}
	for (i = 181; i < 270; i++)
	{
		cos_table[i] = cos_table[180] - (i - 180) / 90.0 * (cos_table[180]
				- cos_table[270]);
		sin_table[i] = sin_table[180] - (i - 180) / 90.0 * (sin_table[180]
				- sin_table[270]);
	}
	for (i = 271; i < 360; i++)
	{
		cos_table[i] = cos_table[270] - (i - 270) / 90.0 * (cos_table[270]
				- cos_table[0]);
		sin_table[i] = sin_table[270] - (i - 270) / 90.0 * (sin_table[270]
				- sin_table[0]);
	}
}

float	get_cos(int angle)
{
	while (angle < 0)
		angle += ANGLE_COUNT;
	angle %= ANGLE_COUNT;
	return (cos_table[angle]);
}

float	get_sin(int angle)
{
	while (angle < 0)
		angle += ANGLE_COUNT;
	angle %= ANGLE_COUNT;
	return (sin_table[angle]);
}

void	move_player(int keycode, t_player *player)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = get_cos(player->angle);
	sin_angle = get_sin(player->angle);
	if (keycode == W_KEY)
	{
		player->x += cos_angle * SPEED;
		player->y += sin_angle * SPEED;
	}
	if (keycode == S_KEY)
	{
		player->x -= cos_angle * SPEED;
		player->y -= sin_angle * SPEED;
	}
	if (keycode == A_KEY)
	{
		player->x += sin_angle * SPEED;
		player->y -= cos_angle * SPEED;
	}
	if (keycode == D_KEY)
	{
		player->x -= sin_angle * SPEED;
		player->y += cos_angle * SPEED;
	}
}

int	key_press(int keycode, void *param)
{
	t_game_info	*game_info;

	game_info = (t_game_info *)param;
	if (keycode == W_KEY)
		game_info->player->move_up = 1;
	if (keycode == S_KEY)
		game_info->player->move_down = 1;
	if (keycode == A_KEY)
		game_info->player->move_left = 1;
	if (keycode == D_KEY)
		game_info->player->move_right = 1;
	if (keycode == LEFT_KEY)
		game_info->player->rotate_left = 1;
	if (keycode == RIGHT_KEY)
		game_info->player->rotate_right = 1;
	if (keycode == ESC_KEY)
	{
		free_game_info(game_info);
		exit(0);
	}
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_game_info	*game_info;

	game_info = (t_game_info *)param;
	if (keycode == W_KEY)
		game_info->player->move_up = 0;
	if (keycode == S_KEY)
		game_info->player->move_down = 0;
	if (keycode == A_KEY)
		game_info->player->move_left = 0;
	if (keycode == D_KEY)
		game_info->player->move_right = 0;
	if (keycode == LEFT_KEY)
		game_info->player->rotate_left = 0;
	if (keycode == RIGHT_KEY)
		game_info->player->rotate_right = 0;
	return (0);
}

// イメージのピクセルに直接色を設定
void	put_pixel_to_image(t_cub_img *img, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
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

// 一つのブロックをイメージに描画
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

void	draw_player_on_minimap(t_game_info *game_info, t_cub_img *minimap)
{
	int	player_x;
	int	player_y;
	int	size;
	int	dir_length;
	int	dir_x;
	int	dir_y;

	player_x = game_info->player->x;
	player_y = game_info->player->y;
	size = 4;
	int i, j;
	for (i = -size; i <= size; i++)
	{
		for (j = -size; j <= size; j++)
		{
			if (i * i + j * j <= size * size)
				put_pixel_to_image(minimap, player_x + j, player_y + i,
					0x00FF0000);
		}
	}
	// 視線方向の矢印
	dir_length = 30;
	dir_x = player_x + dir_length * get_cos(game_info->player->angle);
	dir_y = player_y + dir_length * get_sin(game_info->player->angle);
	draw_line(minimap, player_x, player_y, dir_x, dir_y, 0x0000FF);
}

//ブレゼンハムのアルゴリズム
void	draw_line(t_cub_img *img, int x1, int y1, int x2, int y2, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		put_pixel_to_image(img, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
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

// ミニマップ全体を描画
void	draw_minimap(t_game_info *game_info)
{
	t_cub_img minimap;
	int map_width;
	int map_height;

	map_height = game_info->map_data->map_height * (BLOCK_SIZE * MAP_SIZE);
	map_width = game_info->map_data->map_width * (BLOCK_SIZE * MAP_SIZE);
	minimap.img = mlx_new_image(game_info->mlx, map_width, map_height);
	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bits_per_pixel,
			&minimap.line_length, &minimap.endian);
	minimap.width = map_width;
	minimap.height = map_height;
	draw_map_to_image(game_info, &minimap);
	draw_player_on_minimap(game_info, &minimap);
	mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, minimap.img,
		MAP_X, MAP_Y);
	mlx_destroy_image(game_info->mlx, minimap.img);
}