/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:55:31 by kohki_T           #+#    #+#             */
/*   Updated: 2024/11/12 00:28:59 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;
	size_t			i;

	if (!s)
		return (NULL);
	us = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (us[i] == (unsigned char)c)
			return ((void *)(us + i));
		i++;
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
// 	printf("%s\n", (char *)memchr(test1, 'i', 10 * sizeof(char)));
// 	printf("%s\n", (char *)memchr(test2, 'i', 10 * sizeof(char)));
// 	printf("\n===\n");
// 	printf("%s\n", (char *)ft_memchr(test1, 'i', 10 * sizeof(char)));
// 	printf("%s\n", (char *)ft_memchr(test2, 'i', 10 * sizeof(char)));
// 	return (1);
// }
