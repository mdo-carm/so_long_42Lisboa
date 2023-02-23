/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:22:59 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/12/22 15:56:02 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;
	int	x;

	i = 0;
	if (n == 0)
		return (0);
	if (n < 0)
		return (-1);
	while (s1[i] == s2[i] && i < n - 1 && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	x = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (x);
}
/*
int	main(void)
{
	printf("Real function: %d\n\n", strncmp("1234", "1235", -100));
	printf("My function: %d\n", ft_strncmp("1234", "1235", 0));
}
*/