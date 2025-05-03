/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:24:01 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 12:50:32 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

//プレイヤーの向きと座標を格納する
void	detect_player_position(t_map_info *map_info)
{
	int		x;
	int		y;
	bool	player_found;

	y = 0;
	player_found = false;
	if (!map_info || !map_info->map)
		return ;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x] != '\0')
		{
			if (is_direction_char(map_info->map[y][x]))
			{
				if (player_found)
					error_exit(2, "Error: Multiple players found in map");
				set_player_dir_position(map_info, x, y);
				player_found = true;
			}
			x++;
		}
		y++;
	}
	if (!player_found)
		error_exit(2, "Error: No player found in map");
}

int	is_direction_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	set_player_dir_position(t_map_info *map_info, int x, int y)
{
	char	**map;

	map = map_info->map;
	map_info->player_start_x = x + 1;
	map_info->player_start_y = y + 1;
	if (map[y][x] == 'N')
		map_info->dir = NORTH;
	else if (map[y][x] == 'S')
		map_info->dir = SOUTH;
	else if (map[y][x] == 'E')
		map_info->dir = EAST;
	else if (map[y][x] == 'W')
		map_info->dir = WEST;
}
