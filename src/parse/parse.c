/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:09:08 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 12:52:43 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/error.h"
#include "../../inc/parse.h"

int	parse_args(t_game_info *game_info, char **argv)
{
	if (check_file(argv[1]) == true)
		return (free_game_info_no_mlx(game_info), 1);
	set_value_from_file(game_info, argv[1]);
	// if (!check_valid_map(game_info->map_data)) mapcheck未実装
	return (0);
}

//ファイルがちゃんと開けるか
int	check_file(char *filename)
{
	int	fd;

	if (is_directory(filename) == true)
		return (error_msg(2, ERR_FILE_IS_DIR, filename));
	if (is_cub_extension(filename) != true)
		return (error_msg(2, ERR_INVALID_EXTENSION, filename));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_msg(2, ERR_FILE_OPEN_ERROR, filename));
	close(fd);
	return (0);
}

//.cubファイルに書かれているものを構造体に格納する
void	set_value_from_file(t_game_info *game_info, char *filename)
{
	int		fd;
	char	*line;
	int		opcode;
	int		map_lines_count;

	map_lines_count = 0;
	opcode = 0;
	fd = open(filename, O_RDONLY); // check済みのためエラーチェックを省略する
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
	detect_player_position(game_info->map_data);    //プレイヤーの位置確認
	replace_spaces_with_walls(game_info->map_data); //スペースを壁に
	close(fd);
}
