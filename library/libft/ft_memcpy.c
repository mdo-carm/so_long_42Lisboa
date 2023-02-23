/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:56:38 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/12/22 15:20:36 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*x;
	unsigned char	*y;

	if (!dst && !src)
		return (NULL);
	if (n == 0)
		return (dst);
	x = (unsigned char *)dst;
	y = (unsigned char *)src;
	i = 0;
	while (i < (int)n)
	{
		x[i] = y[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	string_1[] = "Badjoras";
	char	source_1[] = "Lol";
	char	string_2[] = "Badjoras";
	char	source_2[] = "Lol";
	size_t	size;

	size = 3;
	memcpy(string_1, source_1, size);
	printf("Real function: %s\n\n", string_1);
	ft_memcpy(string_2, source_2, size);
	printf("My function: %s\n", string_2);
}
*/