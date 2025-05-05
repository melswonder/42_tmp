/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:45:40 by kohki_T           #+#    #+#             */
/*   Updated: 2024/11/12 02:49:37 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char	uc;

	if (!c)
		return (0);
	uc = (unsigned char)c;
	return (('0' <= uc && uc <= '9') || ('A' <= uc && uc <= 'Z') || ('a' <= uc
			&& uc <= 'z'));
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("isalnum:%i\n", isalnum('A'));
// 	printf("isalnum:%i\n", isalnum('2'));
// 	printf("isalnum:%i\n", isalnum(2));
// 	printf("isalnum:%i\n", isalnum(2 + '0'));
// 	printf("isalnum:%i\n", isalnum(':'));
// 	printf("\n======\n");
// 	printf("ft_isalnum:%i\n", ft_isalnum('A'));
// 	printf("ft_isalnum:%i\n", ft_isalnum('2'));
// 	printf("ft_isalnum:%i\n", ft_isalnum(2));
// 	printf("ft_isalnum:%i\n", ft_isalnum(2 + '0'));
// 	printf("ft_isalnum:%i\n", ft_isalnum(':'));
// 	return (0);
// }
