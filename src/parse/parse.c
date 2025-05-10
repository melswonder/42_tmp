/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:09:08 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/10 17:18:37 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/error.h"
#include "../../inc/parse.h"

int	parse_args(t_game_info *game_info, char **argv)
{
	if (check_file(argv[1]) == true)
		return (free_game_info_no_mlx(game_info), 1);
	if (set_value_from_file(game_info, argv[1]) == true)
		return (free_game_info_no_mlx(game_info), 1);
	if (is_all_assigned(game_info) == false)
		return (free_game_info_no_mlx(game_info), 1);
	return (free_game_info_no_mlx(game_info), 1);
	if (!check_valid_map(game_info->map_data)) // mapcheck実装
		return (error_exit(2, "map_floodfill_faild"), 0);
	init_player(game_info);
	return (0);
}

int	is_all_assigned(t_game_info *game_info)
{
	if (!game_info->north_texture->name || !game_info->east_texture->name
		|| !game_info->west_texture->name || !game_info->south_texture->name)
		return (error_msg(2, ERR_TEXTURE_IS_MISSING, NULL));
	if (!game_info->map_data->map)
		return (error_msg(2, ERR_MAP_EMPTY, NULL));
	return (0);
}

//ファイルがちゃんと開けるか
int	check_file(char *filename)
{
	int	fd;

	if (is_directory(filename) == true)
		return (error_msg(2, ERR_FILE_IS_DIR, filename));
	if (is_cub_extension(filename) != true)
		return (error_msg(2, ERR_FILE_IS_INVALID_EXTENSION, filename));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_msg(2, ERR_FILE_OPEN_ERROR, filename));
	close(fd);
	return (0);
}

int	cleanup_gnl(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

//.cubファイルに書かれているものを構造体に格納する
int	set_value_from_file(t_game_info *game_info, char *filename)
{
	int		fd;
	char	*line;
	int		opcode;

	fd = open(filename, O_RDONLY); // check済みのためエラーチェックを省略する
	line = get_next_line(fd);
	if (!line || line[0] == '\0')
		return (error_msg(2, ERR_FILE_IS_EMPTY, NULL), close(fd), free(line),
			1);
	while (line != NULL)
	{
		opcode = check_value_handle(line);
		if (check_and_set_line(game_info, opcode, line) == FAILURE)
			return (free(line), cleanup_gnl(fd), close(fd), 1);
		free(line);
		line = get_next_line(fd);
	}
	if (detect_player_position(game_info->map_data) == FAILURE)
		return (close(fd), 1);
	replace_spaces_with_walls(game_info->map_data); //スペースを壁に
	close(fd);
	return (0);
}
