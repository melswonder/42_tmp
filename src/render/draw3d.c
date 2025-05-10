/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:21:15 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/05/10 10:26:43 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_wall_line(t_cub_img *image,  t_ray *ray, int x)
{
	float	dist;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		y;

	// Projection calculation
	dist = ray->distance_to_wall_perp;
	if (dist == 0)
		dist = 0.01; // avoid division by 0
	lineHeight = (int)(WIN_Y / dist);
	drawStart = -lineHeight / 2 + WIN_Y / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + WIN_Y / 2;
	if (drawEnd >= WIN_Y)
		drawEnd = WIN_Y - 1;
	// Draw vertical line (on the image buffer, not directly to screen)
	y = drawStart;
	while (y++ < drawEnd)
		ft_mlx_putpixel(image, x, y, 0xCCCCCC);
}

