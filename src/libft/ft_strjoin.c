/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:37:41 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/03/03 19:17:24 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	copy_to_dest(char *dest, const char *s1, const char *s2)
{
	int	i;
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	while (i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		dest[i] = s2[i - len1];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	copy_to_dest(dest, s1, s2);
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char test1[] = "GOOD";
// 	char test2[] = "job";

// 	printf("%s\n", ft_strjoin(test1, test2));
// 	printf("%s\n", ft_strjoin(test1, NULL));
// 	printf("%s\n", ft_strjoin(NULL, test2));
// 	return (1);
// }