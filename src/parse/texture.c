/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/05/10 18:02:21 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

int	is_xpmfile(char *path)
{
	int	len;

	len = strlen(path);
	if (path[len - 4] == '.' && path[len - 3] == 'x' && path[len - 2] == 'p'
		&& path[len - 1] == 'm')
		return (1);
	return (0);
}

int	check_set_texture(t_game_info *game_info, char *line, t_opcode opcode)
{
	t_cub_img	*texture;
	char		*path;
	int			i;
	int			len;

	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	texture = NULL;
	if (opcode == NORTH_TEXTURE)
		texture = game_info->north_texture;
	else if (opcode == SOUTH_TEXTURE)
		texture = game_info->south_texture;
	else if (opcode == WEST_TEXTURE)
		texture = game_info->west_texture;
	else if (opcode == EAST_TEXTURE)
		texture = game_info->east_texture;
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	path = strdup(line + i);
	if (!path)
		return (error_msg(2, ERR_TEXTURE_PATH_IS_MISSING, NULL)); // is opcode使う
	if (!is_xpmfile(path))
		return (error_msg(2, ERR_TEXTURE_PATH_INVALID_EXTENSION, path),
			free(path), 1);
	if (texture->name)
		return (error_msg(2, ERR_TEXTURE_TOO_MANY, path), free(path), 1);
	else
		texture->name = path;
	return (0);
}

int	safe_get_arg_color(char *str)
{
	int	i;
	int	ret;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	ret = atoi(str + i);
	return (ret);
}

int	number_of_elements(char **str) //200,200,のとき治す
{
	int	i = 0;
	// int	j;

	// j = 0;
	// i = 0;
	// while (str[i] != NULL)
	// {
	// 	if (str[i][j] == ' ' || str[i][j] == '\t')
			
	// }
	return (i);
}

void	free_elemts(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_set_color(t_game_info *game_info, char *line, t_opcode opcode)
{
	int		i;
	int		*color;
	char	**str;

	if (opcode == FLOOR_COLOR)
		color = game_info->floor_color;
	else
		color = game_info->ceiling_color;
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (error_msg(2, ERR_COLOR_IS_MISSING, NULL));
	str = ft_split(line + i, ',');
	if (number_of_elements(str) != 3)
		return (free_elemts(str), error_msg(2, ERR_COLOR_IS_NOT_THREE_ELEMENTS,
				NULL));
	color[0] = safe_get_arg_color(str[0]);
	color[1] = safe_get_arg_color(str[1]);
	color[2] = safe_get_arg_color(str[2]);
	if (color[0] < 0 || color[0] > 255 || color[1] < 0 || color[1] > 255
		|| color[2] < 0 || color[2] > 255)
		return (free_elemts(str), error_msg(2, ERR_COLOR_IS_INVALID_VALUE,
				NULL));
	return (free_elemts(str), 0);
}
