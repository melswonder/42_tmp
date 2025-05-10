/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:28:38 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/05/07 20:21:45 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
/*
typedef struct s_ray
{
	// Horizontal position on the screen, from -1.0 (left) to 1.0 (right)
	float		camera_x;

	// The current grid cell (map square) the ray is in
	int			map_x;
	int			map_y;

	// The direction this ray is traveling (unit vector)
	float		dir_x;		
	float		dir_y;

	//  Distance from current position to the next X-side or Y-side grid
	float		side_dist_x;
	float		side_dist_y;

	// Direction to step in the grid (+1 or -1)
	int			step_x;
	int			step_y;

	// Distance the ray has to travel to go from 
	// one X grid line to the next, or Y grid line to next
	float		delta_dist_x;
	float		delta_dist_y;
	float		distance_to_wall_full;
	float		distance_to_wall_perp;
	int			collision_side;
}				t_ray;

*/
void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;//the distance ray has to travel from its first position to the first x-side
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->distance_to_wall_full = 0;
	ray->distance_to_wall_perp = 0;
	ray->collision_side = -1;
	return ;
}

