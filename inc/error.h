/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:01:26 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/10 17:19:23 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_ARG_INVALID "ERROR: INVALID ARGUMENT ./cub3D [file.cub]"

# define ERR_FILE_IS_INVALID_EXTENSION "ERROR: The path extension is not .cub:"
# define ERR_FILE_OPEN_ERROR "ERROR: File open error check permissions or existence:"
# define ERR_FILE_IS_DIR "ERROR: The path is a directory:"
# define ERR_FILE_IS_EMPTY "ERROR: File is empty:"

# define ERR_TEXTURE_PATH_IS_MISSING "ERROR: Texture path is empty"
# define ERR_TEXTURE_PATH_INVALID_EXTENSION "ERROR: Texture path is not .xpm file"
# define ERR_TEXTURE_TOO_MANY "ERROR: Multiple texture settings"
# define ERR_TEXTURE_IS_MISSING "ERROR Texture path is missing"
# define ERR_TEXTURE_FILE_IS_EMPTY //xpm変換時に追加

# define ERR_COLOR_IS_MISSING "ERROR: Color is missing"
# define ERR_COLOR_IS_INVALID_VALUE "ERROR: RGB is invalid value please 0 ~ 255"
# define ERR_COLOR_IS_NOT_THREE_ELEMENTS "ERROR: Color is not three elements"

# define ERR_PLAYER_TOO_MAMY "ERROR: Multiple players found in map"
# define ERR_PLAYER_IS_MISSING "ERROR: There were no players on the map"
# define ERR_PLAYER_IS_EDGE

# define ERR_MAP_EMPTY "ERROR: MAP is empty"
# define ERR_MAP_IS_NOT_CLOSE
# define ERR_MAP_IS_INVALID "test"

#endif