/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:05:16 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 17:40:25 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/keycode.h"
#include "../../inc/parse.h"

void	print_key_press(int keycode)
{
	printf("キーコード: %d - ", keycode);
	if (keycode == ESC_KEY)
		printf("ESC が押されました\n");
	else if (keycode == UP_KEY)
		printf(" ↑  が押されました\n");
	else if (keycode == DOWN_KEY)
		printf(" ↓  が押されました\n");
	else if (keycode == RIGHT_KEY)
		printf(" →  が押されました\n");
	else if (keycode == LEFT_KEY)
		printf(" ←  が押されました\n");
	else if (keycode == W_KEY)
		printf("   W  が押されました\n");
	else if (keycode == A_KEY)
		printf("    A  が押されました\n");
	else if (keycode == S_KEY)
		printf("   S  が押されました\n");
	else if (keycode == D_KEY)
		printf("   D  が押されました\n");
	else if (keycode == Q_KEY)
		printf("   Q  が押されました\n");
	else if (keycode == Z_KEY)
		printf("   Z  が押されました\n");
	else
		printf("   未定義のキー\n");
}

void	print_game_info(t_game_info *game_info)
{
	char	**map;
	int		i;
	int		j;

	printf("\n\n---debug---\n\n");
	if (game_info->north_texture)
	{
		if (game_info->north_texture->name)
			printf("north_texture filename:%s\n",
				game_info->north_texture->name);
		printf("width = %d,height = %d\n", game_info->north_texture->width,
			game_info->north_texture->height);
	}
	else
		printf("north_texture NULL\n");
	if (game_info->south_texture)
	{
		if (game_info->south_texture->name)
			printf("south_texture filename:%s\n",
				game_info->south_texture->name);
		printf("width = %d,height = %d\n", game_info->south_texture->width,
			game_info->south_texture->height);
	}
	else
		printf("south_texture NULL\n");
	if (game_info->west_texture)
	{
		if (game_info->west_texture->name)
			printf("west_texture filename:%s\n", game_info->west_texture->name);
		printf("width = %d,height = %d\n", game_info->west_texture->width,
			game_info->west_texture->height);
	}
	else
		printf("west_texture NULL\n");
	if (game_info->east_texture)
	{
		if (game_info->east_texture->name)
			printf("east_texture filename:%s\n", game_info->east_texture->name);
		printf("width = %d,height = %d\n", game_info->east_texture->width,
			game_info->east_texture->height);
	}
	else
		printf("east_texture NULL\n");
	printf("\n");
	printf("Floor color   R=%d G=%d B=%d\n", game_info->floor_color[0],
		game_info->floor_color[1], game_info->floor_color[2]);
	printf("Ceiling color R=%d G=%d B=%d\n", game_info->ceiling_color[0],
		game_info->ceiling_color[1], game_info->ceiling_color[2]);
	printf("\n");
	if (game_info->map_data)
	{
		printf("width = %d , height = %d\n", game_info->map_data->map_width,
			game_info->map_data->map_height);
		if (game_info->map_data->map)
		{
			map = game_info->map_data->map;
			i = 0;
			while (map[i])
			{
				j = 0;
				while (map[i][j])
				{
					printf("%c", map[i][j]);
					j++;
				}
				printf(" [%d]\n", j);
				i++;
			}
			printf("[%d]\n", i);
		}
		else
			printf("map NULL\n");
	}
	else
		printf("map_data NULL\n");
	if (game_info->map_data && game_info->map_data->dir != NOTHING)
	{
		printf("player x = %d, y = %d dir = ",
			game_info->map_data->player_start_x,
			game_info->map_data->player_start_y);
		if (game_info->map_data->dir == WEST)
			printf("%s\n", "WEST");
		else if (game_info->map_data->dir == EAST)
			printf("%s\n", "EAST");
		else if (game_info->map_data->dir == SOUTH)
			printf("%s\n", "SOUTH");
		else if (game_info->map_data->dir == NORTH)
			printf("%s\n", "NORTH");
		else if (game_info->map_data->dir == NOTHING)
			printf("%s\n", "UNKNOWN");
	}
	else
		printf("No player direction set\n");
	printf("\n\n---DEBUGEND---\n\n");
}
