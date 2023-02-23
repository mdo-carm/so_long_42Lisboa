/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:31:12 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/12/22 18:54:52 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*x;
	size_t	i;

	x = (char *)s;
	i = 0;
	while (i < n)
	{
		x[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	s1[] = "Badjoras";
	char	s2[] = "Badjoras";
	size_t	size;

	size = 1;
	bzero(s1, size);
	printf("Real function: %s\n\n", s1);
	ft_bzero(s2, size);
	printf("My function: %s\n", s2);
}
*/