/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:32:49 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/10 16:56:05 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

//渡されたlineをmapの構造体のmap**格納する
int	check_set_map(t_game_info *game_info, char *line)
{
	t_map_info	*map_data;
	int			len;

	map_data = game_info->map_data;
	// 行末の改行を削除(char ** mapの中には改行ではなくnull文字を格納したいため)
	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (!map_data->map) // 1行目の場合は初期化
	{
		map_data->map = safe_malloc(sizeof(char *) * 2);
		if (!map_data->map)
			error_free_exit(game_info, 2,
				"check_set_map: Memory allocation failed");
		map_data->map[0] = strdup(line);
		if (!map_data->map[0])
			error_free_exit(game_info, 2,
				"check_set_map: Memory allocation failed");
		map_data->map[1] = NULL;
		map_data->map_height = 1;
	}
	else
	{
		map_data->map = add_line_to_map(map_data->map, line,
				map_data->map_height);
		map_data->map_height++;
	}
	if (validate_map_line(map_data, line) == FAILURE)
		return (1);
	return (0);
}

// char **mapを拡張して追加していく
char	**add_line_to_map(char **map, char *line, int height)
{
	char	**new_map;
	int		i;

	new_map = safe_malloc(sizeof(char *) * (height + 2));
	i = 0;
	while (i < height)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[height] = strdup(line);
	if (!new_map[height])
		error_exit(2, "addline: Memory allocation failed");
	new_map[height + 1] = NULL;
	free(map);
	return (new_map);
}

int	validate_map_line(t_map_info *map_data, char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '0' && line[x] != '1' && line[x] != ' ' && line[x] != 'N'
			&& line[x] != 'S' && line[x] != 'E' && line[x] != 'W')
			return (error_msg(2, ERR_MAP_IS_INVALID, NULL));
		x++;
	}
	if (x > map_data->map_width) //読み込んだmapの横幅の最大値を更新していく
		map_data->map_width = x;
	return (0);
}

// 1111111
// 1111111
// 11111111111111111
//このmapが来た時に
//		↓
//空白を埋めるため、最大値を常に更新していく必要がある
// 11111111111111111
// 11111111111111111
// 11111111111111111
