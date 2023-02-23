/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:36:15 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/12/22 18:42:54 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*x;
	char	*y;
	int		i;

	if (!dst && !src)
		return (NULL);
	x = (char *)dst;
	y = (char *)src;
	i = len - 1;
	if (y < x)
	{
		while (i >= 0)
		{
			x[i] = y[i];
			i--;
		}
		return (dst);
	}
	while (len--)
		*x++ = *y++;
	return (dst);
}
/*
int	main(void)
{
	char		dest1[] = "oldstring";
	const char	src1[] = "newstring";
	char		dest2[] = "oldstring";
	const char	src2[] = "newstring";
	size_t		len;

	len = 2;
	printf("\nBefore memmove dest = %s\n", dest1);
	memmove(dest1, src1, len);
	printf("After memmove dest = %s\n\n", dest1);
	printf("Before ft_memmove dest = %s\n", dest2);
	ft_memmove(dest2, src2, len);
	printf("After ft_memmove dest = %s\n\n", dest2);
}
*/