/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:49:57 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/03/01 18:23:50 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>

// unsigned long	ft_strlen(const char *str)
// {
// 	unsigned long	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

char	*ft_strndup(const char *s, size_t n)
{
	int		i;
	char	*dest;
	int		len;

	if (!s || n <= 0)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (len > (int)n)
		len = (int)n;
	dest = (char *)ft_calloc((len + 1), sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return ((char *)dest);
}

// int main()
// {
// 	char *str = "string";
// 	printf("%s\n", ft_strdup(str));
// 	return (1);
// }
