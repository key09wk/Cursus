/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:11:31 by kpalacio          #+#    #+#             */
/*   Updated: 2024/02/12 21:11:40 by kpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*
int main()
{
	char cadena[5] = "hola!";
	
	ft_bzero(cadena, sizeof (cadena));
	printf("%s\n", cadena);
	return (0);
}*/
