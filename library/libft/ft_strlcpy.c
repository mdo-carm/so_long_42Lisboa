/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:23:18 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/12/17 22:56:15 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < size)
	{
		if (size == 0)
			return (ft_strlen(src));
		if (i < size - 1 && size > 0)
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
	}
	if (src[i] == '\0')
		dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	unsigned int	size;
	char src[] = "coucou";
	char dest[10];
	char dest2[10];

	memset(dest, 'A', 10);
	memset(dest2, 'A', 10);
	size = 1;
	printf("\n%lu=====%lu\n", strlcpy(dest, src, size), strlen(src));
	printf("\nString1: %s\n", dest);
	
	printf("\n%u=====%lu\n", ft_strlcpy(dest2, src, size), strlen(src));
	printf("\nString2: %s\n\n", dest2);
}
*/