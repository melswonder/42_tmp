/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakeuch <ktakeuch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:48:56 by oshuhei           #+#    #+#             */
/*   Updated: 2025/02/22 14:44:53 by ktakeuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_basenum(unsigned long long num, int base, char *str,
		int len)
{
	while (num != 0)
	{
		if (num % base < 10)
			str[len - 1] = (num % base) + '0';
		else
			str[len - 1] = (num % base) - 10 + 'A';
		num /= base;
		len--;
	}
	return (str);
}

char	*ft_convert_base(unsigned long long p, int base)
{
	char				*str;
	unsigned long long	num;
	int					digits;

	digits = 0;
	num = p;
	if (p == 0)
		return (ft_strdup("0"));
	while (p != 0)
	{
		p /= base;
		digits++;
	}
	str = ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = create_basenum(num, base, str, digits);
	return (str);
}
