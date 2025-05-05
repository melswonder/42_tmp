/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:01:46 by kohki_T           #+#    #+#             */
/*   Updated: 2024/11/12 01:33:06 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[50] = "GeeksForGeeks is for programming geeks.";
// 	printf("\nBefore memset(): %s\n", str);

// 	ft_memset(str + 13, '.', 8 * sizeof(char));
// 	printf("After memset():  %s\n", str);

// 	ft_memset(NULL, 'p', 8 * sizeof(char));
// 	printf("After memset():  %s\n", str);

// 	ft_memset(str, 'p', 1);
// 	printf("After memset():  %s\n", str);
// }