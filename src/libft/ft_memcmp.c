/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:54:43 by ktakeuch          #+#    #+#             */
/*   Updated: 2024/11/12 00:34:42 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	i = 0;
	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (uc1[i] != uc2[i])
			return ((int)(uc1[i] - uc2[i]));
		i++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char str1[] = "string";
// 	char str2[] = "Ch a ra c t 2**er|s";
// 	char str3[] = "stringP";

// 	printf("%i\n", ft_memcmp(str1, str2, 2));
// 	printf("%i\n", ft_memcmp(str1, str3, 6));
// 	printf("%i\n", ft_memcmp(str1, str3, 7));

// 	printf("%i\n", memcmp(str1, str2, 2));
// 	printf("%i\n", memcmp(str1, str3, 6));
// 	printf("%i\n", memcmp(str1, str3, 7));

// 	printf("%i\n", ft_memcmp(NULL, str3, 7));
// 	printf("%i\n", ft_memcmp(str1, NULL, 7));
// }
