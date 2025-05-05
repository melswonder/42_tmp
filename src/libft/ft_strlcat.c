/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:52:42 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/02/23 21:00:57 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_dest;
	unsigned int	len_src;

	if (!dest || !src)
		return (0);
	i = 0;
	len_dest = (unsigned int)(ft_strlen(dest));
	len_src = (unsigned int)(ft_strlen(src));
	if (size <= len_dest)
	{
		return (size + len_src);
	}
	else if (len_dest < size)
	{
		while (src[i] != '\0' && (i < size - len_dest - 1))
		{
			dest[len_dest + i] = src[i];
			i++;
		}
		dest[len_dest + i] = '\0';
		return (len_dest + len_src);
	}
	else
		return (len_dest + len_src);
}

// #include <stdio.h>
// int main(void)
// {
//     // Test Case 1: Basic Concatenation
//     {
//         char dest[20] = "Hello, ";
//         char src[] = "World!";
//         unsigned int size = 20;

//         printf("Test Case 1\nBefore: %s\n", dest);
//         ft_strlcat(dest, src, size);
//         printf("After: %s\n\n", dest);
//         printf("Return value: %u\n\n", ft_strlcat(dest, src, size));
//     }

//     // Test Case 2: No Space for Concatenation
//     {
//         char dest[10] = "Hi";
//         char src[] = "There!";
//         unsigned int size = 5;

//         printf("Test Case 2\nBefore: %s\n", dest);
//         ft_strlcat(dest, src, size);
//         printf("After: %s\n", dest);
//         printf("Return value: %u\n\n", ft_strlcat(dest, src, size));
//     }

//     // Test Case 3: Buffer Exactly Fits
//     {
//         char dest[15] = "Test";
//         char src[] = "1234";
//         unsigned int size = 15;

//         printf("Test Case 3\nBefore: %s\n", dest);
//         ft_strlcat(dest, src, size);
//         printf("After: %s\n", dest);
//         printf("Return value: %u\n\n", ft_strlcat(dest, src, size));
//     }

//     // Test Case 4: Source Larger Than Buffer
//     {
//         char dest[10] = "ABCDE";
//         char src[] = "123456789";
//         unsigned int size = 10;

//         printf("Test Case 4\nBefore: %s\n", dest);
//         ft_strlcat(dest, src, size);
//         printf("After: %s\n", dest);
//         printf("Return value: %u\n\n", ft_strlcat(dest, src, size));
//     }

//     // Test Case 5: Empty Destination
//     {
//         char dest[10] = "";
//         char src[] = "Hello";
//         unsigned int size = 10;

//         printf("Test Case 5\nBefore: %s\n", dest);
//         ft_strlcat(dest, src, size);
//         printf("After: %s\n", dest);
//         printf("Return value: %u\n\n", ft_strlcat(dest, src, size));
//     }

//     // Test Case 6: Empty Source
//     {
//         char dest[20] = "Start";
//         char src[] = "";
//         unsigned int size = 20;

//         printf("Test Case 6\nBefore: %s\n", dest);
//         ft_strlcat(dest, src, size);
//         printf("After: %s\n", dest);
//         printf("Return value: %u\n\n", ft_strlcat(dest, src, size));
//     }

//     // Test Case 7: Size is Zero
//     {
//         char dest[10] = "NoSpace";
//         char src[] = "Here";
//         unsigned int size = 0;

//         printf("Test Case 7\nBefore: %s\n", dest);
//         ft_strlcat(dest, src, size);
//         printf("After: %s\n", dest);
//         printf("Return value: %u\n\n", ft_strlcat(dest, src, size));
//     }

//     return (0);
// }

// // Test Case 1
// // Before: Hello,
// // After: Hello, World!

// // Return value: 19

// // Test Case 2
// // Before: Hi
// // After: HiTh
// // Return value: 10

// // Test Case 3
// // Before: Test
// // After: Test1234
// // Return value: 12

// // Test Case 4
// // Before: ABCDE
// // After: ABCDE1234
// // Return value: 18

// // Test Case 5
// // Before:
// // After: Hello
// // Return value: 10

// // Test Case 6
// // Before: Start
// // After: Start
// // Return value: 5

// // Test Case 7
// // Before: NoSpace
// // After: NoSpace
// // Return value: 4 <-- was 11 in try 2
