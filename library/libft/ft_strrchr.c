/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:19:12 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/26 22:35:38 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	x;
	int		i;

	x = c;
	i = ft_strlen((char *)s);
	while (s[i] != x && i > 0)
		i--;
	if (s[i] == x)
		return (&((char *)s)[i]);
	return (NULL);
}
/*
int	main(void)
{
	int		c;
	char * empty = (char*)calloc(1, 1);
	c = 'V';
	printf("\nOriginal Function: %s\n", strrchr(empty, c));
	printf("My Function______: %s\n", ft_strrchr(empty, c));
}
*/