/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:14:24 by ktakeuch          #+#    #+#             */
/*   Updated: 2024/11/12 00:02:26 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdlib.h>
// #include <stdio.h>

int	ft_atoi(const char *nptr)
{
	long	i;
	long	ans;
	long	sign;

	i = 0;
	ans = 0;
	sign = 1;
	if (!nptr)
		return (0);
	while (nptr[i] == ' ' || ('\t' <= nptr[i] && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		ans = ans * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(sign * ans));
}

// int main(void)
// {
// 	printf("%i\n", ft_atoi("23"));
// 	printf("%i\n", ft_atoi("--23"));
// 	printf("%i\n", ft_atoi("  23"));
// 	printf("%i\n", ft_atoi("+---23"));
// 	printf("%i\n", ft_atoi("   -23"));
// 	printf("%i\n", ft_atoi("   -2 3"));
// 	printf("%i\n", ft_atoi("  \n\t\v\f\r -23"));
// 	printf("%i\n", ft_atoi("   -2\r3"));
// }
