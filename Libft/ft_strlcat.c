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

static size_t	str_len(char const *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = str_len(dst);
	if (dstsize > i)
	{
		while ((j + i + 1) < dstsize && src[j] != '\0')
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
		return (i + str_len(src));
	}
	return (dstsize + str_len(src));
}
/*
int main()
{
	char dst[20] = "Hello";
	char src[] = " World!";

	printf("%lu", ft_strlcat(dst, src, sizeof(dst)));
	return(0);
}*/
