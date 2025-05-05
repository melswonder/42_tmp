/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohki_T <kohki_T@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:52:25 by ktakeuch          #+#    #+#             */
/*   Updated: 2024/11/12 02:56:21 by kohki_T          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <stdlib.h>

static int	get_newlen(int n)
{
	long	nb;
	int		len;

	nb = (long)n;
	len = 1;
	if (nb == 0)
		return (1 + 1);
	if (nb < 0)
	{
		len = 2;
		nb = -nb;
	}
	while (nb > 0)
	{
		len += 1;
		nb = nb / 10;
	}
	return (len);
}

static void	check_negative(long *nb, char **ans)
{
	if (*nb < 0)
	{
		*nb = -(*nb);
		*ans[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		len;
	long	nb;

	nb = (long)n;
	len = get_newlen(n);
	ans = (char *)malloc(len);
	if (!ans)
		return (NULL);
	if (nb == 0)
		ans[0] = '0';
	check_negative(&nb, &ans);
	ans[len - 1] = '\0';
	while (nb > 0)
	{
		ans[len - 2] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (ans);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%i\n", get_newlen(1234));
// 	printf("%i\n", get_newlen(-123450));
// 	printf("%i\n", get_newlen(-1230));
// 	//
// 	printf("============\n");
// 	printf("%s\n", ft_itoa(1230));
// 	printf("%s\n", ft_itoa(12345));
// 	printf("%s\n", ft_itoa(1230));
// 	printf("%s\n", ft_itoa(-1230));
// 	printf("%s\n", ft_itoa(-12345));
// 	printf("%s\n", ft_itoa(-1230));
// 	return (1);
// }
