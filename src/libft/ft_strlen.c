/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:58:02 by kohki_T           #+#    #+#             */
/*   Updated: 2024/11/12 02:28:21 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlen(const char *str)
{
	unsigned long	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[] = "string";
// 	char	str2[] = "Ch a ra c t 2**er|s";

// 	printf("test1: %lu\n", strlen(str1));
// 	printf("test2: %lu\n", strlen(str2));
// 	printf("test1: %lu\n", ft_strlen(str1));
// 	printf("test2: %lu\n", ft_strlen(str2));
// 	return (1);
// }
