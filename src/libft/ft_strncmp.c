/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 02:35:01 by kohki_T           #+#    #+#             */
/*   Updated: 2024/11/12 02:30:39 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*uc1;
	unsigned char	*uc2;
	size_t			i;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (uc1[i] != uc2[i])
			return ((int)(uc1[i] - uc2[i]));
		if (uc1[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char *test1 = "abcdEFGH";
// 	const char *test2 = "abcdEFg";
// 	printf("%i\n", strncmp(test1, test2, 6));
// 	printf("%i\n", strncmp(test1, test2, 7));
// 	printf("%i\n", strncmp(test1, test2, 8));

// 	printf("%i\n", ft_strncmp(test1, test2, 6));
// 	printf("%i\n", ft_strncmp(test1, test2, 7));
// 	printf("%i\n", ft_strncmp(test1, test2, 8));

// 	return (1);
// }
