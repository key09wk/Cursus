/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpalacio <kpalacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:05:29 by kpalacio          #+#    #+#             */
/*   Updated: 2024/03/04 14:58:31 by kpalacio         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*start;
	int		lens1;
	int		lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = str_len(s1);
	lens2 = str_len(s2);
	newstr = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!newstr)
		return (NULL);
	start = newstr;
	while (*s1)
		*newstr++ = *s1++;
	while (*s2)
		*newstr++ = *s2++;
	*newstr = '\0';
	return (start);
}
