/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:29:07 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/05/06 17:17:25 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3D.h"
# include "error.h"
# include "get_next_line.h"
# include "keycode.h"
# include "libft.h"
# include "minimap.h"
# include "parse.h"
# include "raycast.h"
# include "render.h"
// # include "utils.h"
# include "player.h"

/* util/free.c */
void	free_game_info_no_mlx(t_game_info *game_info);
void	free_game_info(t_game_info *game_info);
void	free_map(t_map_info *map_info);
void	free_mlx_img(void *mlx, t_cub_img *img);

/* util/util.c */
void	error_exit(int fd, char *msg);
int		error_msg(int fd, char *msg, char *arg);
void	error_free_exit(t_game_info *game_info, int fd, char *msg);

/* util/mlx_util.c */
int		exit_event(int keycode, void *param);
int		close_window(void *param);
void	ft_mlx_putpixel(t_cub_img *image, int x, int y, int color);

#endif
