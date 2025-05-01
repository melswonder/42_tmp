/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:11:15 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/01 21:01:53 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_img(t_img *img)
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
	game_info->north_texture = safe_malloc(sizeof(t_img));
	game_info->south_texture = safe_malloc(sizeof(t_img));
	game_info->west_texture = safe_malloc(sizeof(t_img));
	game_info->east_texture = safe_malloc(sizeof(t_img));
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

bool	is_dir(char *filename)
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

	if (is_dir(filename) == true)
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

void	free_mlx_img(void *mlx, t_img *img)
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
		free(map_info->map[i]);
	}
	free(map_info);
}

void	free_game_info(t_game_info *game_info)
{
	if (game_info)
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
	int	i;

	i = 0;
	if (!line || !*line)
		return (0);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			i++;
		else
			return (0);
	}
	// mapに少なくとも0か1が存在するか
	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_value_handle(char *line)
{
	int	i;

	if (!line && *(line))
		return (SPACE_OPCODE);
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
	t_img	*texture;
	char	*path;
	int		i;

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
	while (line[i] && line != ' ')
		i++;
	while (line[i] && line != ' ')
		i++;
	path = strduo(line + i);
	if (!path)
		return (1);
	if (texture->name) //もうsetされたいた場合
		return (-1);
	return (0);
}

void	set_colore(t_game_info *game_info, char *line, t_opcode opcode)
{
	int	i;
	int	red;
	int	green;
	int	blue;
	int	*color;

	if (opcode == FLOOR_COLOR)
		color = game_info->floor_color;
	else if (opcode == CEILING_COLOR)
		color = game_info->ceiling_color;
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	// if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
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

void	set_with_check_map(t_map_info *map_data, char *line, int y)
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

	map_data = game_info->map_data;
	if (!map_data->map)
	{
		map_data->map = safe_malloc(sizeof(char *) * 2);
		map_data->map[0] = strdup(line);
		// if(!map_data->map[0])
		// 	error_exit(2,"set_map malloc error");
		map_data->map[1] = NULL;
		map_data->map_height = 1;
	}
	else
	{
		map_data->map = add_line_to_map(map_data->map, line,
				map_data->map_height);
		map_data->map_height++;
	}
	set_with_check_map(map_data, line, map_data->map_height - 1);
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

void	search_player_position_and_direction(t_map_info *map_info)
{
	char	**map;
	int		x;
	int		y;

	map = map_info->map;
	x = 0;
	y = 0;
	if (map_info->dir != NOTHING)
		error_exit(2, "dir error");
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'N')
				map_info->dir = NORTH;
			else if (map[y][x] == 'S')
				map_info->dir = SOUTH;
			else if (map[y][x] == 'E')
				map_info->dir = EAST;
			else if (map[y][x] == 'W')
				map_info->dir = WEST;
			x++;
		}
		y++;
	}
	map_info->player_start_x = x;
	map_info->player_start_y = y;
}

// void detect_player_position_and_direction(t_map_info *map_info)
// {
//     char **map;
//     int x;
//     int y;
//     bool player_found = false;

//     map = map_info->map;
//     y = 0;
//     while (map[y])
//     {
//         x = 0;
//         while (map[y][x] != '\0')
//         {
//             if (map[y][x] == 'N' || map[y][x] == 'S' || 
//                 map[y][x] == 'E' || map[y][x] == 'W')
//             {
//                 if (player_found) // 2人目のプレイヤーが見つかった
//                     error_exit(2, "Error: Multiple players found in map");
                
//                 // プレイヤーの位置を記録
//                 map_info->player_start_x = x;
//                 map_info->player_start_y = y;
                
//                 // プレイヤーの向きを設定
//                 if (map[y][x] == 'N')
//                     map_info->dir = NORTH;
//                 else if (map[y][x] == 'S')
//                     map_info->dir = SOUTH;
//                 else if (map[y][x] == 'E')
//                     map_info->dir = EAST;
//                 else if (map[y][x] == 'W')
//                     map_info->dir = WEST;
                
//                 player_found = true;
//             }
//             x++;
//         }
//         y++;
//     }
    
//     if (!player_found)
//         error_exit(2, "Error: No player found in map");
// }

void	replace_spaces_with_walls(t_map_info *map_info)
{
	char	**map;
	int		x;
	int		y;

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

	opcode = 0;
	fd = open(filename, O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		opcode = check_value_handle(line);
		set_info_handle(game_info, opcode, line);
		free(line);
	}
	replace_spaces_with_walls(game_info->map_data);
	search_player_position_and_direction(game_info->map_data);
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

int	main(int argc, char **argv)
{
	t_game_info	*game_info;

	if (argc != 2)
		return (error_msg(2, ERR_ARG_MISSING, NULL));
	game_info = safe_malloc(sizeof(t_game_info));
	init_game_info(game_info);
	if (parse_args(game_info, argv) == true)
		return (1);
	// execute()
	free_game_info(game_info);
	return (0);
}
