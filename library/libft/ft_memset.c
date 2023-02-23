/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:51:24 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/12/03 17:40:47 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	x;
	unsigned char	*p;

	p = (unsigned char *)b;
	x = (unsigned char)c;
	i = 0;
	while (i < (int)len)
	{
		p[i] = x;
		i++;
	}
	return (b);
}
/*
int	main(void)
{
	char	s1[] = "Badjoras";
	char	s2[] = "Badjoras";
	int		i;
	size_t	size;

	size = 3;
	i = 72;
	printf("Real function: %s\n\n", memset(s1, i, size));
	printf("My function: %s\n", ft_memset(s2, i, size));
}
*/