/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:11:15 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 12:37:37 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"
#include "../inc/error.h"

int	main(int argc, char **argv)
{
	t_game_info	*game_info;

	if (argc != 2)
		return (error_msg(2, ERR_ARG_MISSING, NULL));
	game_info = safe_malloc(sizeof(t_game_info));
	init_game_info(game_info);
	if (parse_args(game_info, argv) == true)
		return (1);
	print_game_info(game_info);
	free_game_info(game_info);
	return (0);
}
