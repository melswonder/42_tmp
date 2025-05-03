/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:44:55 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 16:00:11 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

int	set_texture(t_game_info *game_info, char *line, t_opcode opcode)
{
	t_texture_img	*texture;
	char			*path;
	int				i;
	int				len;

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
		return (1);
	if (texture->name) //もうsetされたいた場合
		free(path);
	else
		texture->name = path;
	return (0);
}

// C 255,255,255ときた時に カンマ区切りのため、インクリメントをアドレスとして渡す
//呼べば自動的に次の色の開始地点までインクリメントを飛ばしてくれる。　R G Bを確保することができる。
int	get_arg_color(char *line, int *pos)
{
	int		j;
	int		value;
	char	num_str[4];

	j = 0;
	while (line[*pos] && line[*pos] != ',' && line[*pos] != '\n')
	{
		if (j < 3 && line[*pos] >= '0' && line[*pos] <= '9')
			num_str[j++] = line[*pos];
		(*pos)++;
	}
	num_str[j] = '\0';
	value = atoi(num_str);
	if (line[*pos] == ',')
		(*pos)++;
	return (value);
}

void	set_colore(t_game_info *game_info, char *line, t_opcode opcode)
{
	int	i;
	int	rgb[3];
	int	*color;

	if (opcode == FLOOR_COLOR)
		color = game_info->floor_color;
	else
		color = game_info->ceiling_color;
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	rgb[0] = get_arg_color(line, &i); // R
	rgb[1] = get_arg_color(line, &i); // G
	rgb[2] = get_arg_color(line, &i); // B
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255 || rgb[2] < 0
		|| rgb[2] > 255)
		error_exit(2, "Error:Invalid color values (must be 0-255)");
	color[0] = rgb[0];
	color[1] = rgb[1];
	color[2] = rgb[2];
}
