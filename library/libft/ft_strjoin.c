/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:26:59 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/12/22 16:06:22 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	int		i;
	int		ind;

	if (!s1)
		return (NULL);
	x = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!x)
		return (NULL);
	i = 0;
	ind = 0;
	while (s1[i])
	{
		x[i] = s1[i];
		i++;
	}
	while (s2[ind])
	{
		x[i] = s2[ind];
		i++;
		ind++;
	}
	x[i] = '\0';
	return (x);
}
/*
int main(void)
{
	char	s1[] = "Hello";
	char	s2[] = " World!";

	printf("\ns1 = %s \ns2 = %s\n\n", s1, s2);
	printf("My function = %s\n", ft_strjoin(s1, s2));
}
*/