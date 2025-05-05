/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:58:02 by kohki_T           #+#    #+#             */
/*   Updated: 2025/02/23 21:07:10 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!dest)
		return (NULL);
	if (!src)
		return (dest);
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	a[] = "folder";
// 	char	b[] = "make";
// 	char	*pa;
// 	char	*pb;

// 	pa = a;
// 	pb = b;

// 	printf("%s\n", pa);
// 	ft_strcat(pa, pb);
// 	printf("%s\n", pa);

// 	return (0);
// }
