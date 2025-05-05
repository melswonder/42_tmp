/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:01:26 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/02/11 01:25:40 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdlib.h>

// static int	is_separator(char separator, char c)
// {
// 	if (c == separator)
// 		return (1);
// 	return (0);
// }

static int	is_separator(char *separators, char c)
{
	int	i;

	i = 0;
	while (separators[i] != '\0')
	{
		if (c == separators[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strdup_startend(const char *str, int start, int end)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc((((end - start + 1) + 1) * sizeof(char)));
	if (!dest)
		return (NULL);
	while (str[start + i] != '\0' && (start + i <= end))
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	countword_pos(const char *str, char *sep, int target, int option)
{
	int	count;
	int	i;
	int	sepflag;

	i = 0;
	count = 0;
	sepflag = 1;
	while (str[i] != '\0')
	{
		if (sepflag == 1 && is_separator(sep, str[i]) == 0)
			count = count + 1;
		if (count == target && is_separator(sep, str[i]) == 0 && option == 1)
			return (i);
		if (count == target && (is_separator(sep, str[i + 1]) == 1
				|| str[i + 1] == '\0') && option == 2)
			return (i);
		sepflag = is_separator(sep, str[i]);
		i++;
	}
	return (count);
}

static void	ft_free_splits(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		if (strs[i])
			free(strs[i]);
		i++;
	}
	if (strs)
		free(strs);
	return ;
}

// void	free_splits(char **dest, int i)
// {
// 	if (!dest)
// 		return ;
// 	i--;
// 	while (i >= 0)
// 	{
// 		if (dest[i])
// 			free(dest[i]);
// 		i--;
// 	}
// 	free(dest);
// 	return ;
// }

char	**ft_split(const char *sep, char *strs)
{
	int		count_word;
	char	**dest1;
	int		i;

	if (!sep || !strs)
		return (NULL);
	count_word = countword_pos(sep, strs, 0, 0);
	i = 0;
	dest1 = (char **)malloc((count_word + 1) * sizeof(char *));
	if (!dest1)
		return (NULL);
	while (i < count_word)
	{
		dest1[i] = ft_strdup_startend(sep, countword_pos(sep, strs, i + 1, 1),
				countword_pos(sep, strs, i + 1, 2));
		if (!dest1[i])
		{
			return (ft_free_splits(dest1), NULL);
		}
		i++;
	}
	dest1[i] = NULL;
	return (dest1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	sep;
// 	char	strs[] = ";-/abc..def|.ghi//.jklm0-.file3. ~_make.";
// 	char	*copy;
// 	int		target;
// 	char	**split;

// 	target = 6;
// 	sep = '.';
// 	// sep = " ;|-/~_";
// 	// optiion 0 : countword , 1: target start index, 2: target end index
// 	printf("countword: %i\n", countword_pos(strs, sep, target, 0));
// 	printf("wordstart: %i\n", countword_pos(strs, sep, target, 1));
// 	printf("wordend: %i\n", countword_pos(strs, sep, target, 2));
// 	copy = ft_strdup_startend(strs, countword_pos(strs, sep, target, 1),
// 			countword_pos(strs, sep, target, 2));
// 	printf("get target copy: %s\n", copy);

// 	split = ft_split(strs, sep);

// 	printf("\n =======split result =========\n");
// 	int  i =0;
// 	while (i < countword_pos(strs, sep, target, 0))
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// 	// printf("%s\n", split[0]);
// 	// printf("%s\n", split[4]);
// 	// printf("%s\n", split[5]);
// 	return (0);
// }