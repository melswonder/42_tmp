/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:39:50 by ktakeuch          #+#    #+#             */
/*   Updated: 2024/10/26 20:04:01 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = (long)n;
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(fd, &c, 1);
	}
	return ;
}

// int main(void)
// {
// 	ft_putnbr_fd(1234, 1);
// 	ft_putnbr_fd(-5678,1);
// }
