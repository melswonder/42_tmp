/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:34:24 by kohki_T           #+#    #+#             */
/*   Updated: 2024/11/12 02:02:44 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h>

char	*ft_strchr(const char *str, int c)
{
	unsigned char	uc;

	if (!str)
		return (NULL);
	uc = (unsigned char)c;
	while (*str)
	{
		if (*str == uc)
			return ((char *)str);
		str++;
	}
	if (uc == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*test1;
// 	char	*test2;

// 	test1 = "string";
// 	test2 = "original";
// 	printf("%s\n", strchr(test1, 'i'));
// 	printf("%s\n", strchr(test2, 'i'));
// 	printf("\n===\n");
// 	printf("%s\n", ft_strchr(test1, 'i'));
// 	printf("%s\n", ft_strchr(test2, 'i'));
// 	printf("%s\n", ft_strchr(NULL, 'i'));
// 	printf("%s\n", ft_strchr(test2, 0));
// 	return (1);
// }
