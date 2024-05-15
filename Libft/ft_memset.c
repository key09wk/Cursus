/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:15:10 by kpalacio          #+#    #+#             */
/*   Updated: 2024/02/12 21:15:13 by kpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = b;
	i = 0;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}
/*
int main()
{
	char string[10];
	
	unsigned char c;
   	
	c = '*';
	
	printf("%s\n", ft_memset(string, c, sizeof(string)));

	return (0);
}*/
