/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:59:12 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/10 11:56:18 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

void	init_game_info(t_game_info *game_info)
{
	game_info->north_texture = safe_malloc(sizeof(t_cub_img));
	game_info->south_texture = safe_malloc(sizeof(t_cub_img));
	game_info->west_texture = safe_malloc(sizeof(t_cub_img));
	game_info->east_texture = safe_malloc(sizeof(t_cub_img));
	game_info->map_data = safe_malloc(sizeof(t_map_info));
	init_texture_img(game_info->north_texture);
	init_texture_img(game_info->south_texture);
	init_texture_img(game_info->west_texture);
	init_texture_img(game_info->east_texture);
	game_info->floor_color[0] = 0;
	game_info->floor_color[1] = 0;
	game_info->floor_color[2] = 0;
	game_info->ceiling_color[0] = 0;
	game_info->ceiling_color[1] = 0;
	game_info->ceiling_color[2] = 0;
	init_map(game_info->map_data);
	game_info->mlx = NULL;
	game_info->mlx_win = NULL;
	game_info->player = safe_malloc(sizeof(t_player));
}

// init texture img ? のほうが良い？
// NULL初期化でなく、mlx関数を用いたinitializationも必要となる
void	init_texture_img(t_cub_img *image)
{
	image->name = NULL;
	image->img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
	image->width = 0;
	image->height = 0;
}

void	init_map(t_map_info *map)
{
	map->map = NULL;
	map->map_width = 0;
	map->map_height = 0;
	map->dir = NOTHING;
	map->player_start_x = 0;
	map->player_start_y = 0;
}

/*
** void	*mlx_new_image(void *mlx_ptr,int width,int height);
** Create a new MLX compatible image.
**
** @param	void *mlx_ptr	the mlx instance pointer;
** @param	int  width		the width of the image to be created;
** @param	int  height		the height of the image to be created;
** @return	void*			the image instance reference.
*/
void	init_mlx_img(t_game_info *game_info, t_cub_img *image, int width,
		int height)
{
	image->img = mlx_new_image(game_info->mlx, width, height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	return ;
}

/*
1. initialize mlx (not with null but with mlx functions)
2. initialize texture img as mlx img type for minilibx (with mlx funtions)
*/
int	init_mlx_and_texture(t_game_info *game_info)
{
	// initialize mlx (not with null but with mlx functions)
	game_info->mlx = mlx_init();
	game_info->mlx_win = mlx_new_window(game_info->mlx, WIN_X, WIN_Y, "cub3D");
	// initialize texture img as mlx img type for minilibx
	load_texture_from_xpm(game_info);
	return (0);
}

void	init_player(t_game_info *game_info)
{
	double angle_rad;
	if (game_info->map_data->dir == NORTH)//数学座標に合わせました
		game_info->player->angle = 90;
	if (game_info->map_data->dir == SOUTH)
		game_info->player->angle = 270;
	if (game_info->map_data->dir == WEST)
		game_info->player->angle = 180;
	if (game_info->map_data->dir == EAST)
		game_info->player->angle = 0;

	game_info->player->pos_x = game_info->map_data->player_start_x;
	game_info->player->pos_y = game_info->map_data->player_start_y;
	angle_rad = game_info->player->angle * M_PI / 180.0;
	game_info->player->dir_x = cos(angle_rad);
	game_info->player->dir_y = sin(angle_rad);
	printf("dir x %f dir y %f\n", game_info->player->dir_x, game_info->player->dir_y);
	game_info->player->plane_x = - game_info->player->dir_y * FOV_SCALE;
	game_info->player->plane_y = game_info->player->dir_x * FOV_SCALE;

	game_info->player->move_up = false;
	game_info->player->move_down = false;
	game_info->player->move_left = false;
	game_info->player->move_right = false;
	game_info->player->rotate_left = false;
	game_info->player->rotate_right = false;
	game_info->player->minimap_player_x = game_info->map_data->player_start_x;
	game_info->player->minimap_player_y = game_info->map_data->player_start_y;
}
//pos_x pos_yを基準にminimapを修正する