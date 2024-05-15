/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:15:45 by kpalacio          #+#    #+#             */
/*   Updated: 2024/02/12 21:15:47 by kpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	if (dstsize > i)
	{
		while ((j + i + 1) < dstsize && src[j] != '\0')
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
		return (i + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
/*
int main()
{
	char dst[20] = "Hello";
	char src[] = " World!";

	printf("%lu", ft_strlcat(dst, src, sizeof(dst)));
	return(0);
}*/
