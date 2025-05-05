/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:14:24 by ktakeuch          #+#    #+#             */
/*   Updated: 2025/03/02 22:12:28 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_2darray(char **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i] != NULL)
	{
		free(array[i]);
	}
	free(array);
}

void	free_3darray(char ***array)
{
	int	i;
	int	j;

	if (!array)
		return ;
	i = -1;
	while (array[++i] != NULL)
	{
		j = -1;
		while (array[i][++j] != NULL)
			free(array[i][j]);
		free(array[i]);
	}
	free(array);
}

void	free_4darray(char ****array)
{
	int	i;
	int	j;
	int	k;

	if (!array)
		return ;
	i = -1;
	while (array[++i] != NULL)
	{
		j = -1;
		while (array[i][++j] != NULL)
		{
			k = -1;
			while (array[i][j][++k] != NULL)
				free(array[i][j][k]);
			free(array[i][j]);
		}
		free(array[i]);
	}
	free(array);
}
