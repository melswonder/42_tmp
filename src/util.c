/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by hirwatan          #+#    #+#             */
/*   Updated: 2025/04/30 02:32:56 by hirwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	error_exit(int fd, char *msg)
{
	write(fd, msg, strlen(msg));
	exit(1);
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

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		error_exit(2,"Error in malloc");
	return (ret);
}
