/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:19:12 by mdo-carm          #+#    #+#             */
/*   Updated: 2023/04/26 22:35:32 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (s[i] == (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "BanZana Zebra Zebra";
	int		c;

	c = ' ';
	printf("\nOriginal Function: %s\n", strchr(s, c));
	printf("My Function______: %s\n", ft_strchr(s, c));
}
*/