/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:28:36 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/10/28 21:01:12 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*x;
	int		i;

	x = (char *) malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!x)
		return (0);
	i = 0;
	while (s[i])
	{
		x[i] = s[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
/*
int	main(void)
{
	char s[] = "Hello World!";
	char *x = ft_strdup(s);

	printf("%s", x);
}
*/