/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:48:47 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/10 13:46:37 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

int	check_and_set_line(t_game_info *game_info, t_opcode opcode, char *line)
{
	int	ret;

	ret = 0;
	// if(opcode == ERROR_H)多分中身から
	if (opcode == NORTH_TEXTURE || opcode == SOUTH_TEXTURE
		|| opcode == WEST_TEXTURE || opcode == EAST_TEXTURE)
		ret = check_set_texture(game_info, line, opcode);
	else if (opcode == FLOOR_COLOR)
		ret = check_set_color(game_info, line, opcode);
	else if (opcode == CEILING_COLOR)
		ret = check_set_color(game_info, line, opcode);
	else if (opcode == MAP)
		ret = check_set_map(game_info, line);
	if (ret == 1)
		error_free_exit(game_info, 2, NULL);
	return (0);
}

int	check_value_handle(char *line)
{
	int i;
	char *tmp_line;

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
