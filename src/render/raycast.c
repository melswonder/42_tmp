/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:28:38 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/05/07 23:54:03 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

// int	shoot_single_ray(t_game_info *game_info, float ray_dir_x, float ray_dir_y)
// {
// 	t_ray	ray;

// 	init_ray(&ray);
// 	// set which box
// 	ray.map_x = game_info->player->pos_x;
// 	ray.map_y = game_info->player->pos_y;
// 	// length of ray from current position to next x or y-side
// 	// length of ray from one x or y-side to next x or y-side
// 	ray.delta_dist_x = fabs(1 / ray_dir_x);
// 	ray.delta_dist_y = fabs(1 / ray_dir_y);
// 	ray.dir_x = ray_dir_x;
// 	ray.dir_y = ray_dir_y;
// 	// Calculate_step and initial sideDist
// 	if (ray.dir_x < 0)
// 	{
// 		ray.step_x = -1;
// 		ray.side_dist_x = (game_info->player->pos_x - ray.map_x)
// 			* ray.delta_dist_x;
// 	}
// 	else if (ray.dir_x >= 0)
// 	{
// 		ray.step_x = 1;
// 		ray.side_dist_x = (ray.map_x + 1 - game_info->player->pos_x)
// 			* ray.delta_dist_x;
// 	}
// 	if (ray.dir_y < 0)
// 	{
// 		ray.step_y = 1;
// 		ray.side_dist_y = (game_info->player->pos_y - ray.map_y)
// 			* ray.delta_dist_y;
// 	}
// 	else if (ray.dir_y >= 0)
// 	{
// 		ray.step_y = -1;
// 		ray.side_dist_y = (ray.map_y + 1 - game_info->player->pos_y)
// 			* ray.delta_dist_y;
// 	}
// 	printf("step_x: %d, step_y: %d\n", ray.step_x, ray.step_y);
// 	printf("sideDistX:%f, sideDistY:%f\n", ray.side_dist_x, ray.side_dist_y);
// 	printf("dir_x:%f, dir_y:%f\n", ray.dir_x, ray.dir_y);
// 	// perform_DDA
// 	while (game_info->map_data->map[ray.map_x][ray.map_y] != '1')
// 	{
// 		printf("Current ray position: (%d, %d)\n", ray.map_x, ray.map_y);
// 		// jump to square in x-direction or y-direction
// 		if (ray.side_dist_x < ray.side_dist_y)
// 		{
// 			ray.side_dist_x += ray.delta_dist_x;
// 			ray.map_x += ray.step_x;
// 			ray.side = HORIZONTAL_SIDE;
// 		}
// 		else if (ray.side_dist_x >= ray.side_dist_y)
// 		{
// 			ray.side_dist_y += ray.delta_dist_y;
// 			ray.map_y += ray.step_y;
// 			ray.side = VERTICAL_SIDE;
// 		}
// 	}
// 	printf("Ray hit wall at map cell: (%d, %d)\n", ray.map_x, ray.map_y);
// 	return (0);
// }

// ======================
// ===Ray cast by DDA ===
// ======================
t_ray	shoot_single_ray(t_game_info *game_info, float ray_dir_x, float ray_dir_y)
{
	t_ray	ray;

	init_ray(&ray);
	set_ray_for_dda(game_info, &ray, ray_dir_x, ray_dir_y);
	calculate_ray_for_dda(game_info, &ray);
	do_dda(game_info, &ray);
	get_distance_to_wall_full(game_info, &ray);
	get_distance_to_wall_perp(game_info, &ray);
	return ray;
}

/*
関数名は検討中
draw_wall にして、その中に、rayを複数出させるのかdraw_wall はテキスチャのセットなどに撮っておくか
draw wall 
{
 for (int i=0 ; i < WIN_X ; i++)
	shoot_single_ray(game_info, 角度か位置をiずらす)
	2-3 draw wall(←rayの中に、wallへのdistanceをもっておく。それをもとに計算)
	2-4 壁の衝突面の判定に応じて色を加える　（今すでに壁のXかYかはわかるので、dir_x, dir_yもつかって、NSWEを判定）
	2-6 視覚角の補正も入れる
}
*/

