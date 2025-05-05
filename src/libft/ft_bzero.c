/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:16:45 by ktakeuch          #+#    #+#             */
/*   Updated: 2024/11/12 00:04:51 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	if (!s || !n)
		return (NULL);
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
	return (s);
}

// /// test=====================================

// #include <stdio.h>

// int	main(void)
// {
// 	char str[50] = "GeeksForGeeks is for programming geeks.";

// 	printf("Before bzero(): %s\n", str);

// 	// Zero out the part of the string starting from index 13
// 	ft_bzero(str + 13, 10);

// 	printf("After bzero():  %s\n", str);

// 	// Print the raw memory contents after bzero, to see the null bytes
// 	printf("Memory after bzero(): ");
// 	for (int i = 0; i < 50; i++)
// 	{
// 		if (str[i] == '\0')
// 			printf("\\0 ");
// 		else
// 			printf("%c ", str[i]);
// 	}

// 	return (0);
// }