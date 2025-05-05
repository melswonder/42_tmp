/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:15:54 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/04 18:00:50 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

// マップが有効な形状かチェック
bool	check_valid_map(t_map_info *map_info)
{
	char	**map;
	int		player_x;
	int		player_y;
	int		rows;
	int		cols;
	int		i;

	map = map_copy(map_info);
	player_x = map_info->player_start_x - 1;
	player_y = map_info->player_start_y - 1;
	rows = map_info->map_height;
	cols = map_info->map_width;
	if (!floodFill(map, player_x, player_y, '0', '2', rows, cols))
		return (false);
	printf("--floodFill--\nsrc/map/flood_fill.c\n");
	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	return (true);
}

char	**map_copy(t_map_info *map_info)
{
	char	**ret;
	int		i;

	ret = (char **)malloc(sizeof(char *) * (map_info->map_height + 1));
	ret[map_info->map_height] = NULL;
	i = 0;
	while (i < map_info->map_height)
	{
		ret[i] = strdup(map_info->map[i]);
		i++;
	}
	return (ret);
}

bool	floodFill(char **map, int x, int y, char target, char replace, int rows,
		int cols)
{
	if (!isInBounds(x, y, rows, cols))
		return (false);
	if (map[x][y] != target)
		return (false);
	map[x][y] = replace;
	floodFill(map, x + 1, y, target, replace, rows, cols); // 下
	floodFill(map, x - 1, y, target, replace, rows, cols); // 上
	floodFill(map, x, y + 1, target, replace, rows, cols); // 右
	floodFill(map, x, y - 1, target, replace, rows, cols); // 左
	return (true);
}

bool	isInBounds(int x, int y, int rows, int cols)
{
	return (x >= 0 && x < rows && y >= 0 && y < cols);
}
