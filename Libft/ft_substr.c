/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skey09 <skey09@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:31:12 by kpalacio          #+#    #+#             */
/*   Updated: 2024/02/29 14:06:00 by skey09           ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*str_ptr;

	if (!s)
		return (NULL);
	if (start > str_len(s))
		len = 0;
	else if (len > (str_len(s) - start))
		len = str_len(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	s += start;
	str_ptr = str;
	*(str + len) = '\0';
	while (len-- && *s)
		*str++ = *s++;
	return (str_ptr);
}
