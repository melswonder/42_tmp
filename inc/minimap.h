/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:02:59 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/06 00:10:12 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"
# include "error.h"
# include "get_next_line.h"
# include "keycode.h"
# include "libft.h"
# include "parse.h"
# include "raycast.h"
# include "render.h"
# include "utils.h"
// # include "minimap.h"

#define MAP_GREEN 0x00008000 //0x00008000だと半透明になるらしいがlinuxだとできない
#define MAP_WHITE 0x00FFFFFF
#define MAP_PINK 0x00FFDBED
#define MAP_RED 0x00FF0000
#define BLUE 0x000000FF

#define SPEED 5 //minimapのplayerの移動速度
#define BLOCK_SIZE 12 //mapnのブロックサイズを定義できます
#define MAP_SIZE 1 // minimapのサイズを定義できます
#define MAP_X 10 //minimapのX座標
#define MAP_Y 10 //minimapのY座標

#define PI 3.141592654
#define ANGLE_COUNT 360


typedef struct s_math
{
float	cos_table[ANGLE_COUNT]; //0~360のcosを入れている
    float	sin_table[ANGLE_COUNT]; //sin_table
}   t_math;
