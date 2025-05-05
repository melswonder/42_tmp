/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:13:53 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/06 00:42:51 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minimap.h"

//プレイヤーの方向ベクトルの計算に必要

float	cos_table[ANGLE_COUNT];
float	sin_table[ANGLE_COUNT];


/// @brief Initialize the sine and cosine tables for angles from 0 to 359 degrees.
void	init_trig_tables(void)
{
	int	i = -1;

	while (++i < ANGLE_COUNT)
	{
		const int	q = i / 90;
		const int	p = i % 90;
		const float	ratio = p / 90.0f;

		cos_table[i] = (float[]){1 - ratio, -ratio, -1 + ratio, ratio}[q];
		sin_table[i] = (float[]){ratio, 1 - ratio, -ratio, -1 + ratio}[q];
	}
}

float	get_cos(int angle)
{
	while (angle < 0)
		angle += ANGLE_COUNT;
	angle %= ANGLE_COUNT;
	return (cos_table[angle]);
}

float	get_sin(int angle)
{
	while (angle < 0)
		angle += ANGLE_COUNT;
	angle %= ANGLE_COUNT;
	return (sin_table[angle]);
}
