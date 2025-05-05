/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:52:46 by ktakeuch          #+#    #+#             */
/*   Updated: 2024/11/12 00:08:49 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdlib.h>
// #include <stdio.h>

// void	*ft_memset(void *s, int c, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*ptr;

// 	i = 0;
// 	ptr = (unsigned char *)s;
// 	while (i < n)
// 	{
// 		ptr[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (s);
// }

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > 2147483647 / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, nmemb * size);
	return ((void *)p);
}

// int main(void)
// {
// 	char *c;
// 	c = calloc(2,4);
// 	if(!c)
// 		return (0);
// 	printf("%p", c);
// 	free(c);
// 	return (1);
// }