/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:24:46 by ktakeuch          #+#    #+#             */
/*   Updated: 2024/11/12 02:03:15 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*uc1;
	unsigned char	*uc2;
	int				i;

	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	i = 0;
	while (uc1[i] != '\0' && uc2[i] != '\0')
	{
		if (uc1[i] != uc2[i])
			return ((int)(uc1[i] - uc2[i]));
		i++;
	}
	return ((int)(uc1[i] - uc2[i]));
}
