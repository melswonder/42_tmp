/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:11:15 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/02 17:32:42 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_img(t_texture_img *img)
{
	img->name = NULL;
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

void	init_map(t_map_info *map)
{
	map->map = NULL;
	map->map_width = 0;
	map->map_height = 0;
	map->dir = NOTHING;
	map->player_start_x = 0;
	map->player_start_y = 0;
}

void	init_game_info(t_game_info *game_info)
{
	game_info->north_texture = safe_malloc(sizeof(t_texture_img));
	game_info->south_texture = safe_malloc(sizeof(t_texture_img));
	game_info->west_texture = safe_malloc(sizeof(t_texture_img));
	game_info->east_texture = safe_malloc(sizeof(t_texture_img));
	game_info->map_data = safe_malloc(sizeof(t_map_info));
	init_img(game_info->north_texture);
	init_img(game_info->south_texture);
	init_img(game_info->west_texture);
	init_img(game_info->east_texture);
	game_info->floor_color[0] = 0;
	game_info->floor_color[1] = 0;
	game_info->floor_color[2] = 0;
	game_info->ceiling_color[0] = 0;
	game_info->ceiling_color[1] = 0;
	game_info->ceiling_color[2] = 0;
	init_map(game_info->map_data);
	game_info->mlx = NULL;
	game_info->mlx_win = NULL;
}

bool	is_directory(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (true);
	}
	return (false);
}

bool	has_cub_extension(char *filename)
{
	int	len;

	len = strlen(filename);
	if (len < 4)
		return (false);
	if (filename[len - 4] == '.' && filename[len - 3] == 'c' && filename[len
		- 2] == 'u' && filename[len - 1] == 'b')
		return (true);
	return (false);
}

int	check_file(char *filename)
{
	int	fd;

	if (is_directory(filename) == true)
		return (error_msg(2, ERR_FILE_IS_DIR, filename));
	if (has_cub_extension(filename) != true)
		return (error_msg(2, ERR_INVALID_EXTENSION, filename));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_msg(2, ERR_FILE_OPEN_ERROR, filename));
	close(fd);
	return (0);
}

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

int	is_map_line(char *line)
{
	int		i;
	bool	has_valid_char;

	i = 0;
	has_valid_char = false;
	if (!line || !*line)
		return (0);
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
		return (0);
	while (line[i] && line[i] != '\n' && line[i] != '\r')
	{
		if (line[i] == ' ' || line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			if (line[i] == '0' || line[i] == '1')
				has_valid_char = true;
			i++;
		}
		else
			return (0);
	}
	if (has_valid_char)
		return (1);
	return (0);
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

int	set_texture(t_game_info *game_info, char *line, t_opcode opcode)
{
	t_texture_img	*texture;
	char			*path;
	int				i;

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

void	set_colore(t_game_info *game_info, char *line, t_opcode opcode)
{
	int	i;
	int	j;
	int	red;
	int	green;
	int	blue;
	int	*color;

	char num_str[4]; // 最大3桁の数字 + 終端文字
	if (opcode == FLOOR_COLOR)
		color = game_info->floor_color;
	else if (opcode == CEILING_COLOR)
		color = game_info->ceiling_color;
	// 識別子 "F " や "C " をスキップ
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	// 赤色の値を抽出
	j = 0;
	while (line[i] && line[i] != ',')
	{
		if (j < 3)
			num_str[j++] = line[i];
		i++;
	}
	num_str[j] = '\0';
	red = atoi(num_str);
	// カンマをスキップ
	if (line[i] == ',')
		i++;
	// 緑色の値を抽出
	j = 0;
	while (line[i] && line[i] != ',')
	{
		if (j < 3)
			num_str[j++] = line[i];
		i++;
	}
	num_str[j] = '\0';
	green = atoi(num_str);
	// カンマをスキップ
	if (line[i] == ',')
		i++;
	// 青色の値を抽出
	j = 0;
	while (line[i] && line[i] != ',' && line[i] != '\n')
	{
		if (j < 3)
			num_str[j++] = line[i];
		i++;
	}
	num_str[j] = '\0';
	blue = atoi(num_str);
	// 値の範囲チェック（0-255）
	if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0
		|| blue > 255)
		error_exit(2, "Invalid color values (must be 0-255)");
	// 色情報を保存
	color[0] = red;
	color[1] = green;
	color[2] = blue;
}

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

void	set_width_check_map(t_map_info *map_data, char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '0' && line[x] != '1' && line[x] != ' ' && line[x] != 'N'
			&& line[x] != 'S' && line[x] != 'E' && line[x] != 'W')
			error_exit(2, "Invalid character in map");
		x++;
	}
	if (x > map_data->map_width)
		map_data->map_width = x;
}

void	set_map(t_game_info *game_info, char *line)
{
	t_map_info	*map_data;
	int			len;

	map_data = game_info->map_data;
	// 行末の改行を削除
	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	// 1行目の場合は初期化
	if (!map_data->map)
	{
		map_data->map = safe_malloc(sizeof(char *) * 2);
		if (!map_data->map)
			error_exit(2, "set_map: Memory allocation failed");
		map_data->map[0] = strdup(line);
		if (!map_data->map[0])
			error_exit(2, "set_map: Memory allocation failed");
		map_data->map[1] = NULL;
		map_data->map_height = 1;
	}
	else
	{
		// 既存のマップに行を追加
		map_data->map = add_line_to_map(map_data->map, line,
				map_data->map_height);
		map_data->map_height++;
	}
	// 行の長さを更新し、マップの文字をチェック
	set_width_check_map(map_data, line);
}

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

int	is_direction(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	validate_player_position(t_map_info *map_info)
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
			if (is_direction(map_info->map[y][x]))
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

void	set_value_from_file(t_game_info *game_info, char *filename)
{
	int		fd;
	char	*line;
	int		opcode;
	int		map_lines_count;

	map_lines_count = 0;
	opcode = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		opcode = check_value_handle(line);
		if (opcode == MAP)
			map_lines_count++;
		set_info_handle(game_info, opcode, line);
		free(line);
		line = get_next_line(fd);
	}
	validate_player_position(game_info->map_data);  //プレイヤーの位置確認
	replace_spaces_with_walls(game_info->map_data); //スペースを壁に
	// check_valid_check();
	close(fd);
}

int	parse_args(t_game_info *game_info, char **argv)
{
	if (check_file(argv[1]) == true)
		return (free_game_info_no_mlx(game_info), 1);
	set_value_from_file(game_info, argv[1]);
	// check_valid_map();
	return (0);
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
int	main(int argc, char **argv)
{
	t_game_info	*game_info;

	if (argc != 2)
		return (error_msg(2, ERR_ARG_MISSING, NULL));
	game_info = safe_malloc(sizeof(t_game_info));
	init_game_info(game_info);
	if (parse_args(game_info, argv) == true)
		return (1);
	print_game_info(game_info);
	// execute()
	// free_game_info(game_info);
	return (0);
}