int shoot_multiple_rays(t_game_info *game_info, t_cub_img *image)
{
	int x;
	float camera_x;
	float ray_dir_x;
	float ray_dir_y;
	t_ray ray;

	x = 0;
	ray_dir_x = 0;
	ray_dir_y = 0;
	while (++x < WIN_X)
	{
		camera_x = 2 * x / (float)WIN_X - 1;
		ray_dir_x = game_info->player->dir_x + game_info->player->plane_x * camera_x;
		ray_dir_x = game_info->player->dir_y + game_info->player->plane_y * camera_x;
		ray = shoot_single_ray(game_info, ray_dir_x, ray_dir_y);
		// draw_rays_on_minimap(game_info, &ray);
		draw_wall_line(image, &ray, x);
	}
	// shoot_single_ray()
	// Calculate wall height and draw
	return(0);
}

// delta dist
// delta_dist_x = sqrt (1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x))
void	set_ray_for_dda(t_game_info *game_info, t_ray *ray, float ray_dir_x, float ray_dir_y)
{
	init_ray(ray);
	ray->dir_x = ray_dir_x;
	ray->dir_y = ray_dir_y;
	ray->map_x = game_info->player->pos_x;
	ray->map_y = game_info->player->pos_y;
	ray->delta_dist_x = fabs(1 / ray_dir_x); 
	ray->delta_dist_y = fabs(1 / ray_dir_y);
}

void	calculate_ray_for_dda(t_game_info *game_info, t_ray *ray)
{
	// Calculate_step and initial sideDist
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game_info->player->pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else if (ray->dir_x >= 0)
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - game_info->player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = 1;
		ray->side_dist_y = (game_info->player->pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else if (ray->dir_y >= 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->map_y + 1 - game_info->player->pos_y)
			* ray->delta_dist_y;
	}
	// printf("step_x: %d, step_y: %d\n", ray->step_x, ray->step_y);
	// printf("sideDistX:%f, sideDistY:%f\n", ray->side_dist_x, ray->side_dist_y);
	// printf("dir_x:%f, dir_y:%f\n", ray->dir_x, ray->dir_y);
}

// Digital Differential Analyzer
int	do_dda(t_game_info *game_info, t_ray *ray)
{
	if (!game_info || !game_info->map_data || !game_info->map_data->map || !ray)
		return (EXIT_FAILURE);
	while (game_info->map_data->map[ray->map_x][ray->map_y] != '1')
	{
		// printf("Current ray (%d, %d)\n", ray->map_x, ray->map_y);
		// jump to square in x-direction or y-direction
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->collision_side = HORIZONTAL_SIDE;
		}
		else if (ray->side_dist_x >= ray->side_dist_y)
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->collision_side = VERTICAL_SIDE;
		}
	}
	// printf("Ray hit wall at map cell: (%d, %d)\n", ray->map_x, ray->map_y);
	return 0;
}

// full distance
void 	get_distance_to_wall_full(t_game_info *game_info, t_ray *ray)
{
	if (!game_info)
		return ;
	if (ray->collision_side == HORIZONTAL_SIDE)
    	ray->distance_to_wall_full = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->distance_to_wall_full = ray->side_dist_y - ray->delta_dist_y;
	// printf("distance to wall full: %f\n" , ray->distance_to_wall_full);
}

// perpendicular distance
void 	get_distance_to_wall_perp(t_game_info *game_info, t_ray *ray)
{
	if (ray->collision_side == HORIZONTAL_SIDE)
    	ray->distance_to_wall_perp = (ray->map_x - game_info->player->pos_x + (1 - ray->step_x) / 2) / ray->dir_x;
	else
    	ray->distance_to_wall_perp = (ray->map_y - game_info->player->pos_y + (1 - ray->step_y) / 2) / ray->dir_y;
	// printf("distance to wall perp: %f\n" , ray->distance_to_wall_perp);
}
