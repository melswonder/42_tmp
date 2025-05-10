/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:29:07 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/05/07 23:49:06 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3D.h"
# include "error.h"
# include "get_next_line.h"
# include "keycode.h"
# include "libft.h"
# include "minimap.h"
# include "parse.h"
# include "raycast.h"
// # include "render.h"
# include "utils.h"
# include "player.h"

// /* render.c */
int	render(t_game_info *game_info);
int	draw_ceiling_and_floor(t_game_info *game_info, t_cub_img *image);

// /* key.c */
int	key_press(int keycode, void *param);
int	key_release(int keycode, void *param);

#endif
