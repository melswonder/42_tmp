/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:52:42 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/02/23 21:07:49 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
// 	char a[] = "ready";
// 	char b[] = "alluser";

// 	ft_strcpy(a, b);  // Copy string b to a

// 	printf("%s\n", a);  // Print the copied string

// 	return (0);
// 	// char *ptra;
// 	// char *ptrb;

// 	// ptra = &a;
// 	// ptrb = &b;

// 	// ft_strcpy(ptra, ptrb);

// 	// printf("%s", ptra);
// }
