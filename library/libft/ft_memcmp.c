/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:14:41 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/10/28 19:35:46 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*x;
	unsigned char	*y;
	unsigned int	i;

	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (x[i] != y[i])
			return (x[i] - y[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char 	x[] = "Badjoras";
	char 	y[] = "Badoras";
	size_t 	n = 4;

	printf("\n\nOriginal function: %d\n", memcmp(x, y, n));
	printf("My function      : %d\n", ft_memcmp(x, y, n));
}
*/