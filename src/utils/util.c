/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by hirwatan          #+#    #+#             */
/*   Updated: 2025/05/03 20:35:23 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"
#include "../inc/utils.h"

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

