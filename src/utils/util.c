/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/06 18:51:05 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"
#include "../inc/utils.h"

void	error_exit(int fd, char *msg)
{
	if(msg!=NULL)
		write(fd, msg, strlen(msg));
	exit(1);
}

void error_free_exit(t_game_info *game_info,int fd,char *msg)
{
	free_game_info(game_info);
	error_exit(fd,msg);	
}

int	error_msg(int fd, char *msg,char *arg)
{
	while(*msg)
		write(fd,msg++,1);
	write(fd," ",1);
	if(arg)
	{
		while(*arg)
			write(fd,arg++,1);
	}
	write(fd, "\n", 1);
	return (1);
}

