/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:54:01 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 12:50:40 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

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

//.cubの拡張子化チェック
bool	is_cub_extension(char *filename)
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
