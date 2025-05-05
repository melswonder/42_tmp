/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:45:40 by kohki_T           #+#    #+#             */
/*   Updated: 2024/11/12 03:02:04 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	unsigned char	uc;

	if (!c)
		return (-1);
	uc = (unsigned char)c;
	return ('0' <= uc && uc <= '9');
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("isdigit: %i\n", isdigit('A'));
// 	printf("isdigit:%i\n", isdigit('2'));
// 	printf("isdigit:%i\n", isdigit(2));
// 	printf("isdigit:%i\n", isdigit(2 + '0'));

// 	printf("ft_isdigit: %i\n", ft_isdigit('A'));
// 	printf("ft_isdigit:%i\n", ft_isdigit('2'));
// 	printf("ft_isdigit:%i\n", ft_isdigit(2));
// 	printf("ft_isdigit:%i\n", ft_isdigit(2 + '0'));
// 	printf("ft_isdigit:%i\n", ft_isdigit(0));
// 	return (0);
// }
