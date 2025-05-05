/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:49:57 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/03/01 18:21:09 by ktakeuch         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
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
