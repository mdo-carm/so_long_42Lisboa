/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:26:24 by mdo-carm          #+#    #+#             */
/*   Updated: 2021/12/18 00:40:39 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first_i;
	int		last_i;

	first_i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[first_i] && ft_strchr(set, s1[first_i]))
		first_i++;
	last_i = ft_strlen(s1);
	while (last_i > 0 && ft_strchr(set, s1[last_i]))
		last_i--;
	return (ft_substr(s1, first_i, last_i - first_i + 1));
}
/*
int	main(void)
{
	char	s1[] = "abbacdebaab";
	char	set[] = "ab";

	printf("\n%s\n", ft_strtrim(s1, set));
}
*/