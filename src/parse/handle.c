/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:48:47 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 12:39:22 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

void	set_info_handle(t_game_info *game_info, t_opcode opcode, char *line)
{
	if (opcode == NORTH_TEXTURE || opcode == SOUTH_TEXTURE
		|| opcode == WEST_TEXTURE || opcode == EAST_TEXTURE)
		set_texture(game_info, line, opcode);
	else if (opcode == FLOOR_COLOR)
		set_colore(game_info, line, opcode);
	else if (opcode == CEILING_COLOR)
		set_colore(game_info, line, opcode);
	else if (opcode == MAP)
		set_map(game_info, line);
}

int	check_value_handle(char *line)
{
	int		i;
	char	*tmp_line;

	if (!line || !*line)
		return (SPACE_OPCODE);
	tmp_line = strdup(line);
	if (!tmp_line)
		return (ERROR_OPCODE);
	i = strlen(tmp_line) - 1;
	if (i >= 0 && (tmp_line[i] == '\n' || tmp_line[i] == '\r'))
		tmp_line[i] = '\0';
	free(tmp_line);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
		return (SPACE_OPCODE);
	if (strncmp(line + i, "NO ", 3) == 0)
		return (NORTH_TEXTURE);
	else if (strncmp(line + i, "SO ", 3) == 0)
		return (SOUTH_TEXTURE);
	else if (strncmp(line + i, "WE ", 3) == 0)
		return (WEST_TEXTURE);
	else if (strncmp(line + i, "EA ", 3) == 0)
		return (EAST_TEXTURE);
	else if (strncmp(line + i, "C ", 2) == 0)
		return (CEILING_COLOR);
	else if (strncmp(line + i, "F ", 2) == 0)
		return (FLOOR_COLOR);
	else if (is_map_line(line))
		return (MAP);
	return (ERROR_OPCODE);
}