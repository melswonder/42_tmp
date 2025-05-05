/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:51:45 by kohki_T           #+#    #+#             */
/*   Updated: 2024/11/12 03:02:11 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	unsigned char	uc;

	if (!c)
		return (-1);
	uc = (unsigned char)c;
	return (' ' <= uc && uc <= '~');
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("isprint:%i\n", isprint(127));
// 	printf("isprint:%i\n", isprint(126));
// 	printf("isprint:%i\n", isprint('D'));
// 	printf("isprint:%i\n", isprint(32));
// 	printf("isprint:%i\n", isprint(31));
// 	printf("\n====\n");

// 	printf("ft_isprint: %i\n", ft_isprint(127));
// 	printf("ft_isprint: %i\n", ft_isprint(126));
// 	printf("ft_isprint: %i\n", ft_isprint('D'));
// 	printf("ft_isprint: %i\n", ft_isprint(32));
// 	printf("ft_isprint: %i\n", ft_isprint(31));
// 	return (0);
// }
