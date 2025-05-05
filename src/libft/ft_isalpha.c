/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:45:40 by kohki_T           #+#    #+#             */
/*   Updated: 2024/11/12 03:01:58 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char	uc;

	if (!c)
		return (-1);
	uc = (unsigned char)c;
	return (('A' <= uc && uc <= 'Z') || ('a' <= uc && uc <= 'z'));
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("isalpha: %i\n", isalpha('A'));
// 	printf("isalpha:%i\n", isalpha('2'));
// 	printf("isalpha:%i\n", isalpha('['));

// 	printf("ft_isalpha: %i\n", ft_isalpha('A'));
// 	printf("ft_isalpha:%i\n", ft_isalpha('2'));
// 	printf("ft_isalpha:%i\n", ft_isalpha('['));
// 	return (0);
// }
