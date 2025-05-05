/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:11:34 by ktakeuch          #+#    #+#             */
/*   Updated: 2024/11/12 02:27:18 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>

// int	ft_strlen(char *c)
// {
// 	int	i;

// 	i = 0;
// 	while (c[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	if (!dest || !src)
		return (0);
	i = 0;
	if (size == 0)
		return ((unsigned int)(ft_strlen(src)));
	while ((src[i] != '\0') && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ((unsigned int)(ft_strlen(src)));
}

// #include <stdio.h>
// int	main(void)
// {
//     char a[10] = "ready";
//     char b[] = "alluser";
//     char c[3] = "hi";  // Smaller buffer

//     // Normal case
//     ft_strlcpy(a, b, sizeof(a));
//     printf("Test 1: %s\n", a);  
// 	// Expected output: "alluser"

//     // Buffer smaller than source
//     ft_strlcpy(c, b, sizeof(c));
//     printf("Test 2: %s\n", c);  
// 	// Expected output: "al"

//     // Buffer size zero
//     unsigned int len = ft_strlcpy(a, b, 0);
//     printf("Test 3: Length of source: %u\n", len);  
// 	// Expected output: length of "alluser"

//     return 0;
// }

// /*
// c4r1s7% ./a.out 
// Test 1: alluser
// Test 2: al
// Test 3: Length of source: 7
// */

// /*
// n=1
// c2r3s8% ./a.out

// n=5
// c2r3s8% ./a.out        
// allu

// n=0
// c2r3s8% ./a.out        
// ready

// n=10
// c2r3s8% ./a.out        
// alluser
// */

// /*
// Explanation of Each Test:

//     Normal Case: 
// 	This test ensures that a typical string copy from a 
// 	larger source to a larger destination buffer works as expected.

//     Buffer Smaller than Source: 
// 	This checks if the function correctly handles cases where the 
// 	destination buffer is smaller than the source string, truncating 
// 	as needed and null-terminating the destination string.

//     Buffer Size Zero: 
// 	Tests how the function behaves when the destination buffer size is zero. 
// 	The function should only return the length of the source string and not 
// 	attempt to copy anything.

//     Empty Source String: 
// 	Tests how the function behaves when the source string is empty.
// 	Empty Destination Buffer: 
// 	Tests the behavior when the destination buffer has a size of 1,
// 	 ensuring it doesn’t copy anything beyond the null terminator.
// */
