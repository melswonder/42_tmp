/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:30:48 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/04 16:16:29 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

//空白を1に置き換える
void	replace_spaces_with_walls(t_map_info *map_info)
{
	char	**map;
	int		x;
	int		y;

	if (!map_info || !map_info->map)
		return ;
	y = 0;
	map = map_info->map;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == ' ')
				map[y][x] = '1';
			x++;
		}
		y++;
	}
}
