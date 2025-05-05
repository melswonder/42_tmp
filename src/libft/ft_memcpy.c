/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:30:08 by ktakeuch          #+#    #+#             */
/*   Updated: 2024/11/12 00:41:00 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <string.h>

void	*ft_memcpy(void *v1, const void *v2, size_t n)
{
	size_t				i;
	unsigned char		*uc1;
	const unsigned char	*uc2;

	if (!v1)
		return (NULL);
	if (!v2)
		return (v1);
	i = 0;
	uc1 = (unsigned char *)v1;
	uc2 = (const unsigned char *)v2;
	while (i < n)
	{
		uc1[i] = uc2[i];
		i++;
	}
	return (v1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[50] = "GeeksForGeeks is for programming geeks.";
// 	char num[6] = "012345";
// 	printf("Before memcpy(): %s\n", str);

// 	ft_memcpy(str + 5, num, 4 * sizeof(char));
// 	ft_memcpy(NULL, num, 4 * sizeof(char));
// 	ft_memcpy(str + 5, NULL, 4 * sizeof(char));

// 	printf("After memcpy():  %s\n", str);
// }
