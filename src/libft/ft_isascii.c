/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:44:03 by kohki_T           #+#    #+#             */
/*   Updated: 2024/11/12 03:01:40 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (!c)
		return (-1);
	return (0 <= c && c <= 127);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("isascii:%i\n", isascii(128));
// 	printf("isascii:%i\n", isascii(127));
// 	printf("isascii:%i\n", isascii('D'));
// 	printf("isascii:%i\n", isascii(0));
// 	printf("isascii:%i\n", isascii(-1));
// 	printf("\n====\n");

// 	printf("ft_isascii: %i\n", ft_isascii(128));
// 	printf("ft_isascii: %i\n", ft_isascii(127));
// 	printf("ft_isascii: %i\n", ft_isascii('D'));
// 	printf("ft_isascii: %i\n", ft_isascii(0));
// 	printf("ft_isascii: %i\n", ft_isascii(-1));
// 	return (0);
// }
