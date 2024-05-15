/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:14:41 by kpalacio          #+#    #+#             */
/*   Updated: 2024/02/12 21:14:45 by kpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src || dst == (char *)src + len)
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			((char *)dst)[i - 1] = ((char *)src)[i - 1];
			i--;
		}
	}
	return (dst);
}
/*
int main()
{
	char src[4];
	src[0] = 'H';
	src[1] = 'o';
	src[2] = 'l';
	src[3] = 'a';
	char dst[8];

	printf("%s\n", ft_memmove(dst, src, sizeof(src)));
	return (0);
}*/
