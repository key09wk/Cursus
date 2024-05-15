/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:35:34 by kpalacio          #+#    #+#             */
/*   Updated: 2024/02/13 11:27:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const	char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)last);
}
/*
int main()
{
    char s[] = "ELELELEL /buenas";
    int c = '\0';
  
	printf("%s\n", ft_strrchr(s, 't' + 256));
	printf("%s\n", strrchr(s, 't' + 256));
    return (0);
}*/
