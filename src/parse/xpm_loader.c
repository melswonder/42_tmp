/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:12:09 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/04 18:33:15 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

static int	load_single_texture(void *mlx, t_cub_img *texture)
{
	int	width;
	int	height;

	if (!texture || !texture->name)
		return (1);
	texture->img = mlx_xpm_file_to_image(mlx, texture->name, &width, &height);
	if (!texture->img)
		return (error_msg(2, "Failed to load texture", texture->name));
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	texture->width = width;
	texture->height = height;
	return (0);
}

int	load_texture_from_xpm(t_game_info *game_info)
{
	if (load_single_texture(game_info->mlx, game_info->north_texture))
		return (1);
	if (load_single_texture(game_info->mlx, game_info->south_texture))
		return (1);
	if (load_single_texture(game_info->mlx, game_info->west_texture))
		return (1);
	if (load_single_texture(game_info->mlx, game_info->east_texture))
		return (1);
	return (0);
}
