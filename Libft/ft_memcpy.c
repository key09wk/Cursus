/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:14:14 by kpalacio          #+#    #+#             */
/*   Updated: 2024/02/12 21:14:18 by kpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ptr;

	ptr = dst;
	if (!dst && !src)
		return (dst);
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (ptr);
}
/*
int	main()
{
	char destino[2];
	char source[] = "Prueba";
		
	printf("%s\n", ft_memcpy(destino, source, sizeof(destino)));
	return (0);
}*/
