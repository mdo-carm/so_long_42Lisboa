/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:00:30 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/12/23 02:32:54 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numberlength(int n)
{
	if (n < 0 && n > -10)
		return (2);
	if (!n)
		return (0);
	return (1 + ft_numberlength(n /= 10));
}

char	*ft_itoa(int n)
{
	char			*s;
	int				i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_numberlength(n);
	s = (char *)ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = 45;
		n = -n;
	}
	while (n > 0)
	{
		s[i-- - 1] = ((n % 10) + 48);
		n /= 10;
	}
	return (s);
}
/*
int	main(void)
{
	int	n;

	n = 156;
	printf("\nOriginal number (int):%d:\n", n);
	printf("\nMy function (string) :%s:\n", ft_itoa(n));
}
*/