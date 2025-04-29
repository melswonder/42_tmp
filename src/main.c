/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:11:15 by hirwatan          #+#    #+#             */
/*   Updated: 2025/04/30 05:42:31 by hirwatan         ###   ########.fr       */
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
		while (map_info->map[i] != '\0')
		{
			free(map_info->map[i]);
			i++;
		}
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

int	parse_args(t_game_info *game_info, char **argv)
{
	(void)game_info;
	if (check_file(argv[1]) == true)
		return (free_game_info_no_mlx(game_info), 1);
	
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
	free_game_info(game_info);
	return (0);
}
