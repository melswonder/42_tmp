/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:13:21 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 12:34:48 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

void	free_game_info_no_mlx(t_game_info *game_info)
{
	if (!game_info)
		return ;
	free(game_info->north_texture);
	free(game_info->south_texture);
	free(game_info->west_texture);
	free(game_info->east_texture);
	free(game_info->map_data);
	free(game_info);
}

void	free_game_info(t_game_info *game_info)
{
	if (!game_info)
		return ;
	free_mlx_img(game_info->mlx, game_info->north_texture);
	free_mlx_img(game_info->mlx, game_info->south_texture);
	free_mlx_img(game_info->mlx, game_info->west_texture);
	free_mlx_img(game_info->mlx, game_info->east_texture);
	free_map(game_info->map_data);
	if (game_info->mlx && game_info->mlx_win)
		mlx_destroy_window(game_info->mlx, game_info->mlx_win);
	if (game_info->mlx)
		mlx_destroy_display(game_info->mlx);
	free(game_info);
}

void	free_mlx_img(void *mlx, t_texture_img *img)
{
	if (img)
	{
		if (img->img && mlx)
			mlx_destroy_image(mlx, img->img);
		free(img->name);
		free(img);
	}
}

void	free_map(t_map_info *map_info)
{
	int	i;

	if (map_info->map)
	{
		i = 0;
		while (map_info->map[i] != NULL)
		{
			free(map_info->map[i]);
			i++;
		}
		free(map_info->map);
	}
	free(map_info);
}
