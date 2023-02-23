/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:42:15 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/10/28 19:35:50 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	x;

	x = 31;
	printf("\nOriginal function: %d\n\n", isprint(x));
	printf("My Function      : %d\n\n", ft_isprint(x));
}
*/